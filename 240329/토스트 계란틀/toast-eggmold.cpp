#include <iostream>
#include <queue>
#include <cmath>

#define MAX_N 50

using namespace std;
int n, L, R;
int grid[MAX_N][MAX_N];
int next_grid[MAX_N][MAX_N];

queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
bool curVisited[MAX_N][MAX_N];
int total_cnt;
int total_sum;
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool IsMoved = false;
void Input(){
    cin >> n >> L >> R;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
}

void Initialize_before_search(){
    IsMoved = false;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
}

void Initialize_cur_visited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            curVisited[i][j] = false;
}

void Push(int x, int y){
    visited[x][y] = true;
    curVisited[x][y] = true;
    q.push(make_pair(x, y));
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int prior_value){      // (x,y)로 갈 수 있는지 확인하는 함수
    // 이전 계란틀에 있는 계란의 양과 차이가 L이상 R이하일 때 갈 수 있음
    int diff = abs(grid[x][y] - prior_value);
    return InRange(x, y) && !curVisited[x][y] && (L <= diff && diff <= R); 
}

void bfs(){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        //cout << x << ' ' << y << '\n';
        for(int d=0; d<4; d++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(CanGo(nx, ny, grid[x][y])){
                Push(nx, ny);
                total_cnt++;
                total_sum += grid[nx][ny];
            }
        }
    }
}

void MakeNextEgg(){
    if(total_cnt > 1)   
        IsMoved = true;
    int val = total_sum / total_cnt;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(curVisited[i][j])
                next_grid[i][j] = val;
        }
    }

}

void Simulate(){        // 계란 이동 시뮬레이션 함수
    // 1. 먼저 이동 전 움직인 여부 초기화하기
    Initialize_before_search();

    // 2. 매 칸마다 확인하면서 탐색 진행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;     // 만약 이미 탐색을 진행한 곳이라면 넘어가기
            Initialize_cur_visited();
            Push(i, j);
            total_cnt = 1;
            total_sum = grid[i][j];
            bfs();
            //cout << '\n';
            MakeNextEgg();

        }
    }

    // 3. next_grid에서 grid로 옮기기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = next_grid[i][j];
            //cout << grid[i][j] << ' ';
        }
        //cout << '\n';
    }
    //cout << '\n';
}

int main() {
    // 입력 받기:
    Input();

    // 계란 이동 시작하기
    int cnt = 0;
    while(true){
        Simulate();
        if(IsMoved)
            cnt++;
        else
            break;
        //cout << "현재 cnt: " << cnt << '\n';
    }
    cout << cnt;
    return 0;
}