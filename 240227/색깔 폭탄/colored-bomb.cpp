#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

#define MAX_N 20

using namespace std;

int grid[MAX_N][MAX_N];     // -1: 검정 돌, 0: 빨간 폭탄, 1~m: 다른 색
int temp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

queue<pair<int, int> > q;
vector<pair<int, int> > red_loc;
tuple<int, int, int, int> target_bundle;       // (개수, -빨강 개수, 기준점의 행, -기준점의 열)
int curr_cnt;       // 현재 묶음에 있는 폭탄 개수
int curr_red_cnt;
int n, m;
int total_score;

void Input(){
    cin >> n >> m;      // n: 격자 크기, m: 빨강 이외 서로 다른 폭탄 종류
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 0)
                red_loc.push_back(make_pair(i,j));
        }
}

void Initialized_visited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGoFirst(int x, int y, int val){         // 제일 먼저 탐색하면서 갈 수 있는지 확인하는 함수
    return InRange(x, y) && !visited[x][y] && grid[x][y] == val; 
}

pair<int, int> bfs(int target_num){ 
    pair<int, int> std_point = make_pair(-1,MAX_N);     // 기준점 좌표
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        // 기준점인지 계속 확인
        if(std_point.first < curr.first || (std_point.first == curr.first && std_point.second > curr.second))
            std_point = make_pair(curr.first, curr.second);
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            if(CanGoFirst(nx, ny, target_num)){      // 만약 갈 수 있다면
                visited[nx][ny] = true;
                curr_cnt++;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return std_point;
}

bool CanGoSecond(int x, int y, int val){    // 폭탄을 지우기 위해서 탐색이 가능한지 확인하는 함수
    // 범위 안에 있고, 아직 방문하지 않았으며, val과 같은 색깔이거나 빨간색이면 이동 가능
    return InRange(x, y) && !visited[x][y] && (grid[x][y] == val || grid[x][y] == 0); 
}

pair<int, int> bfsRedPlus(int target_num){ 
    pair<int, int> std_point = make_pair(-1,MAX_N);     // 기준점 좌표
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        //cout << curr.first << ' ' << curr.second << '\n';
        // 기준점인지 계속 확인
        if(std_point.first < curr.first || (std_point.first == curr.first && std_point.second > curr.second))
            std_point = make_pair(curr.first, curr.second);
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            //cout << "확인하는 좌표: " << nx << ' ' << ny << '\n';
            if(CanGoSecond(nx, ny, target_num)){      // 만약 갈 수 있다면
                visited[nx][ny] = true;
                curr_cnt++;
                q.push(make_pair(nx, ny));
                if(grid[nx][ny] == 0)
                    curr_red_cnt++;
            }
        }
    }
    return std_point;
}


void delete_bomb(int color_num){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        if(grid[curr.first][curr.second] == 0){
            for(int k=0; k<(int)red_loc.size(); k++){
                if(red_loc[k].first == curr.first && red_loc[k].second == curr.second){
                    red_loc.erase(red_loc.begin() + k);
                    break;
                }
            }
        } 
        grid[curr.first][curr.second] = -10;
        
        //cout << curr.first << ' ' << curr.second << ' ' << color_num << "없앰"<<'\n';
        for(int d=0; d<4; d++){
            int nx = curr.first + dirs[d][0], ny = curr.second + dirs[d][1];
            if(CanGoSecond(nx, ny, color_num)){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

void Do_Gravity(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = -10;
        }
    }

    for(int j=0; j<n; j++){
        // j열을 차례대로 보면서 중력 작용시키기
        vector<int> a;
        for(int i=n-1; i >= 0; i--){
            if(grid[i][j] >= 0){
                // 만약 폭탄이 있다면
                a.push_back(grid[i][j]);
            }
            else if(grid[i][j] == -1){
                // 만약 돌멩이가 있다면
                int empty_cnt = (n-1-i) - a.size();

                while(empty_cnt){
                    a.push_back(-10);
                    empty_cnt--;
                }
                a.push_back(-1);
            }
        }

        int idx = n-1;
        for(int i=0; i<(int)a.size(); i++){
            temp[idx--][j] = a[i];
        }

    }
    // 다시 temp를 grid에다가 넣기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = temp[i][j];
        }

    }

}

void Rotate_CounterClockwise(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[n-1-j][i] = grid[i][j];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = temp[i][j];
}

void FindSameColorBomb(){
    Initialized_visited();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] > 0 && !visited[i][j]){       // 만약 색깔 폭탄이라면
                visited[i][j] = true;
                curr_cnt = 1;                           // 현재 묶음에 들어있는 개수 1로 초기화
                q.push(make_pair(i,j));                 // 큐에다가 넣기
                pair<int, int> std_point = bfs(grid[i][j]);     // 해당 묶음 탐색하며 기준점 찾기

                tuple<int, int, int, int> curr_bundle = make_tuple(curr_cnt, 0, std_point.first, -std_point.second);
                if(target_bundle < curr_bundle)
                    target_bundle = curr_bundle;
            }
        }
    }
}

bool Simulate(){
    // 0. target_bundle 초기화하기
    target_bundle = make_tuple(-1, MAX_N*MAX_N, -1, MAX_N);
    // 1. 우선순위가 가장 높은 폭탄 묶음 찾기
    // 1.1 먼저 같은색 끼리만 만들어지는 폭탄 묶음 찾기
    FindSameColorBomb();

    // 1.2 빨강과 연결된 묶음 찾기
    Initialized_visited();
    int maxRedIdx, maxDirIdx;
    //cout << red_loc.size() << '\n';
    for(int i=0; i<(int)red_loc.size(); i++){
        int r = red_loc[i].first, c = red_loc[i].second;
        //cout << r << ' ' << c << "빨간좌표" << '\n';
        // 현재 보고 있는 빨강과 연결된 폭탄 묶음 확인하기
        for(int d=0; d<4; d++){
            int sr = r + dirs[d][0], sc = c + dirs[d][1];
            if(InRange(sr, sc) && !visited[sr][sc] && grid[sr][sc] > 0){
                // 빨간색과 연결되어 있으면서, 방문하지 않은 폭탄이라면
                curr_cnt = 2;
                curr_red_cnt = 1;
                q.push(make_pair(sr,sc));
                q.push(make_pair(r,c));
                visited[sr][sc] = true;
                visited[r][c] = true;
                pair<int, int> std_point = bfsRedPlus(grid[sr][sc]);
                tuple<int, int, int, int> curr_bundle = make_tuple(curr_cnt, -curr_red_cnt, std_point.first, -std_point.second);
                //cout << sr << ' ' << sc << "에서 시작한 " << grid[sr][sc] << "와 같은 색을 가진 묶음에서 ";
                //cout << "개수는 "<<curr_cnt<<"이고, std_point는 " << std_point.first << ' ' << std_point.second << "이고, red cnt는" << curr_red_cnt<<"\n";
                
                if(target_bundle < curr_bundle){
                    target_bundle = curr_bundle;
                    maxRedIdx = i;
                    maxDirIdx = d;
                }
            
                // 이제 모든 빨간색을 false로 바꿔주어야 한다.
                for(int j=0; j<(int)red_loc.size(); j++){
                    visited[red_loc[j].first][red_loc[j].second] = false;
                }
            }
        }
    }

    // 2. 선택한 묶음 내의 폭탄 모두 제거 & 점수 업데이트 하기
    int cnt, redCnt, r, c;
    tie(cnt, redCnt, r, c) = target_bundle;
    //cout << cnt << ' ' << redCnt << ' ' << r << ' ' << c << '\n';
    if(cnt <= 1){
        return true;
    }
    c *= -1;
    redCnt *= -1;
    //cout << maxDirIdx << ' ' << maxRedIdx << '\n';
    //cout << red_loc.size() << '\n';
    Initialized_visited();
    if(redCnt > 0){
    // 다시 target_bundle의 (r,c)를 기준으로 탐색 진행하면서 폭탄 삭제하기
        int cx = red_loc[maxRedIdx].first, cy = red_loc[maxRedIdx].second;
        int nx = cx + dirs[maxDirIdx][0], ny = cy + dirs[maxDirIdx][1];
        visited[cx][cy] = true;
        visited[nx][ny] = true;
        int start_num = grid[nx][ny];
        q.push(make_pair(cx,cy));
        q.push(make_pair(nx,ny));

        delete_bomb(start_num);
    }
    else if(redCnt == 0){
        visited[r][c] = true;
        q.push(make_pair(r,c));

        delete_bomb(grid[r][c]);
    }

    total_score += cnt*cnt;

    // 3. 해당 격자에 대해서 중력 작용하기
    Do_Gravity();

    // 4. 반시계 방향으로 90도 회전하기
    Rotate_CounterClockwise();

    // 5. 다시 중력 작용하기
    Do_Gravity();

    red_loc.clear();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0)
                red_loc.push_back(make_pair(i,j));
        }
    }
    return false;
}

int main() {
    // 입력 받기:
    Input();
    
    // 더이상 폭탄 묶음이 없을 때까지 시뮬레이션 진행
    int turn = 0;
    while(true){
        bool IsFinished = Simulate();
        if(IsFinished)
            break;

    }

    // 최종 점수 출력하기
    cout << total_score;
    return 0;
}