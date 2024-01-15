#include <iostream>
#include <queue>
#include <climits>

#define MAX_N 100
using namespace std;

int n, h, m;    // n: 격자 크기, h: 사람 명수, m: 비를 피할 수 있는 공간 위치 개수
int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int grid[MAX_N][MAX_N];     // 0: 이동 가능, 1: 벽으로 이동 불가, 2: 사람, 3: 비를 피할 수 있는 공간

queue<pair<int, int> > q;
int step[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int curMin = INT_MAX;

int result[MAX_N][MAX_N];   // 0: 사람X, 양수: 비를 피할 수 있는 공간까지 최소 시간, -1: 비를 피할 수 없음 

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && grid[x][y] != 1;
}

void Initialize(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            visited[i][j] = false;
            step[i][j] = 0;
        }

    curMin = INT_MAX;
}
void Push(int x, int y, int d){
    q.push(make_pair(x,y));
    visited[x][y] = true;
    step[x][y] = d;
}

void bfs(){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
    
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            if(CanGo(nx,ny)){
                Push(nx,ny,step[curr.first][curr.second]+1);
                if(grid[nx][ny] == 3){
                    curMin = min(curMin, step[curr.first][curr.second]+1);
                }
            }
        }
    }
}

int main() {
    // 입력:
    cin >> n >> h >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    // 탐색 진행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 2){
                // 초기화하기
                Initialize();
                Push(i,j,0);
                bfs();
                if(curMin!=INT_MAX)
                    result[i][j] = curMin;
                else
                    result[i][j] = -1;
            }
        }
    }

    // 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}