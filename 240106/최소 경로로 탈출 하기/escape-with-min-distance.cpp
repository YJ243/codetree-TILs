#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 100

using namespace std;

int n, m;
int a[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int, int> > q;
int ans = -1;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && a[x][y];
}

void Push(int x, int y, int s){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    step[x][y] = s;
}

void bfs(){
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        for(int d=0; d<4; d++){
            int nx = cur.first + dirs[d][0], ny = cur.second + dirs[d][1];
            if(CanGo(nx,ny)){
                Push(nx,ny,step[cur.first][cur.second]+1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];     // 1: 이동 가능, 0: 뱀
        }
    }
    Push(0,0,0);
    bfs();
    
    if(visited[n-1][m-1]){
        ans = step[n-1][m-1];
    }
    
    cout << ans;

    return 0;
}