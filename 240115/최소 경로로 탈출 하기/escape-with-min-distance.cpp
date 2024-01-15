/*
 * 시간복잡도: BFS는 한 번 방문한 위치는 다시 방문하지 않기 때문에, 격자의 크기에 해당하는 O(NM)
*/
#include <iostream>
#include <queue>
#define MAX_N 100

using namespace std;

// 전역 변수 선언:
int n, m;
int grid[MAX_N][MAX_N];

// bfs에 필요한 변수들
queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
int loc[MAX_N][MAX_N];  // loc[i][j]: 시작점으로부터 (i,j) 지점에 도달하기 위한 최단 거리

int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int ans = -1;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

// 격자를 벗어나지 않으면서, 아직 방문한 적이 없고, 뱀도 없으면
// 지금 이동하는 것이 최단거리를 보장할 수 있으므로 가야만 함
bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && grid[x][y];
}

// bfs를 통해 최소 이동 횟수를 구하기
void BFS(){
    // 큐에 남은 것이 없을 때까지 반복
    while(!q.empty()){
        // queue에서 가장 먼저 들어온 원소를 빼기
        pair<int, int> curr = q.front();
        q.pop();

        // 큐에서 뺀 원소의 위치를 기준으로 4방향을 확인해보기
        for(int i=0; i<4; i++){
            int nx = curr.first+dirs[i][0], ny = curr.second+dirs[i][1];
            if(CanGo(nx,ny)){
                // queue에 새로운 위치를 추가하고 방문 여부를 표시
                // 시작점으로부터의 최단거리 값도 갱신
                loc[nx][ny] = loc[curr.first][curr.second]+1;   // 최단거리는 이전 최단거리에 1이 증가
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    cin >> n >> m;  // n*m크기의 격자
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];  // 뱀X:1, 뱀:0
    
    visited[0][0] = true;
    q.push(make_pair(0,0));
    BFS();

    // 우측 하단에 가는 것이 가능할 때만 답을 갱신해주기
    if(visited[n-1][m-1]){
        ans = loc[n-1][m-1];
    }
    cout << ans;
    return 0;
}