#include <iostream>
#include <queue>
#include <tuple>
#define MAX_L 55
#define MAX_N 40

using namespace std;

int L, N, Q;                                                // L: 체스판 크기, N: 기사들 수, Q: 명령 수
int grid[MAX_L][MAX_L];                                     // 0: 빈칸, 1: 함정, 2: 벽
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};       // 상, 우, 하, 좌
tuple<int, int, int, int, int, int> knights[MAX_N+1];       // 기사들 정보(r, c, h, w, k, damage)
                                    // 탐색을 위한 큐
    bool IsMoving[MAX_N+1];  
        queue<int> q; 
void Input(){                       // 입력을 받는 함수
    cin >> L >> N >> Q;             // L: 체스판 크기, N: 기사들 수, Q: 명령 수
    for(int i=0; i<L; i++){         // 체스판 입력받기
        for(int j=0; j<L; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=N; i++){            // N명의 기사들 입력받기
        int r, c, h, w, k;              // 기사들 정보(r, c, h, w, k, damage)
        cin >> r >> c >> h >> w >> k;
        r--; c--;                       // (0,0)부터 시작하도록 함
        knights[i] = make_tuple(r, c, h, w, k, 0);
    }
}

bool InRange(int x, int y){         // 범위 안에 있는지 확인하는 함수
    return 0 <= x && x < L && 0 <= y && y < L;
}

void Move(int id, int d){
    while(!q.empty())
        q.pop();
    // 1. 먼저 tmp_grid에 기사들 표시하기 & IsMoving 초기화
                                   // 현재 턴에 움직이고 있는지 확인

    for(int i=1; i<=N; i++)
        IsMoving[i] = false;
    
    int tmp_grid[MAX_L][MAX_L] = {0,};
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            tmp_grid[i][j] = 0;
        }
    }
    for(int i=1; i<=N; i++){
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[i];
        if(k <= 0) continue;              // 살아있는 기사들에 한해서 격자에다가 옮기기
        for(int x=r; x<r+h; x++){           // 기사들 구성하는 칸에 대해서
            for(int y=c; y<c+w; y++){
                tmp_grid[x][y] = i;         // 번호 적기
            }
        }
        
        IsMoving[i] = false;                    // 현재 움직이는지 여부 초기화하기
    }
    /*
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cout << tmp_grid[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    // 2. id와 연결되어 있는 기사 찾기
  
    q.push(id);                                 // 현재 명령을 받은 id번 기사 큐에 넣기
    IsMoving[id] = true;                        // 움직이고 있다고 표시하기
    while(!q.empty()){                      // 큐가 빌 때까지 진행
        int curr = q.front();               // 제일 앞에 있는 기사 번호 가져오기
        q.pop();
        
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[curr];

        for(int x=r; x<r+h; x++){
            for(int y=c; y<c+w; y++){
                int a = x, b = y;       // (a,b)는 curr 기사의 한 부분
                for(;;){
                    a += dirs[d][0]; b += dirs[d][1];
                    if(!InRange(a, b))  // 만약 범위를 벗어나면 움직일 수 없으니 바로 리턴
                        return;         
                    if(tmp_grid[a][b] == 0){    // 빈칸 만남
                        if(grid[a][b] == 2){    // 그런데 벽을 만났다면
                            return;             // 움직이지 못하니 리턴
                        }
                        // 벽이 아닌 빈칸을 만났으면 이제 탐색 중단해도 됨
                        break;
                    }   
                    if(!IsMoving[tmp_grid[a][b]]){          // 만약 새로운 기사를 만났다면
                        IsMoving[tmp_grid[a][b]] = true;    // 움직여야 한다고 표시하기
                        q.push(tmp_grid[a][b]);             // 큐에 번호 넣기
                    }
                }
            }
        }
    }
    // << id << "번 기사 명령 받음" << '\n';
    for(int i=1; i<=N; i++){        // N명의 기사에 대해
        //cout << i << "번 움직임: " << IsMoving[i] << '\n';
        if(!IsMoving[i]) continue;  // 움직이는 기사가 아니라면 넘어가기
       
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[i];
        r += dirs[d][0]; c += dirs[d][1];               // d방향으로 1만큼 이동시키기
        if(i != id){
            for(int x=r; x<r+h; x++){
                for(int y=c; y<c+w; y++){
                    if(grid[x][y] == 1){                // 만약 함정이라면
                        damage++;                       // 데미지 증가
                        k--;                            // 목숨 감소
                    }
                }
            }
        }
       // cout << i << ' ' << r << ' ' << c << ' ' << h << ' ' << w << ' ' << k << ' ' << damage << '\n';
        knights[i] = make_tuple(r, c, h, w, k, damage); // 다시 정보 저장하기
    }
}

void Pro(){
    // Q번의 왕의 명령 수행하기
    while(Q--){
        int id, d;
        cin >> id >> d;
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[id];
        if(k <= 0) continue;
        Move(id, d);    // 명령 수행하기
    }
}

void Output(){
    int ans = 0;
    for(int i=1; i<=N; i++){
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[i];
        if(k >= 1){
            ans += damage;
        }
    }
    cout << ans;
}

int main() {
    // 입력 받기:
    Input();
    // 명령 진행하기
    Pro();

    // 출력하기
    Output();
    return 0;
}