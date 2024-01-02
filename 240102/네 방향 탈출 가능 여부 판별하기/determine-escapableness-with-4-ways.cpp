#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 100
using namespace std;
int n, m;
int grid[MAX_N][MAX_N];
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
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dirs[i][0];
            int ny = cur.second + dirs[i][1];
            if(CanGo(nx,ny)){
                // 만약 갈 수 있다면
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];  // 1: 빈칸, 0: 뱀
        }
    }
    visited[0][0] = true;
    q.push(make_pair(0,0));
    BFS();

    cout << visited[n-1][m-1];
    return 0;
}