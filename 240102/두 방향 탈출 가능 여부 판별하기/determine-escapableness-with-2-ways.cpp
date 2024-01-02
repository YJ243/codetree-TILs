#include <iostream>
#define MAX_N 100
using namespace std;
int n,m;

int dirs[2][2] = {{1,0},{0,1}}; // 아래, 오른쪽
int graph[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int ans;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y){
    // 범위 안에 있고, 방문하지 않았으며, 빈칸일 경우 갈 수 있음
    return InRange(x,y) && !visited[x][y] && graph[x][y];
}

void DFS(int x, int y){
    for(int i=0; i<2; i++){
        int nx = x+dirs[i][0], ny = y+dirs[i][1];
        if(CanGo(nx,ny)){
            visited[nx][ny] = 1;
            DFS(nx,ny);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j]; // 1: 빈칸, 0: 뱀
        }
    }

    visited[0][0] = true; // 시작칸 방문 처리
    DFS(0,0);
    
    if(visited[n-1][m-1]){
        ans = 1;
    }
    cout << ans;
    return 0;
}