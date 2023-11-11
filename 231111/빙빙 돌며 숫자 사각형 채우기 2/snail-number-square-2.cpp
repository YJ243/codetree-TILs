#include <iostream>
#define MAX_N 100

using namespace std;
int n, m;
int x=-1, y=0;
int d;
int arr[MAX_N][MAX_N];
int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; // 아래, 오른쪽, 위, 왼쪽

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n*m; i++){
        int nx = x+dirs[d][0], ny = y+dirs[d][1];
        if(!InRange(nx,ny) || arr[nx][ny] !=0){
            d = (d+1)%4;
        }
        x = x+dirs[d][0], y = y+dirs[d][1];
        arr[x][y]=i;

    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j] << ' ';
        }
        cout<<'\n';
    }
    return 0;
}