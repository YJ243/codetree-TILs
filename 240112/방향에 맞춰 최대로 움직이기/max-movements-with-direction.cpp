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

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Move(int x, int y){
    /*
    // 이동 가능할 때에만 Move를 부르
    if(!InRange(x,y)){
        // 해당 위치로 왔을 때 더이상 이동하지 못한다면
        ans = max(ans, moving_dist);
        return;
    }
    */

    //cout << x << ' ' << y << ' ' << moving_dist << '\n';
    // 1. directions[x][y]방향에 숫자가 현재보다 작은게 있다면 한칸 이동
    for(int i=1; i<4; i++){
        int nx = x+dx[directions[x][y]]*i, ny = y+dy[directions[x][y]]*i;
        if(InRange(nx,ny) && numbers[nx][ny] > numbers[x][y]){
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