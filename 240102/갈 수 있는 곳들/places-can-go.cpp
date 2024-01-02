#include <iostream>
#include <queue>

#define MAX_N 100
using namespace std;

// 전역 변수 선언:
int n, k;
int grid[MAX_N][MAX_N];
int ans;

// bfs에 필요한 변수들
bool visited[MAX_N][MAX_N];
queue<pair<int, int> > q;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && !grid[x][y];
}

void BFS(){
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    // queue에 남은 것이 없을 때까지 반복
    while(!q.empty()){
        // queue에서 가장 먼저 들어오 ㄴ원소를 빼기
        pair<int, int> cur = q.front();
        q.pop();

        // queue에서 뺀 원소의 위치를 기준으로 4방향 확인
        for(int i=0; i<4; i++){
            int nx = cur.first + dirs[i][0];
            int ny = cur.second + dirs[i][1];

            // 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            // 새로 queue에 넣어주고 방문 여부를 표시
            if(CanGo(nx,ny)){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    // 입력:
    cin >> n >> k;  // n: 격자 행열 수, k: 시작점 개수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];      // 0: 이동가능, 1: 이동X
        }
    }

    // 시작점을 모두 bfs queue에 넣기
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        visited[x-1][y-1] = true;
        q.push(make_pair(x-1,y-1));
    }

    // bfs를 진행
    BFS();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += visited[i][j];
        }
    }
    cout << ans;
    return 0;
}