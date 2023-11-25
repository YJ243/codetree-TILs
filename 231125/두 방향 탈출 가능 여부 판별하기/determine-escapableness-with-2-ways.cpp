#include <iostream>
#define MAX_N 100
using namespace std;

int n, m;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && arr[x][y];
}

void dfs(int x, int y){
    int dirs[2][2] = {{1,0},{0,1}};
    for(int i=0; i<2; i++){
        int nx = x+dirs[i][0], ny = y+dirs[i][1];
        if(CanGo(nx,ny)){
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];   // 뱀X: 1, 뱀o:0
        }
    }

    visited[0][0] = true;
    dfs(0,0);

    cout << visited[n-1][m-1];

}