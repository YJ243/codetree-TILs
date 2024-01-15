#include <iostream>
#include <queue>
#define MAX_N 100

using namespace std;
int n,k;

int grid[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<pair<int, int> > q;

void Push(int x, int y, int t){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    step[x][y] = t;
    grid[x][y] = 2;
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && grid[x][y] == 1 && !visited[x][y];
}

void bfs(){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            if(CanGo(nx,ny)){
                Push(nx,ny, step[curr.first][curr.second]+1);
            }
        }
    }
}

int main() {
    cin >> n >> k;    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                Push(i,j,0);
            }
            else if(grid[i][j] == 0)
                step[i][j] = -1;
        }
    }

    bfs();
    // 끝까지 상하지 않는 귤 처리
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1 && step[i][j] == 0)
                step[i][j] = -2;
        }
    }
    // 출력:
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << step[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}