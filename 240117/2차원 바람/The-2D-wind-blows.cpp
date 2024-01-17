#include <iostream>
#define MAX_N 100
#define MAX_M 100

using namespace std;

int n, m, q;                // n:행, m: 열, q: 바람 횟수
int grid[MAX_N][MAX_M];     // 건물 상태
int grid2[MAX_N][MAX_M];     // 직사각형 내부 값을 동시에 변화시키기 위한 임시 배열

void WindtoEdge(int r1, int c1, int r2, int c2){
    // 1. 윗줄: 오른쪽으로 밀기
    int temp = grid[r1][c2];    // 제일 오른쪽 값 보관
    for(int i=c2; i>=c1+1; i--)
        grid[r1][i] = grid[r1][i-1];
    
    // 2. 오른쪽 줄: 아래로 밀기
    int temp2 = grid[r2][c2];   // 제일 아래값 보관
    for(int i=r2; i >= r1+2; i--)
        grid[i][c2] = grid[i-1][c2];
    grid[r1+1][c2] = temp;      // 앞에서 보관했던 제일 오른쪽 값 넣기

    // 3. 아래줄: 왼쪽으로 밀기
    temp = grid[r2][c1];        // 제일 왼쪽 값 보관
    for(int i=c1; i<=c2-2; i++)
        grid[r2][i] = grid[r2][i+1];
    grid[r2][c2-1] = temp2;     // 앞에서 보관했던 제일 아래값 넣기

    // 4. 왼쪽 줄: 위로 밀기
    for(int i=r1; i<=r2-2; i++)
        grid[i][c1] = grid[i+1][c1];
    grid[r2-1][c1] = temp;      // 앞에서 보관했던 제일 왼쪽 값 넣기
}

bool InRange(int x, int y){ 
    return 0 <= x && x < n && 0 <= y && y < m;
}

void ChangeInternal(int r1, int c1, int r2, int c2){
    for(int i = r1; i <= r2; i++){
        for(int j=c1; j <= c2; j++){
            int curSum = grid[i][j], curCnt = 1;
            int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int d=0; d<4; d++){
                int nx = i+dirs[d][0], ny = j+dirs[d][1];
                if(InRange(nx,ny)){
                    curSum += grid[nx][ny];
                    curCnt++;
                }
            }
            grid2[i][j] = curSum/curCnt;
        }
    }

    // 직사각형 옮기기
    for(int i=r1; i<=r2; i++)
        for(int j=c1; j<=c2; j++)
            grid[i][j] = grid2[i][j];
}

void Simulate(int r1, int c1, int r2, int c2){
    // Step 1. 직사각형 경계에 대해서 시계방향으로 한 칸씩 회전하기
    WindtoEdge(r1, c1, r2, c2);

    // Step 2. 직사각형 영역 내에 있는 숫자들 평균값으로 바꾸기
    ChangeInternal(r1, c1, r2, c2);
}

int main() {
    // 입력:
    cin >> n >> m >> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    
    for(int i=0; i<q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        // 해당 직사각에 대해서 시뮬레이션 진행
        Simulate(r1, c1, r2, c2);
    }

    // 출력:
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}