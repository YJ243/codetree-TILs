#include <iostream>
#include <vector>

#define MAX_M 10
#define MAX_N 4

using namespace std;

int n = MAX_N;
int m, t;                           // m: 몬스터 마리 수, t: 진행되는 턴 수
vector<int> grid[MAX_N][MAX_N];     // grid[i][j]: (i,j)에 있는 몬스터의 방향(방향 정보만 저장)
vector<int> egg[MAX_N][MAX_N];      // egg[i][j]: (i,j)에서 부화되는 알의 방향
vector<int> dead[MAX_N][MAX_N];     // dead[i][j]: (i,j)에 있는 시체의 소멸되는 턴을 저장
pair<int, int> pacman;              // 팩맨 위치

int dirs[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}}; //   ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int pdirs[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};   // 팩맨 움직이는 방향, 상좌하우
vector<int> selected;
int movingDir[3];
int max_caught;
void Input(){   // 입력을 받는 함수 
    cin >> m >> t;      // m: 몬스터 마리 수, t: 진행되는 턴 수
    int r, c;
    cin >> r >> c;
    pacman = make_pair(r-1, c-1);   // 팩맨 위치 입력받기
    for(int i=0; i<m; i++){
        int r, c, d;
        cin >> r >> c >> d;
        grid[r-1][c-1].push_back(d-1);      // 몬스터 위치와 방향 입력받기
    }
}

void TryCopyMonster(int x, int y){ // (x, y)에 있는 몬스터를 복제하는 함수
    for(int i=0; i<(int)grid[x][y].size(); i++){
        int d = grid[x][y][i];
        egg[x][y].push_back(d);     // 알에다가 d 방향 넣기
    }
}

bool InRange(int x, int y){     // (x, y)가 범위 안에 있는지 확인하는 함수
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){   // 몬스터가 (x, y)로 이동할 수 있는지 확인하는 함수
    // 범위 안에 있고, 팩맨이 없으며, 시체가 없는 경우에 움직일 수 있다.
    return InRange(x, y) && make_pair(x, y) != pacman && (int)dead[x][y].size() == 0; 
}

void MoveMonster(){     // 몬스터를 이동하는 함수
    vector<int> tmp[n][n];  // 다음 몬스터 위치를 저장할 배열
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            tmp[i][j].clear();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j].size() >= 1){ // 만약 해당 칸에 몬스터가 있다면
                for(int k=0; k<(int)grid[i][j].size(); k++){
                    int cur_d = grid[i][j][k];  // 몬스터의 현재 방향
                    bool movable = false; // 움직일 수 있는지 여부
                    int ni, nj;
                    for(int l=0; l<=8; l++){
                        ni = i + dirs[(cur_d+l)%8][0], nj = j + dirs[(cur_d+l)%8][1];
                        if(CanGo(ni, nj)){
                            movable = true;
                            cur_d = (cur_d+l) % 8;
                            break;
                        }
                    }
                    if(movable){    // 만약 k번째 몬스터를 움직일 수 있다면
                        tmp[ni][nj].push_back(cur_d);
                    }
                    else{   // 움직일 수 없다면 해당 자리에 그대로 놓기
                        tmp[i][j].push_back(cur_d);
                    }
                }
            }
        }
    }
    // tmp에서 grid로 옮겨주기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = tmp[i][j];
        }
    }
}

bool IsValidRoute(){    // selected에 있는 방향대로 팩맨이 움직일 수 있는지 확인하는 함수
    int x = pacman.first, y = pacman.second;
    for(int i=0; i<3; i++){
        x += pdirs[selected[i]][0]; y += pdirs[selected[i]][1];
        if(!InRange(x, y))
            return false;
    }
    return true;
}

int GetMonsterCnt(){    
    int monsterCnt = 0;
    bool visited[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }

    int x = pacman.first, y = pacman.second;
    for(int i=0; i<3; i++){
        x += pdirs[selected[i]][0]; y += pdirs[selected[i]][1];
        if(!visited[x][y])
            monsterCnt += (int)grid[x][y].size();        
        visited[x][y] = true;
    }
    return monsterCnt;
}

void ChooseDirs(int idx){
    if(idx == 3){
        if(IsValidRoute()){
            int curCnt = GetMonsterCnt();
            if(max_caught < curCnt){
                max_caught = curCnt;
                for(int i=0; i<3; i++)
                    movingDir[i] = selected[i];    // 움직이는 방향 저장하기
            }
        }
        return;
    }
    for(int i=0; i<4; i++){
        selected.push_back(i);
        ChooseDirs(idx+1);
        selected.pop_back();
    }
}

void EatMonster(int turn){
    int x = pacman.first, y = pacman.second;
    for(int i=0; i<3; i++){
        int d = movingDir[i];
        x += pdirs[d][0]; y += pdirs[d][1];
        for(int k=0; k < (int)grid[x][y].size(); k++){
            dead[x][y].push_back(turn+2); // 시체가 사라지는 턴수 집어넣기
        }
        grid[x][y].clear();
    }
    pacman = make_pair(x, y);
}

void MovePacman(int turn){      // 팩맨을 움직이는 함수
    // 팩맨이 움직이는 방향 구하기
    max_caught = -1;
    ChooseDirs(0);  // 0번째 움직일 방향을 선택하러 가기
    // 이제 movingDir에 있는 방향대로 움직이면서 몬스터를 먹어 치우기 시체 남기기
    EatMonster(turn);
}

void DeleteDeadMonster(int turn){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dead[i][j].size() >= 1){
                vector<int> tmp;
                for(int k=0; k<(int)dead[i][j].size(); k++){
                    // 만약 소멸되는 턴수가 현재 turn보다 작을 때만 남기기
                    if(dead[i][j][k] > turn)
                        tmp.push_back(dead[i][j][k]);
                }
                dead[i][j] = tmp;
            }
        }
    }
}

void CopyMonster(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(egg[i][j].size() > 0){
                for(int k=0; k<(int)egg[i][j].size(); k++){
                    grid[i][j].push_back(egg[i][j][k]);
                }
                egg[i][j].clear();
            }

        }
    }
}
void Simulate(int turn){
    // Step 1. 몬스터 복제 시도
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            egg[i][j] = grid[i][j];
        }
    }

    // Step 2. 몬스터 이동
    MoveMonster();


    // Step 3. 팩맨 이동
    MovePacman(turn);

    // Step 4. 시체 소멸
    DeleteDeadMonster(turn);
    // Step 5. 몬스터 복제 완성
    CopyMonster();

    
}

void Output(){  // 살아남은 몬스터를 출력하는 함수
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += (int)grid[i][j].size();
        }
    }
    cout << ans << '\n';
}

int main() {
    // 입력 받기:
    Input();

    // t개의 턴에 대해 시뮬레이션 진행
    for(int i=1; i<=t; i++){
        Simulate(i);
    }

    // 출력하기:
    Output();
    return 0;
}