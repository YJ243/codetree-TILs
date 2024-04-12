#include <iostream>
#include <queue>

#define MAX_N 20

using namespace std;

int n, m, k;    // n: 격자 크기, m: 벽의 개수, k: 사무실 시원함 정도
int grid[MAX_N][MAX_N];     // 격자 정보
int walls[MAX_N][MAX_N];    // 벽 표시하기
int room_cnt;
vector<pair<int, int> > aircond;    // 에어컨 위치
int dirs[4][3][2] = {   // 에어컨에서 바람이 나와서 시원하게 만드는 위치, 오위왼아 순서
    {{0,-1},{-1,-1},{1,-1}},
    {{-1,0},{-1,-1},{-1,1}},
    {{0,1},{-1,1},{1,1}},
    {{1,0},{1,-1},{1,1}}
};
int checkdirs[4][4][2] = {  // 대각선 방향 확인하기
    {{-1,0},{0,-1},{1,0},{0,-1}},
    {{0,-1},{-1,0},{0,1},{-1,0}},
    {{-1,0},{0,1},{1,0},{0,1}},
    {{0,-1},{1,0},{0,1},{1,0}}
};
// bfs 탐색을 위한 자료구조
queue<pair<int, int> > q;   // 탐색을 위한 큐
bool visited[MAX_N][MAX_N]; // 방문 확인을 위한 배열
int step[MAX_N][MAX_N];     // 시원함이 퍼져나가는 정도 
int cool[MAX_N][MAX_N];     // 시원함 정도
int tempCool[MAX_N][MAX_N];
void Input(){   // 입력을 받는 함수
    cin >> n >> m >> k; // n: 격자 크기, m: 벽의 개수, k: 사무실 시원함 정도
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];  // 격자 입력받기
            if(grid[i][j] == 1)
                room_cnt++;
            if(grid[i][j] > 1)
                aircond.push_back(make_pair(i, j));
        }
    int wall_idx = 0;
    for(int i=0; i<m; i++){
        int x, y, s;
        cin >> x >> y >> s;
        x--; y--;
        if(s == 0){ // (x, y) 바로 위에 벽
            int val = 0;
            if(walls[x][y] > 0 || walls[x-1][y] > 0)
                val = max(walls[x][y], walls[x-1][y]);
            else if(walls[x][y] == 0 && walls[x-1][y] == 0)
                val = ++wall_idx;
            walls[x][y] = val;
            if(0 <= x-1 && x-1 < n)
                walls[x-1][y] = val;
        }       
        else{   // (x, y) 바로 왼쪽에 벽
            int val = 0;
            if(walls[x][y] > 0 || walls[x][y-1] > 0)
                val = max(walls[x][y], walls[x][y-1]);
            else if(walls[x][y] == 0 && walls[x][y-1] == 0)
                val = ++wall_idx;
            walls[x][y] = val;
            if(0 <= y-1 && y-1 < n)
                walls[x][y-1] = val;
        }
    }
}

bool IsFinish(){    // 끝났는지 확인하는 함수
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1 && cool[i][j] >= k)
                cnt++;
        }
    }
    if(cnt == room_cnt)
        return true;
    return false;
}

void Initialize_visited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
            step[i][j] = 0;
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int nx, int ny, int s, int d){
    // 범위 안에 있고, 방문하지 않았고, 벽이 없으면
    // 범위 안에 없거나 방문했다면 그 곳으로는 갈 수 없
    if(!InRange(nx, ny) || visited[nx][ny])
        return false;
    bool ret = true;
    if(d == 0){
        if(walls[x][y] >0 && walls[x][y] == walls[nx][ny]){
            ret = false;
        }
    }
    else if(d == 1){
        if((walls[x][y] >0 && walls[x+checkdirs[s][0][0]][y+checkdirs[s][0][1]] == walls[x][y]) ||
        (walls[x+checkdirs[s][0][0]][y+checkdirs[s][0][1]] >0 && walls[nx][ny] == walls[x+checkdirs[s][0][0]][y+checkdirs[s][0][1]]))
            ret = false;
    }
    else{
        // (x,y) && (x + checkdirs[s][2][0], y + checkdirs[s][2][1])
        if((walls[x][y] > 0 && walls[x+checkdirs[s][2][0]][y+checkdirs[s][2][1]] == walls[x][y]) ||
        (walls[x+checkdirs[s][2][0]][y+checkdirs[s][2][1]] > 0 && walls[nx][ny] == walls[x+checkdirs[s][2][0]][y+checkdirs[s][2][1]]))
            ret = false;
    }
    return ret;
}

void bfs(int s){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        for(int d=0; d<3; d++){
            int nx = x + dirs[s][d][0], ny = y + dirs[s][d][1];
            ////cout<<nx << ' ' << ny << '\n';
            if(CanGo(x, y, nx, ny,s, d) && step[x][y] >= 1 && step[x][y] > 0){
                //cout << "갈 수 있음 " << nx << ' ' << ny << '\n';
                visited[nx][ny] = true;         // 방문 표시
                step[nx][ny] = step[x][y]-1;    // 시원함 정도 1 줄이기
                q.push(make_pair(nx, ny));      // 큐에다가 넣기
            }
        }
    }
}

void BlowWind(int x, int y, int s){
    // 탐색 전 초기화하기
    Initialize_visited();
    int nx = x + dirs[s][0][0], ny = y + dirs[s][0][1];
    //cout << x << ' ' << y << ' ' << s << ' ' << nx << ' ' << ny << '\n';
    visited[nx][ny] = true;
    step[nx][ny] = 5;
    q.push(make_pair(nx, ny));
    bfs(s);
}

void MixAir(int x, int y){  // (x, y)에서 공기가 이동할 수 있다면 이동시키기
    int sdirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    
    for(int d=0; d<4; d++){
        int nx = x + sdirs[d][0], ny = y + sdirs[d][1];
        if(!InRange(nx, ny)) continue;
        if(walls[x][y] > 0 && walls[nx][ny] == walls[x][y]) continue;
        if(cool[x][y] > cool[nx][ny]){
            //cout << x << ' ' << y << ' ' <<"에서 " << nx << ' ' << ny << "로 감" << ' ' << abs(cool[x][y] - cool[nx][ny]) / 4<<'\n';
            tempCool[nx][ny] += abs(cool[x][y] - cool[nx][ny]) / 4;
            tempCool[x][y] -= abs(cool[x][y] - cool[nx][ny]) / 4;
        }
    }

}

void Simulate(){    // 시뮬레이션을 진행하는 함수
    // Step 1. 에어컨의 바람이 나와서 공기를 시원하게 한다.
    for(int i=0; i<(int)aircond.size(); i++){
        int x, y, s;
        x = aircond[i].first, y = aircond[i].second;
        s = grid[x][y];     // 에어컨 방향 번호, 2: 왼, 3: 위, 4:오, 5: 아
        BlowWind(x, y, s-2);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cool[i][j] += step[i][j];
    }

    // Step 2. 시원한 공기들이 섞이기 시작한다.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tempCool[i][j] = cool[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            MixAir(i, j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cool[i][j] = tempCool[i][j];
            //cout << cool[i][j] << ' ';
        }
        //cout << '\n';
    }
    
    // Step 3. 외벽에 있는 칸에 대해서 시원함이 1씩 감소한다.
    for(int j=0; j<n; j++){
        cool[0][j] = max(cool[0][j]-1, 0);
        cool[n-1][j] = max(cool[n-1][j]-1, 0);
    }
    for(int i=1; i<=n-2; i++){
        cool[i][0] = max(cool[i][0]-1, 0);
        cool[i][n-1] = max(cool[i][n-1]-1, 0);
    }

}

int main(){
    // 입력 받기:
    Input();
    
    // 시뮬레이션 진행하기
    int elapsed_time = 0;
    while(true){
        if(IsFinish() || elapsed_time > 100)
            break;
        elapsed_time++;
        Simulate();
    }
    
    // 모든 사무실의 시원함 정도가 k 이상이 되는 최초의 시간 출력
    if(elapsed_time > 100)
        elapsed_time = -1;
    cout << elapsed_time;       
    return 0;
}