#include <iostream>
#include <algorithm>
#define MAX_N 20
#define MAX_DIR 4
using namespace std;

int n, m, k;    // n: 격자 크기, m: 벽의 개수, k: 시원함 정도
int grid[MAX_N][MAX_N];     // 격자 정보
// 0: 빈 공간, 1: 사무실, 2~5 에어컨 => 0:왼/1:위/2:오/3:아
bool walls[MAX_N][MAX_N][MAX_DIR];  // walls[x][y][d]: (x,y)에서 d방향으로 wall이 있는지

bool visited[MAX_N][MAX_N];
int cool[MAX_N][MAX_N];
int dirs[MAX_DIR][2] = {{0,-1},{-1,0},{0,1},{1,0}};   // 0:왼/1:위/2:오/3:아

void Input(){   // 입력을 받는 함수
    cin >> n >> m >> k; // n: 격자 크기, m: 벽 개수, k: 시원함 정도
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int x, y, s;
        cin >> x >> y >> s;     // s: 0 (x,y) 위에 벽, 1 (x,y) 왼쪽에 벽
        x--; y--;
        if(s == 0){
            walls[x][y][1] = true;          // (x, y)에서 위로 가는 방향에 벽이 있음
            if(0 <= x-1 && x-1 < n)
                walls[x-1][y][3] = true;    // (x, y)에서 아래로 가는 방향에 벽이 있음
        }
        else{
            walls[x][y][0] = true;      // (x, y)에서 왼쪽으로 가는 방향에 벽이 있음
            if(0 <= y-1 && y-1 < n)
                walls[x][y-1][2] = true;    // (x, y)에서 오른쪽으로 가는 방향에 벽이 있음
        }
    }
}

bool InRange(int x, int y){     // (x, y)가 범위 안에 있는지 확인하는 함수
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Blow(int x, int y, int d, int coolness){   // (x, y)에서 d방향으로 coolness 정도의 바람을 부는 함수
    if(coolness == 0)
        return;

    int nx = x + dirs[d][0], ny = y + dirs[d][1];
    
    // 1. 직진 방향
    // 범위 안에 있고, 벽이 없고, 아직 방문하지 않았다면
    if(InRange(nx, ny) && !walls[x][y][d] && !visited[nx][ny]){
        cool[nx][ny] += coolness;
        visited[nx][ny] = true;
        Blow(nx, ny, d, coolness-1);
    }
    if(coolness == 5) return;
    // 2. 대각선방향1, 좌우로 움직이는 경우
    if(dirs[d][0] == 0){
        int dxs[2] = {x-1, x+1};    // (1. 위 2. 좌우), (1. 아래 2. 좌우)
        // 1 방향으로 움직일 수 있다면
        for(int i=0; i<2; i++){
            int nex = dxs[i];
            int nd = 0;
            if(i == 0) nd = 1;
            else nd = 3;

            if(InRange(nex, y) && InRange(nex, ny) && !walls[x][y][nd] && !walls[nex][y][d] && !visited[nex][y] && !visited[nex][ny]){
                cool[nex][ny] += coolness;
                visited[nex][ny] = true;
                Blow(nex, ny, d, coolness-1);
            }
        }
    }
    // 3. 대각선방향2, 상하로 움직이는 경우
    else{
        int dys[2] = {y-1, y+1};    // (1. 왼 2. 상하), (1. 오 2. 상하)
        for(int i=0; i<2; i++){
            int ney = dys[i];
            int nd;
            if(i == 0) nd = 0;
            else nd = 2;
            if(InRange(x, ney) && InRange(nx, ney) && !walls[x][y][nd] && !walls[x][ney][d] && !visited[x][ney] && !visited[nx][ney]){
                cool[nx][ney] += coolness;
                visited[nx][ney] = true;
                Blow(nx, ney, d, coolness-1);

            }
        }
    }
}

void Initialize_visited(){      // 방문 배열을 초기화하는 함수 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
}

void MakeCool(){    // 에어컨이 사무실을 시원하게 만들도록 하는 함수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] >= 2){
                Initialize_visited();
                Blow(i, j, grid[i][j]-2, 5);    // (i, j)에서 grid[i][j]-1 방향으로 5만큼의 시원함 정도 전파하기
            }
        }
    }
}

void MixAir(){
    int temp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = cool[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int d=0; d<4; d++){
                int nI = i + dirs[d][0], nJ = j + dirs[d][1];
                if(InRange(nI, nJ) && cool[i][j] > cool[nI][nJ] && !walls[i][j][d]){
                    int val = (cool[i][j] - cool[nI][nJ]) / 4;
                    temp[i][j] -= val;
                    temp[nI][nJ] += val;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cool[i][j] = temp[i][j];
}

void DecreaseCool(){
    for(int i=0; i<n; i++){
        cool[i][0] = max(0, cool[i][0]-1);
        cool[i][n-1] = max(0, cool[i][n-1]-1);
    }
    for(int j=1; j <= n-2; j++){
        cool[0][j] = max(0, cool[0][j]-1);
        cool[n-1][j] = max(0, cool[n-1][j]-1);
    }
}

void Simulate(){
    // Step 1. 공기를 시원하게 하기
    MakeCool();

    // Step 2. 공기가 섞임
    MixAir();

    // Step 3. 외벽-1
    DecreaseCool();
}

bool IsFinish(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1 && cool[i][j] < k)
                return false;
        }
    }
    return true;
}

int main() {
    // 입력 받기
    Input();    

    int elapsed_time = 0;
    while(true){
        if(IsFinish() || elapsed_time > 100)
            break;
        elapsed_time++;
        Simulate();
        break;
    }

    if(elapsed_time >= 100)
        elapsed_time = -1;

    cout << elapsed_time << '\n';
    return 0;
}