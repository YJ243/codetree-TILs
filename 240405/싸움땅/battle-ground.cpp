#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 20
#define MAX_M 30

using namespace std;

int n, m, k;                            // n: 격자 크기, m: 플레이어 수, k: 라운드 수
vector<int> gun_power[MAX_N][MAX_N];    // 격자에 존재하는 총의 공격력
// 총의 공격력, 한 칸에 여러 총이 존재할 수 있음
// 0: 빈칸, 양수: 총의 공격력

int grid[MAX_N][MAX_N];                 
// 플레이어 번호가 적힌 격자
// 0: 빈칸, 1이상의 양수: 번호
tuple<int, int, int, int, int> players[MAX_M+1];        // players[i]: i번 선수의 위치 (x,y), 방향 d, 초기능력 s, 총의 공격력 p
int points[MAX_M+1];                                    // 플레이어들의 점수
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};           // 상, 우, 하, 좌

void Input(){       // 입력을 받는 함수 
    cin >> n >> m >> k;                 // n: 격자 크기, m: 플레이어 수, k: 라운드 수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int p;
            cin >> p;
            gun_power[i][j].push_back(p);   // (i,j)열에 p 파워를 가진 총 넣기.
        }
    }
    for(int i=1; i<=m; i++){    // m명의 플레이어 정보 주어짐
        int x, y, d, s;         // (x,y) 플레이어 위치, d는 방향, s: 초기 능력
        cin >> x >> y >> d >> s;
        x--; y--;               // (0,0)에서 시작하도록 함
        grid[x][y] = i;         // 격자 칸에다가 플레이어 번호 적기
        players[i] = make_tuple(x, y, d, s, 0);
    }
}

bool InRange(int x, int y){         // (x,y)가 범위 안에 있는지 확인하는 함수
    return 0 <= x && x < n && 0 <= y && y < n;
}

void GetGun(int x, int y, int idx){  // idx번 플레이어가 (x, y)에서 총 줍기 
    int d, s, p;                     // 방향 d, 초기능력 s, 가지고 있는 총의 공격력 p
    tie(ignore, ignore, d, s, p) = players[idx];     // idx번 플레이어 정보
    
    int max_power_gun = 0, maxI = 0;                 // 현재 (x,y)에 존재하는 총들 중 가장 공격력이 센 총
    for(int i=0; i<(int)gun_power[x][y].size(); i++){
        if(max_power_gun < gun_power[x][y][i]){
            max_power_gun = gun_power[x][y][i];   // 해당 칸에 있는 총들의 가장 큰 공격력
            maxI = i;
        }
    }
    if(max_power_gun != 0){     // 만약 총이 놓여있다면
            // 현재 플레이어의 총의 공격력과 비교하기
            if(p == 0 || p < max_power_gun){ // 플레이어가 총을 가지고 있지 않거나, 가지고 있는 총의 공격력이 더 작다면
                if(p > 0)   // 총 내려놓기
                    gun_power[x][y].push_back(p);
                p = max_power_gun;  // 총 획득하기
                vector<int> tmp;
                for(int i=0; i<(int)gun_power[x][y].size(); i++){
                    if(i != maxI)
                        tmp.push_back(gun_power[x][y][i]);        // 획득한 총 빼고 저장하기
                }
                gun_power[x][y] = tmp;
            }
        }
    players[idx] = make_tuple(x, y, d, s, p);
    if((int)gun_power[x][y].size() == 0)    // 만약 비어있다면 0 표시 
        gun_power[x][y].push_back(0);
}

void MoveLosePlayer(int idx){       // 싸움에서 진 idx번 플레이어를 이동시키는 함수
    int x, y, d, s, p;                     // 위치 (x,y), 방향 d, 초기능력 s
    tie(x, y, d, s, p) = players[idx];     // idx번 플레이어 정보
    if(p > 0){      // 총이 있다면 총 내려놓기
        gun_power[x][y].push_back(p);       // 해당 칸에 총 넣고
        p = 0;      // 가지고 있는 총의 공격력 0으로
    }
    int nx, ny;     // 다음으로 이동할 위치

    for(int i=0; i<4; i++){
        nx = x + dirs[(d+i)%4][0], ny = y + dirs[(d+i)%4][1];   // idx번 플레이어가 이동할 다음 위치
        if(!InRange(nx, ny) || grid[nx][ny] > 0){   // 만약 격자 밖이거나 해당 칸에 다른 플레이어가 있다면
            continue;
        }
        d = (d+i)%4;
        break;  // 그게 아니라면 반복문 나가기
    }
    players[idx] = make_tuple(nx, ny, d, s, p);     // 이동한 위치 업데이트
    GetGun(nx, ny, idx);                            // 이동한 곳에서 총 줍기
}

tuple<int, int, int> GetNext(int x, int y, int d){
    int nx = x + dirs[d][0], ny = y + dirs[d][1];   // idx번 플레이어가 이동할 다음 위치
    // 격자를 벗어나면 방향을 뒤집어 반대 방향으로 한 칸 이동한다.
    if(!InRange(nx, ny)){                           // 만약 해당 방향으로 나갈 때 격자를 벗어난다면
        d = (d + 2) % 4;                            // 정 반대방향으로 바꾸기
        nx = x + dirs[d][0], ny = y + dirs[d][1];   // 다시 다음 위치 설정하기
    }
    return make_tuple(nx, ny, d);
}

void Move(int idx){ // idx번 플레이어 이동시키는 함수
    int x, y, d, s, p;                     // 위치 (x,y), 방향 d, 초기능력 s
    tie(x, y, d, s, p) = players[idx];     // idx번 플레이어 정보

    // Step 1-1. 현재 플레이어가 움직일 그 다음 위치와 방향을 구한다.
    int nx, ny;
    tie(nx, ny, d) = GetNext(x, y, d);

    if(grid[nx][ny] == 0){      // 만약 이동한 방향에 플레이어가 없다면
        players[idx] = make_tuple(nx, ny, d, s, p);     // idx번 플레이어의 위치, 방향, 초기능력, 총의 공격력 업데이트
        GetGun(nx, ny, idx);                            // 이동한 곳에서 총 줍기 
    }
    else{                       // 만약 플레이어가 존재한다면
        // 현재 (x,y) -> (nx, ny) 방향으로 가려는 원래 idx번 플레이어가 grid[nx][ny]번 사람과 만나게 됨
        int x2, y2, d2, s2, p2;
        tie(x2, y2, d2, s2, p2) = players[grid[nx][ny]];    // 이동할 격자 칸에 존재하는 플레이어
        bool win = false;       // 참: idx번 플레이어 승, 거짓: idx번 플레이어 짐
        
        if(make_tuple(s+p, s) > make_tuple(s2+p2, s2))  // 만약 idx번 플레이어가 이겼다면
            win = true;     // 이겼다고 표시
        // 이긴 플레이어는 각 플레이어의 초기 능력치와 가지고 있는 총의 공격력의 합의 차이만큼 포인트를 획득
        int winIdx, loseIdx;
        if(win){    // idx번 플레이어가 이겼다면
            points[idx] += (s+p) - (s2+p2);             // idx번 플레이어 점수 증가
            winIdx = idx, loseIdx = grid[nx][ny];   
        }
        else{       // 격자에 있던 플레이어가 이겼다면
            points[grid[nx][ny]] += (s2+p2) - (s+p);    // 해당 플레이어 점수 증가 
            winIdx = grid[nx][ny], loseIdx = idx;
        }
        grid[x][y] = 0;                                 // 누가 이겼든 원래 있던 자리는 0으로 만들어야 함
        players[idx] = make_tuple(nx, ny, d, s, p);     // idx번 위치, 방향, 초기능력, 총의 공격력 업데이트
    
        // 진 플레이어는 이동시키기
        MoveLosePlayer(loseIdx);

        // 이긴 플레이어 총 획득하기
        GetGun(nx, ny, winIdx);
    }
}

void Initialize(){      // 플레이어 격자를 업데이트하는 함수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = 0;
        }
    }
    for(int i=1; i<=m; i++){
        int x, y;
        tie(x, y, ignore, ignore, ignore) = players[i];
        grid[x][y] = i;
    }
}

void Simulate(){
    // grid 그리기
    for(int i=1; i<=m; i++){    // 첫 번째 플레이어부터 순차적으로 이동하기
        Initialize();           // 격자 업데이트
        Move(i);                // i번 플레이어 움직이기
    }
}

void Output(){      // 플레이어들의 점수를 출력하는 함수 
    for(int i=1; i<=m; i++){
        cout << points[i] << ' ';
    }
}

int main() {
    // 입력 받기:
    Input();  

    // k번의 라운드에 대해 시뮬레이션 진행하기
    while(k--){
        Simulate();
    }  
    
    // 출력하기:
    Output();
    return 0;
}