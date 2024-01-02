#include <iostream>
#include <queue>

#define MAX_N 100
#define MAX_M 100
using namespace std;

// 전역 변수 선언:
int n, m;
int grid[MAX_N][MAX_N];

// bfs에 필요한 변수
bool visited[MAX_N][MAX_N];
queue<pair<int,int> > q;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y){
    return InRange(x,y) && grid[x][y] && !visited[x][y];
}

void BFS(){
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    // queue에 남은 것이 없을 때까지 반복
    while(!q.empty()){
        // queue에서 가장 먼저 들어온 원소를 빼
        pair<int, int> cur = q.front();
        q.pop();

        // queue에서 뺀 원소의 위치를 기준으로 4방향을 확
        for(int i=0; i<4; i++){
            int nx = cur.first + dirs[i][0];
            int ny = cur.second + dirs[i][1];
            // 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            // 새로 queue에 넣어주고 방문 여부를 표시
            if(CanGo(nx,ny)){
                // 만약 갈 수 있다면
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    // 입력:
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];  // 1: 빈칸, 0: 뱀
        }
    }

    // bfs를 이용해 최소 이동 횟수를 구하기
    // 시작점을 queue에 넣고 시작
    visited[0][0] = true;
    q.push(make_pair(0,0));
    BFS();

    // 우측 하단을 방문한 적이 있는지 여부를 출력
    cout << visited[n-1][m-1];
    return 0;
}