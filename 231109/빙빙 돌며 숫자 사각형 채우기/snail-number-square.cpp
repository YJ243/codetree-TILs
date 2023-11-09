#include <iostream>
#define MAX_N 100
using namespace std;

int n, m;
int x, y, cur_d;
int num=1;
int maze[MAX_N][MAX_N];
int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}
int main() {
    cin >> n >> m;
    maze[0][0] = num;
    num++;
    for(int i=num; i <= n*m; i++){
        int nx = x+dirs[cur_d][0], ny = y+dirs[cur_d][1];
        if(!InRange(nx,ny) || maze[nx][ny]!=0){
            cur_d = (cur_d+1)%4;
        }
        x += dirs[cur_d][0];
        y += dirs[cur_d][1];

        maze[x][y] = num;
        num++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<maze[i][j]<<' ' ;
        }
        cout<<'\n';
    }
    return 0;
}