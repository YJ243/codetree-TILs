#include <iostream>
#include <queue>

#define MAX_N 20

using namespace std;
int n, m;   // n: 격자 크기, m: 굴리는 횟수
int grid[MAX_N][MAX_N];
int dice[3] = {1, 2, 3};    // 위, 앞, 오

int dice_loc[2] = {0,0};    // 주사위 위치
int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   // 우하좌상
int dice_d; // 주사위의 방향

bool visited[MAX_N][MAX_N];
queue<pair<int, int> > q;
int cur_cnt;
int ans;

void Input(){
    cin >> n >> m;      // n: 격자 크기, m: 굴리는 횟수
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];      // 격자 판에 숫자 넣기
}

bool InRange(int x, int y){     // (x, y)가 격자 안에 있는지 확인하는 함수
    return 0 <= x && x < n && 0 <= y && y < n;
}

void UpdateDice(int x, int y){
    int i, j, k;
    if(dice_d == 0){    // 오른쪽 방향
        i = 7-dice[2], j = dice[1], k = dice[0];
    }
    else if(dice_d == 1){   // 아래 방향
        i = 7-dice[1], j = dice[0], k = dice[2];    
    }
    else if(dice_d == 2){   // 왼쪽 방향
        i = dice[2], j = dice[1], k = 7-dice[0];
    }
    else{   // 위쪽 방향
        i = dice[1], j = 7-dice[0], k = dice[2];
    }
    dice[0] = i, dice[1] = j, dice[2] = k;
    dice_loc[0] = x, dice_loc[1] = y;
}

void MoveDice(){    // 주사위를 현재 방향으로 한 칸 이동하는 함수
    int nx = dice_loc[0] + dirs[dice_d][0], ny = dice_loc[1] + dirs[dice_d][1];
    if(!InRange(nx, ny)){   // 만약 다음 위치가 범위를 벗어난다면 
        dice_d = (dice_d + 2) % 4;
        nx = dice_loc[0] + dirs[dice_d][0], ny = dice_loc[1] + dirs[dice_d][1];
    }
    UpdateDice(nx, ny);     // 주사위 위치를 (nx, ny) 칸으로 업데이트하는 함수
    //cout << dice_loc[0] << ' ' << dice_loc[1] << '\n';
    //cout << dice[0] << ' ' << dice[1] << ' ' << dice[2] << '\n';
}

void Initialize_before_search(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
    cur_cnt = 1;
}


bool CanGo(int x, int y, int val){
    return InRange(x, y) && !visited[x][y] && grid[x][y] == val;
}

void bfs(int val){  // val와 같은 숫자를 가진 인접한 칸 개수를 찾는 함수
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        for(int d=0; d<4; d++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(CanGo(nx, ny, val)){
                cur_cnt++;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void UpdateScore(){
    // 방문배열 초기화하기
    Initialize_before_search();

    q.push(make_pair(dice_loc[0], dice_loc[1]));
    visited[dice_loc[0]][dice_loc[1]] = true;
    bfs(grid[dice_loc[0]][dice_loc[1]]);

    ans += grid[dice_loc[0]][dice_loc[1]] * cur_cnt;
}

void UpdateDir(){   // 주사위의 방향을 바꾸는 함수
    int val = 7-dice[0];
    int x = dice_loc[0], y = dice_loc[1];
    if(val > grid[x][y]){
        dice_d = (dice_d + 1)% 4;
    }
    else if(val < grid[x][y]){
        dice_d = (dice_d -1 + 4) % 4;
    }
}

void Simulate(){
    // Step 1. 현재 방향대로 한 칸 움직이기
    MoveDice();
    // Step 2. 주사위 옮긴 칸에서 점수 업데이트 하기 
    UpdateScore();
    // Step 3. 진행방향 틀기
    UpdateDir();
}

int main() {
    // 입력 받기:
    Input();  
    while(m--){ // m번 시뮬레이션 진행하기
        Simulate();
    }  
    cout << ans;
    return 0;
}