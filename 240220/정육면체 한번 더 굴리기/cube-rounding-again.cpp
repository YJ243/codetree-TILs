#include <iostream>
#define MAX_N 20
using namespace std;
int n, m;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};   // 상, 우, 하, 좌
int cur_d = 1;              // 처음 방향은 오른쪽
pair<int, int> dice_loc;    // 주사위가 놓인 위치

int same_cnt;
int dice[3] = {1, 2, 3};    // 위, 앞, 오 숫자
int total_score;            // 전체 점수

void Input(){
    cin >> n >> m;    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
}


bool InRange(int x, int y){     // (x,y)가 범위 안에 있는지 확인하는 함수 
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Move_dice(){
    // 1. 주사위 숫자 업데이트
    int a = dice[0], b = dice[1], c = dice[2];
    if(cur_d == 0){         // 위로 움직임
        dice[0] = b, dice[1] = 7-a;
    }
    else if(cur_d == 1){    // 오른쪽으로 움직임 
        dice[0] = 7-c, dice[2] = a;
    }
    else if(cur_d == 2){    // 아래로 움직임
        dice[0] = 7-b, dice[1] = a;
    }
    else{               // 왼쪽으로 움직임
        dice[0] = c, dice[2] = 7-a;
    }

    // 2. 주사위 위치 업데이트
    int x = dice_loc.first, y = dice_loc.second;
    dice_loc = make_pair(x+dirs[cur_d][0], y+dirs[cur_d][1]);

}

void Decide_direction(){
    int bottom = 7-dice[0];
    int cur_num = grid[dice_loc.first][dice_loc.second];
    
    if(bottom > cur_num){
        // 90도 시계방향으로 돌리기
        cur_d = (cur_d + 1) % 4;
    }
    else if(bottom < cur_num){
        // 90도 반시계 방향으로 돌리기
        cur_d = (cur_d - 1) % 4;
    }

    if(!InRange(dice_loc.first + dirs[cur_d][0], dice_loc.second + dirs[cur_d][1])){
        // 만약 격자 판을 벗어난다면 반대방향으로 이동하기
        cur_d = (cur_d + 2) % 4;
    }
    Move_dice();   // cur_d 방향으로 이동시키기
}

void Initialize_before_search(){
    // 1. 방문 배열 초기화
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;

    // 2. 인접한 칸에 적힌 같은 숫자 개수 초기화 
    same_cnt = 1;
}

bool CanGo(int x, int y, int val){
    // 범위 안에 있고, 아직 방문하지 않았으며, val값과 같을 경우 이동 가능
    return InRange(x, y) && !visited[x][y] && grid[x][y] == val;
}

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if(CanGo(nx, ny, grid[x][y])){
            visited[nx][ny] = true;
            same_cnt++;
            dfs(nx, ny);
        }
    }
}


void Simulate(int turn){
    // Step 1. 현재 주사위가 이동할 방향 정해서 한칸 이동하기
    if(turn == 0)
        Move_dice();
    else
        Decide_direction();
    
    // Step 2. 점수 얻기
    // 2-1. 현재 주사위가 놓인 위치를 기준으로 탐색 진행
    //      인접한 행열에서 같은 숫자의 개수만큼 점수 더해주기
    Initialize_before_search();
    int x = dice_loc.first, y = dice_loc.second;
    visited[x][y] = true;
    dfs(x, y);      // (x,y)를 기준으로 같은 숫자가 있는지 탐색 진행
    total_score += grid[x][y]*same_cnt;
}


int main() {
    // 입력 받기
    Input();

    for(int r=0; r<m; r++){
        // m번에 걸쳐서 주사위 굴리기
        Simulate(r);
    }
    // 출력하기
    cout << total_score;
    return 0;
}