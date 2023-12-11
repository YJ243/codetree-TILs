#include <iostream>
using namespace std;

#define MAX_NM 50

int n, m;
char arr[MAX_NM][MAX_NM];

int dirs[8][2] = {{1,-1},{1,0},{1,1},{-1,-1},{-1,0},{-1,1},{0,-1},{0,1}};       // 가로, 세로, 대각선 8개 방향
int ans;

bool InRange(int nx, int ny){
    return 0 <= nx && nx < n && 0 <= ny && ny < m;
}

int main() {
    cin >> n >> m;    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // arr[i][j]가 첫 시작
            if(arr[i][j] == 'L'){
                for(int d=0; d<8; d++){
                    int cnt = 1;
                    int x=i, y=j;
                    while(true){
                        int nx = x+dirs[d][0], ny = y+dirs[d][1];
                        if(!InRange(nx,ny) || arr[nx][ny] != 'E')   break;
                        x = nx, y = ny;
                        cnt++;
                    }
                    if(cnt==3) ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}