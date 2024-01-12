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
        // 해당 방향에서 갈 수 있는 곳 탐색
        int nx = x+dx[directions[x][y]]*i, ny = y+dy[directions[x][y]]*i;
        if(CanGo(nx,ny,numbers[x][y])){
            moving_dist++;                  // 움직일 수 있다면 거리 증가시키기
            ans = max(ans, moving_dist);    // 움직일 때마다 정답 업데이트
            Move(nx,ny);                    // 다음 좌표로 이동
            moving_dist--;                  // 리턴 후 거리 감소
        }
    }
}

/*
해설에서는 이 Move를 아래와 같이 짰음
void FindMax(int x, int y, int cnt){
    // 언제 끝날 지 모르기 때문에 항상 최댓값을 갱신
    ans = max(ans, cnt);

	int dx[DIR_NUM] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int dy[DIR_NUM] = {0, 1, 1, 1, 0, -1, -1, -1};
    int d = move_dir[x][y] -1;

    for(int i=0; i<n; i++){
        int nx = x+dx[d]*i, ny = y+dy[d]*i;
        if(CanGo(nx,ny,num[x][y]))
            FindMax(nx, ny, cnt+1);
    }
}

*/

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
    r--;c--;        // 좌표는 (0,0)에서 시작
    Move(r,c);      // (r,c)에서 움직일 곳을 찾는 함수
    // 출력:
    cout << ans;    
    return 0;
}