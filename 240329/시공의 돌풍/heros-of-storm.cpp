#include <iostream>
#include <vector>

#define MAX_NUM 50
#define DIR_NUM 4
#define WINDBLAST -1

using namespace std;

int n, m, t;

int dust[MAX_NUM][MAX_NUM];
int next_dust[MAX_NUM][MAX_NUM];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanSpread(int x, int y) {
    return InRange(x, y) && dust[x][y] != WINDBLAST;
}

// (x, y)에서 인접한 4방향으로 확산이 일어납니다.
void Spread(int x, int y) {
    int dx[DIR_NUM] = {-1, 1, 0, 0};
    int dy[DIR_NUM] = {0, 0, -1, 1};
    
    int curr_dust = dust[x][y];
    
    // 인접한 4방향으로 확산이 일어납니다.
    for(int i = 0; i < DIR_NUM; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        // 격자 안이면서, 시공의 돌풍이 없는 곳으로만 확산이 가능합니다.
        if(CanSpread(nx, ny)) {
            next_dust[nx][ny] += curr_dust / 5;
            dust[x][y] -= curr_dust / 5;
        }
    }
}

void Diffusion() {
    // next_dust 값을 0으로 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            next_dust[i][j] = 0;
    
    // 시공의 돌풍을 제외한 위치에서만 확산이 일어납니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(dust[i][j] != WINDBLAST)
                Spread(i, j);
    
    // next_dust값을 확산 후 남은 dust에 더해줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dust[i][j] += next_dust[i][j];
}

void CounterClockwiseRotation(int start_row, int start_col, int end_row, int end_col) {
    // Step1-1. 직사각형 가장 왼쪽 위 모서리 값을 temp에 저장합니다.
    int temp = dust[start_row][start_col];

    // Step1-2. 직사각형 가장 위 행을 왼쪽으로 한 칸씩 shift 합니다.
    for(int col = start_col; col < end_col; col++)
        dust[start_row][col] = dust[start_row][col + 1];
    
    // Step1-3. 직사각형 가장 오른쪽 열을 위로 한 칸씩 shift 합니다.
    for(int row = start_row; row < end_row; row++)
        dust[row][end_col] = dust[row + 1][end_col];
    
    // Step1-4. 직사각형 가장 아래 행을 오른쪽으로 한 칸씩 shift 합니다.
    for(int col = end_col; col > start_col; col--)
        dust[end_row][col] = dust[end_row][col - 1];
    
    // Step1-5. 직사각형 가장 왼쪽 열을 아래로 한 칸씩 shift 합니다.
    for(int row = end_row; row > start_row; row--)
        dust[row][start_col] = dust[row - 1][start_col];

    // Step1-6. temp를 가장 왼쪽 위 모서리를 기준으로 바로 아래 칸에 넣습니다. 
    dust[start_row + 1][start_col] = temp;
}

void ClockwiseRotation(int start_row, int start_col, int end_row, int end_col) {
    // Step1-1. 직사각형 가장 왼쪽 위 모서리 값을 temp에 저장합니다.
    int temp = dust[start_row][start_col];

    // Step1-2. 직사각형 가장 왼쪽 열을 위로 한 칸씩 shift 합니다.
    for(int row = start_row; row < end_row; row++)
        dust[row][start_col] = dust[row + 1][start_col];
    
    // Step1-3. 직사각형 가장 아래 행을 왼쪽으로 한 칸씩 shift 합니다.
    for(int col = start_col; col < end_col; col++)
        dust[end_row][col] = dust[end_row][col + 1];

    // Step1-4. 직사각형 가장 오른쪽 열을 아래로 한 칸씩 shift 합니다.
    for(int row = end_row; row > start_row; row--)
        dust[row][end_col] = dust[row - 1][end_col];
    
    // Step1-5. 직사각형 가장 위 행을 오른쪽으로 한 칸씩 shift 합니다.
    for(int col = end_col; col > start_col; col--)
        dust[start_row][col] = dust[start_row][col - 1];

    // Step1-6. temp를 가장 왼쪽 위 모서리를 기준으로 바로 오른쪽 칸에 넣습니다. 
    dust[start_row][start_col + 1] = temp;
}

void Cleaning() {
    vector<int> windblast_rows;
    for(int i = 0; i < n; i++)
        if(dust[i][0] == WINDBLAST)
            windblast_rows.push_back(i);
            
    CounterClockwiseRotation(0, 0, windblast_rows[0], m - 1);
    ClockwiseRotation(windblast_rows[1], 0, n - 1, m - 1);
    
    // 돌풍 보정
    dust[windblast_rows[0]][0] = dust[windblast_rows[1]][0] = -1;
    dust[windblast_rows[0]][1] = dust[windblast_rows[1]][1] = 0;
}

void Simulate() {
    // 확산이 일어납니다.
    Diffusion();
    
    // 시공의 돌풍이 청소를 진행합니다.
    Cleaning();
}

int main() {
    cin >> n >> m >> t;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> dust[i][j];

    // 총 t번 시뮬레이션을 진행합니다.
    while(t--)
        Simulate();
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(dust[i][j] != WINDBLAST)
                ans += dust[i][j];
    
    cout << ans;
    return 0;
}