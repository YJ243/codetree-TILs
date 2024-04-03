#include <iostream>
#include <cstdlib>
#define MAX_N 10

using namespace std;

int N, M, K;
int grid[MAX_N][MAX_N];
/*
 grid는 격자
 0: 빈칸, -1 ~ -9: 벽의 내구도, -10: 출구, 양수: 참가자 수
*/
int temp_grid[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int total_moved;

void Input(){
    cin >> N >> M >> K;     // N: 미로 크기, M: 참가자 수, K: 게임 시간
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            grid[i][j] = -grid[i][j];
        }
    }
    for(int i=0; i<M; i++){
        int r, c;
        cin >> r >> c;
        grid[r-1][c-1]++;
    }
    int r, c;
    cin >> r >> c;
    grid[r-1][c-1] = -10;       // 출구 표시

}

bool IsFinish(){        // 모든 참가자가 미로를 탈출했는지 확인하는 함수
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] > 0){
                return false;
            }
        }
    }
    return true;
}

void Initialize_before_search(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp_grid[i][j] = 0;
        }
    }
}

pair<int, int> FindExit(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == -10){
                return make_pair(i,j);
            }
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool CanGo(int x, int y, int dist){
    pair<int, int> exit_loc = FindExit();
    int curDist = abs(exit_loc.first - x) + abs(exit_loc.second - y);
    return InRange(x, y) && (grid[x][y] >= 0 || grid[x][y] == -10) && dist > curDist;
}

void MoveAll(){
    // 1. 탐색 전 초기화
    Initialize_before_search();
    pair<int, int> exit_loc = FindExit();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] > 0){     // 참가자가 있는 칸을 만났다면
                int dist = abs(exit_loc.first - i) + abs(exit_loc.second - j);
                int curX = i, curY = j;
                for(int d=0; d<4; d++){
                    int nx = i + dirs[d][0], ny = j + dirs[d][1];
                    if(CanGo(nx,ny, dist)){
                        curX = nx, curY = ny;
                        total_moved += grid[i][j];      // 움직인 거리 증가하기
                        break;
                    }
                }
                if(curX == i && curY == j){
                    temp_grid[i][j] += grid[i][j];
                }
                else{
                    if(grid[curX][curY] == -10)
                        continue;
                    temp_grid[curX][curY] += grid[i][j];
                }
            }
            else if(grid[i][j] < 0)
                temp_grid[i][j] = grid[i][j];

        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            grid[i][j] = temp_grid[i][j];
        }
    }
}

bool CanMakeSquare(int len, int x, int y){
    bool IsPerson = false, IsExit = false;
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(grid[i][j] > 0)
                IsPerson = true;
            if(grid[i][j] == -10)
                IsExit = true;
        }
    }
    return IsPerson && IsExit;
}

void RotateSquare(int x, int y, int len){
    // 1. 일단 grid의 정사각형 부분을 tmp로 옮기기
    int tmp[len][len];
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            tmp[i][j] = grid[i+x][j+y];
        }
    }
    // 2. tmp를 90도 회전하기
    int rotate_tmp[len][len];
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            rotate_tmp[j][len-1-i] = tmp[i][j];
            if(-9 <= rotate_tmp[j][len-1-i] && rotate_tmp[j][len-1-i] <= -1)
                rotate_tmp[j][len-1-i]++;
        }
    }
    // 3. rotate_tmp를 grid로 넣기
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            grid[i+x][j+y] = rotate_tmp[i][j];
        }
    }
}

void Simulate(int turn){
    // Step 1. 모든 참가자 한 칸 이동
    MoveAll();
    // Step 2. 가장 작은 정사각형 잡기
    int firstX, firstY, minLen;
    bool FindSquare = false;
    for(int k=1; k<=N; k++){    // 정사각형 한 변의 길이는 1부터 N까지
        for(int i=0; i<=N-k; i++){
            for(int j=0; j<=N-k; j++){
                if(CanMakeSquare(k, i, j)){
                    firstX = i, firstY = j, minLen = k;
                    FindSquare = true;
                    break;
                }
            }
            if(FindSquare) break;
        }
        if(FindSquare) break;
    }

    // Step 3. 회전하기
    RotateSquare(firstX, firstY, minLen);
}

int main() {
    // 입력 받기:
    Input();
    // K초 동안 이동하기
    for(int i=1; i<=K; i++){
        if(IsFinish())
            break;
        Simulate(i);
    }
    cout << total_moved << '\n';
    pair<int, int> exit_loc = FindExit();
    cout << exit_loc.first+1 << ' ' << exit_loc.second+1 << '\n';
    return 0;
}