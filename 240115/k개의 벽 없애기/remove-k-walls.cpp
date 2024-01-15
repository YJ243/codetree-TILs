#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_N 100
using namespace std;

int n, k;                       // n: 격자 크기, k: 없애야 할 벽의 개수
int r1, c1, r2, c2;             // 시작점과 도착점
vector<pair<int, int> > walls;  // 벽의 위치
vector<int> selected_walls;         // 선택된 벽의 위치
int grid[MAX_N][MAX_N]; // 1: 벽으로 이동 불가, 0: 이동 가능
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
queue<pair<int, int> > q;

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

void Push(int x, int y, int d){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    step[x][y] = d;
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && grid[x][y] == 0 && !visited[x][y];
}

void bfs(){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            if(CanGo(nx,ny)){
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
int main() {
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
    if(ans == INT_MAX)
        ans = -1;
    cout << ans;
    return 0;
}