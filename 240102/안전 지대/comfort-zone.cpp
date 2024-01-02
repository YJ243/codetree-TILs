#include <iostream>
#include <algorithm>
#define MAX_N 50
using namespace std;

// 안전영역: K초과
int n, m;
int grid[MAX_N][MAX_N];
int ans;
int max_k;
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y, int k){
    return InRange(x,y) && grid[x][y] > k && !visited[x][y];
}

void Initialize(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
}

void DFS(int x, int y, int k){
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0; i<4; i++){
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if(CanGo(nx,ny,k)){
            visited[nx][ny] = true;
            DFS(nx,ny,k);
        }
    }
}

int main() {
    int max_h = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            max_h = max(max_h, grid[i][j]);
        }
    }

    for(int k=1; k<=max_h; k++){
        // visited배열 초기화
        Initialize();
        int cur = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(CanGo(i,j,k)){
                    visited[i][j] = true;
                    cur++;
                    DFS(i,j,k);
                }
            }
        }
        if(ans < cur){
            ans = cur;
            max_k = k;
        }
    }
    if(max_k == 0){
        // 만약 최대 k가 1 이상인 수로 바뀌지 않았다면
        max_k = 1;
    }
    cout << max_k << ' ' << ans;
    return 0;
}