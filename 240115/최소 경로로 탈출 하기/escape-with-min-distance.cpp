#include <iostream>
#include <queue>
#define MAX_N 100

using namespace std;
int n, m;
int grid[MAX_N][MAX_N];
int loc[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue<pair<int, int> > q;
int ans = -1;
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && grid[x][y];
}

void BFS(){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = curr.first+dirs[i][0], ny = curr.second+dirs[i][1];
            if(CanGo(nx,ny)){
                loc[nx][ny] = loc[curr.first][curr.second]+1;
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
    if(visited[n-1][m-1]){
        ans = loc[n-1][m-1];
    }
    cout << ans;
    return 0;
}