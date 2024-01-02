#include <iostream>
#include <queue>

#define MAX_N 100
using namespace std;
int n, k;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<pair<int, int> > q;
int ans;
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && !grid[x][y];
}

void BFS(){
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dirs[i][0];
            int ny = cur.second + dirs[i][1];
            if(CanGo(nx,ny)){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    cin >> n >> k;  // n: 격자 행열 수, k: 시작점 개수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];      // 0: 이동가능, 1: 이동X
        }
    }

    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        visited[x-1][y-1] = true;
        q.push(make_pair(x-1,y-1));
    }
    BFS();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += visited[i][j];
        }
    }
    cout << ans;
    return 0;
}