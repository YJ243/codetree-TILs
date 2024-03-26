#include <iostream>
#include <queue>
#include <climits>
#define MAX_N 20

using namespace std;

int n, m;               // n: 격자 판 크기, m: 몬스터 개수
int rX, rY;             // robot 좌표
int rLevel=2;           // robot 레벨
int grid[MAX_N][MAX_N]; // 격자판, 0: 빈칸, 1~6: 해당 칸에 있는 몬스터 레벨, 9: 전투로봇
int cur_killed;
int elapsed_time;
// bfs 탐색을 위한 자료구조
queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void Input(){       // 입력값을 받는 함수
    cin >> n;  // 격자판 크기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 9){        // 전투로봇인 경우
                rX = i, rY = j;
            }
        }
    }
}

bool IsFinish(){    // 없앨 수 있는 몬스터가 없는지 확인해서 게임이 종료됐는지 반환하는 함수
    bool LowerLevelExist = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(1 <= grid[i][j] && grid[i][j] <= 6 && grid[i][j] < rLevel)
                LowerLevelExist = true;
        }
    }
    return !LowerLevelExist;
}

void Initialize_before_Search(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
            step[i][j] = 0;
        }
    }
}

void Push(int x, int y, int cur_step){      // (x, y)좌표를 큐에 넣고, 해당칸으로 가는데 까지 걸린 step 수 저장
    visited[x][y] = true;
    q.push(make_pair(x, y));
    step[x][y] = cur_step;
}

bool InRange(int x, int y){         // (x,y)가 범위 안에 있는지 확인하는 함수
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){       // (x,y)로 이동할 수 있는지 확인하는 함수
    // 범위 안에 있고, 아직 방문한 적이 없으며, 몬스터의 레벨수가 로봇보다 작거나 같음 
    return InRange(x, y) && !visited[x][y] && grid[x][y] <= rLevel;
}

pair<int, int> bfs(){
    int tX = INT_MAX, tY = INT_MAX;         // 타겟 몬스터의 좌표
    int minL = INT_MAX;                     // 전투로봇에서 타겟 몬스터까지의 최소 거리
    while(!q.empty()){
        pair<int ,int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second, s = step[x][y];
        for(int d=0; d<4; d++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(CanGo(nx ,ny)){
                Push(nx, ny, s+1);      // 큐에 넣기
                if(grid[nx][ny] < rLevel && grid[nx][ny] != 0){
                    if(s+1 < minL){         // 현재까지 가장 가까운 몬스터라면
                        minL = s+1;
                        tX = nx, tY = ny;
                    }
                    else if(s+1 == minL && (tX > nx || (tX == nx && tY > ny))){
                        // 거리는 최소로 같은데, 만약 가장 위에 존재하거나 혹은 행은 같은데 가장 왼쪽에 존재한다면
                        minL = s+1;
                        tX = nx, tY = ny;
                    }
                }
            }
        }
    }
    return make_pair(tX, tY);
}

int Simulate(){
    // 1. 탐색 전 방문배열, step 초기화
    Initialize_before_Search();

    // 2. 전투로봇의 좌표 큐에 넣기
    Push(rX, rY, 0);

    // 3. 탐색 시작
    pair<int, int> target_robot = bfs();
    if(target_robot.first == INT_MAX)
        return -1;
    // 4. 로봇 이동시키기
    int nx = target_robot.first, ny = target_robot.second;
    grid[rX][rY] = 0;       // 원래 자리 0으로
    rX = nx, rY = ny;       // 좌표 옮기고
    grid[rX][rY] = 9;       // 로봇 표시
    // 4-1. 죽인 횟수 증가시키기
    cur_killed++;
    // 4-2. 죽인 횟수가 레벨이랑 같아졌는지 확인
    if(cur_killed == rLevel){
        cur_killed = 0;
        rLevel++;
    }
    // 4-3. elapsed_time 증가
    elapsed_time += step[rX][rY];
    return 0;

}

int main() {
    // 입력받기:
    Input(); 
    
    // 시뮬레이션 진행
    while(true){
        if(IsFinish())
            break;
        int ret = Simulate();
        if(ret == -1)
            break;
    }

    // 출력하기
    cout << elapsed_time;
    
    return 0;
}