#include <iostream>
#include <queue>
#define MAX_N 100
#define DIR_NUM 8
using namespace std;

// 전역 변수 선언:
int n;
int r1, c1, r2, c2;
int dirs[DIR_NUM][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

// bfs에 필요한 변수들
queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];     // step[i][j]: 시작점으로부터 (i,j) 지점에 도달하기 위한 최단 거리 기록

int ans = -1;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 격자를 벗어나지 않으면서, 아직 방문한 적이 없는 곳이라면
// 지금 이동하는 것이 최단거리임을 보장할 수 있으므로 가야만 함
bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y];
}

// queue에 새로운 위치를 추가하고
// 방문 여부를 표시
void Push(int x, int y, int d){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    step[x][y] = d;
}

// bfs를 통해 최소 이동 횟수를 구하기
void bfs(){
    // queue에 남은 것이 없을 때까지 반복
    while(!q.empty()){
        // queue에서 가장 먼저 들어온 원소를 빼기
        pair<int, int> curr = q.front();
        q.pop();

        // 큐에서 뺀 원소의 위치를 기준으로 8방향을 확인
        for(int i=0; i<DIR_NUM; i++){
            int nx = curr.first + dirs[i][0], ny = curr.second + dirs[i][1];
            // 아직 방문한 적이 없으면서 갈 수 있는 곳이라면
            // 새로 큐에 넣어주기
            if(CanGo(nx,ny)){
                // 최단 거리는 이전 최단거리에 1이 증가
                Push(nx,ny,step[curr.first][curr.second]+1);
            }
        }
    }
}

int main() {
    // 입력:
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;c1--;r2--;c2--;

    // bfs를 이용해 최소 이동 횟수를 구하기
    // 시작점을 queue에 넣고 시작하기
    Push(r1, c1, 0);
    bfs();

    // 출력:
    // 도착지에 가는 것이 가능할 때만 답을 갱신해주기
    if(visited[r2][c2])
        ans = step[r2][c2];

    cout << ans;
    return 0;
}