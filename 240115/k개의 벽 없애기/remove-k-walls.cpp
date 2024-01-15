#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_N 100
using namespace std;

// 전역 변수 선언:
int n, k;                       // n: 격자 크기, k: 없애야 할 벽의 개수
int r1, c1, r2, c2;             // 시작점과 도착점
int grid[MAX_N][MAX_N];         // 1: 벽으로 이동 불가, 0: 이동 가능

vector<pair<int, int> > walls;  // 벽의 위치
vector<int> selected_walls;     // 선택된 벽의 위치

// bfs에 필요한 변수들
queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

int ans = INT_MAX;
int wallCnt;

void Initialize(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
            step[i][j] = 0;
        }
    }
}

// queue에 새로운 위치를 추가하고
// 방문 여부를 표시해줍니다.
// 시작점으로 부터의 최단거리 값도 갱신해줍니다.
void Push(int x, int y, int d){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    step[x][y] = d;
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 격자를 벗어나지 않으면서, 벽도 없고, 아직 방문한 적이 없는 곳이라면
// 지금 이동하는 것이 최단거리임을 보장할 수 있으므로 가야만 합니다. 
bool CanGo(int x, int y){
    return InRange(x,y) && grid[x][y] == 0 && !visited[x][y];
}

// bfs를 통해 최소 이동 횟수를 구합니다.
void bfs(){
    // queue에 남은 것이 없을때까지 반복합니다.
    while(!q.empty()){
        // queue에서 가장 먼저 들어온 원소를 뺍니다.
        pair<int, int> curr = q.front();
        q.pop();

        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        // queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            
            // 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            // 새로 queue에 넣어줍니다. 
            if(CanGo(nx,ny)){
                // 최단 거리는 이전 최단거리에 1이 증가하게 됩니다. 
                Push(nx,ny,step[curr.first][curr.second]+1);
            }
        }
    }
}

void FindMinTime(){     // k개의 벽을 없앴을 때 시작점에서 도착점까지 이동하는데 걸리는 최소 시간 구하기
    // 탐색 전 초기화하기
    Initialize();
    // 시작점으로부터 탐색 시작
    Push(r1,c1,0);
    bfs();
    // 만약 도착점에 도달했다면 ans 업데이트
    if(visited[r2][c2])
        ans = min(ans, step[r2][c2]);
}

void DeleteWalls(){
    for(int i=0; i<k; i++){
        int wallNum = selected_walls[i];
        grid[walls[wallNum].first][walls[wallNum].second] = 0;
    }
}

void RepairWalls(){
    for(int i=0; i<k; i++){
        int wallNum = selected_walls[i];
        grid[walls[wallNum].first][walls[wallNum].second] = 1;
    }
}
void Choose(int num){
    if((int)selected_walls.size() == k){
        // k개의 벽을 골랐으면 탐색 시작
        DeleteWalls();
        FindMinTime();
        RepairWalls();
        return;
    }

    for(int i=num; i<wallCnt; i++){
        selected_walls.push_back(i);
        //grid[walls[i].first][walls[i].second] = 0;  // 벽 제거
        Choose(i+1);
        //grid[walls[i].first][walls[i].second] = 1; // 벽 원상 복구
        selected_walls.pop_back();
    }
}

/*
해설에서의 Backtracking 함수

void FindMin(int idx, int cnt){
    if(idx == (int)stone_pos.size()){
        if(cnt == k){
            // visited, step 값을 초기화해주기
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    visited[i][j] = step[i][j] = 0;
            
            // bfs를 이용해 최소 이동 횟수를 구하기
            // 시작점을 queue에 넣고 시작하기
            Push(r1, c1, 0);
            int min_dist = bfs();
            ans = min(min_dist, ans);
        }
        return;
    }

    a[stone_pos[idx].first][stone_pos[idx].second] = 0;
    FindMin(idx+1, cnt+1);
    a[stone_pos[idx].first][stone_pos[idx].second] = 1;

    FindMin(idx+1, cnt);
}
*/
int main() {
    // 입력:
    cin >> n >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j]; 
            if(grid[i][j]){
                walls.push_back(make_pair(i,j));
            }
        }
    
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    wallCnt = (int)walls.size();
    Choose(0);  // 없앨 첫 번째 벽 구하기

    // 출력:
    if(ans == INT_MAX)  // 불가능한 경우라면 -1을 답으로 넣어주기
        ans = -1;
    cout << ans;
    return 0;
}