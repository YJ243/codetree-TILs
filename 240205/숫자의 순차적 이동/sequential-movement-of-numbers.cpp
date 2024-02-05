#include <iostream>
#define MAX_N 20

using namespace std;
int n, m;
int grid[MAX_N][MAX_N];
pair<int, int> num_loc[MAX_N*MAX_N+1];
int dirs[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Simulate(){
    // 1이 적힌 위치부터 확인
    for(int i=1; i<=n*n; i++){
        int x = num_loc[i].first, y = num_loc[i].second;
        int curr = grid[x][y];
        int maxV = 0, maxX=0, maxY=0;
        for(int d=0; d<8; d++){ // 여덟방향으로 인접한 곳 중 가장 큰 수의 위치 확인
            int nx = x+dirs[d][0], ny = y+dirs[d][1];
            if(InRange(nx,ny) && maxV < grid[nx][ny]){
                maxV = grid[nx][ny], maxX = nx, maxY = ny;
            }
        }
        // 현재 위치와 가장 큰 수의 위치 바꿔주기
        int tmp = grid[x][y];
        grid[x][y] = grid[maxX][maxY];
        grid[maxX][maxY] = tmp;

        // num_loc도 바꿔주기
        num_loc[grid[maxX][maxY]] = make_pair(maxX, maxY);
        num_loc[grid[x][y]] = make_pair(x,y);
    }
}

int main() {
    // 변수 선언 및 입력:
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            num_loc[grid[i][j]] = make_pair(i,j);
        }

    while(m--){
        Simulate();
    }

    // 정답 출력하기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}