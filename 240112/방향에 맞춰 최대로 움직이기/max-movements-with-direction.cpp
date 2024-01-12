#include <iostream>
#include <algorithm>
#define MAX_N 4
using namespace std;

int numbers[MAX_N][MAX_N];          // 각 칸에 적혀있는 숫자
int directions[MAX_N][MAX_N];       // 해당 칸에 적혀있는 방향을 나타내는 숫자
int dx[8] = {-1,-1,0,1,1,1,0,-1};   // 8방향의 x
int dy[8] = {0,1,1,1,0,-1,-1,-1};   // 8방향의 y

int n;                              // 격자의 크기
int r, c;                           // 시작점 좌표
int moving_dist;                    // 움직인 거리
int ans;                            // 최대 이동할 수 있는 거리

bool InRange(int x, int y){         // 해당 좌표가 범위 안에 있는지 인
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int prior_num){    // 해당 좌표가 범위 안에 있고, 이전 숫자보다 크다면 이동 가능
    return InRange(x,y) && numbers[x][y] > prior_num;
}

void Move(int x, int y){
    for(int i=1; i<n; i++){
        int nx = x+dx[directions[x][y]]*i, ny = y+dy[directions[x][y]]*i;
        if(CanGo(nx,ny,numbers[x][y])){
            moving_dist++;
            ans = max(ans, moving_dist);    // 움직일 때마다 정답 업데이트
            Move(nx,ny);
            moving_dist--;
        }
    }

}

int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> numbers[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> directions[i][j];
            directions[i][j]--;
        }    
    cin >> r >> c;
    r--;c--;
    Move(r,c);      // (r,c)에서 움직일 곳을 가는 함수
    cout << ans;
    return 0;
}