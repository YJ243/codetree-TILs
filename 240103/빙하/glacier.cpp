/*
 * 2023.1.3.
 * 빙하가 녹을 조건? 옆에 빙하에 둘러쌓여 있지 않은 물이 있을 경우
 * -> 그럼 이 물을 어떻게 구하지?, 일단 가장자리는 전부 물이니, (0,0)을 시작점으로 BFS를 돌리기
 * 빙하에 둘러쌓여 있지 않은 물을 찾은 후? 각 빙하에 대해 인접한 영역에 이전 BFS에 visited 표시가 된 적 있ㅡㄴ 부분이 존재하는지 판

*/

#include <iostream>
#include <queue>

#define MAX_N 200
#define MAX_M 200
#define MAX_DIR 4
using namespace std;
int n, m;
int grid[MAX_N][MAX_M];
queue<pair<int, int> > q;       
bool visited[MAX_N][MAX_M];
int curr_melted;
int dirs[MAX_DIR][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int time_sec;
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && !grid[x][y]; 
}

void bfs(){
    while(!q.empty()){
        // q가 빌 때까지
        pair<int, int> curr = q.front();
        q.pop();
        for(int i=0; i<MAX_DIR; i++){
            int nx = curr.first + dirs[i][0];
            int ny = curr.second + dirs[i][1];
            if(CanGo(nx,ny)){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }

    }
}

bool IsFinish(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]) return false;
        }
    }
    return true;
}

void Initialize(){
    // 1. 방문 배열 초기화
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j] = false;
    
    // 2. 현재 녹은 빙하 개수 초기화
    curr_melted = 0;
}

void Melt(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]){
                // 만약 빙하라면
                for(int d=0; d<MAX_DIR; d++){
                    int nx = i+dirs[d][0], ny = j+dirs[d][1];
                    if(InRange(nx,ny) && grid[nx][ny] == 0 && visited[nx][ny]){
                        grid[i][j] = 0;
                        curr_melted++;
                        break;
                    }
                }
            }
        }
    }
}

void Simulate(){
    time_sec++;
    // Step 0. 시뮬레이션을 돌리기 전에 먼저 초기화하기
    Initialize();
    // Step 1. 먼저 bfs 탐색을 돌면서 빙하로 둘러싸이지 않은 물을 파악하기
    visited[0][0] = true;
    q.push(make_pair(0,0));
    bfs();

    // Step 2. 모든 격자를 돌면서 녹일 수 있는 빙하는 녹이기
    Melt();

}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    
    while(true){
        // 모든 격자가 0이 된다면 break;
        if(IsFinish()) break;
        Simulate();
    }
    
    cout << time_sec << ' ' << curr_melted << '\n';
    return 0;
}