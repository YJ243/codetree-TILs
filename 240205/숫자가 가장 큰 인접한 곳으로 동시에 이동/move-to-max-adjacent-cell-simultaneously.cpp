#include <iostream>
#include <tuple>
#define MAX_N 20
using namespace std;

int n, m, t;    // n: 격자 크기, m: 구슬 개수, t: 시간
int grid[MAX_N][MAX_N];
int count[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int ans;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

pair<int, int> FindNextLoc(int x, int y){       // (x,y)가 다음에 이동할 위치를 반환하는 함수
    int maxValue=0, maxX=0, maxY=0;
    for(int d=0; d<4; d++){
        int nx = x+dirs[d][0], ny = y+dirs[d][1];
        if(InRange(nx,ny) && maxValue < grid[nx][ny])
            maxValue = grid[nx][ny], maxX = nx, maxY = ny;
    }
    return make_pair(maxX,maxY);
}

void Simulate(){
    // 중간에 구슬 이동을 위한 임시 배열
    int tmp[MAX_N][MAX_N];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            tmp[i][j] = 0;

    // 구슬이 있는 위치를 보면서 옮겨주기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(count[i][j]){
                int r, c;
                tie(r,c) = FindNextLoc(i,j);
                tmp[r][c]++;
            }
        }
    }

    // 이동한 이후에 2개 이상의 구슬 위치에 대해서 없애주기
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(tmp[i][j] > 1)
                tmp[i][j] = 0;
    
    // 중간에 저장한 배열을 count로 옮겨주기
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            count[i][j] = tmp[i][j];
}

int main() {
    cin >> n >> m >> t;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    for(int i=0; i<m; i++){
        int r, c;
        cin >> r >> c;
        count[r-1][c-1]++;
    }
    // 시뮬레이션 진행
    while(t--){
        Simulate();
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ans += count[i][j];
    cout << ans;
    return 0;
}