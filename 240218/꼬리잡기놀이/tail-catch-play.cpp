#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 20
#define MAX_M 5

using namespace std;
int n, m, k;                // n: 격자 크기, m: 팀 개수, k: 라운드 수
int grid[MAX_N][MAX_N];     // 격자 정보
int visited[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int team_number = -1;
int total_score;


int team[MAX_N][MAX_N];     // 각 팀의 정보 
pair<int, int> team_head[MAX_N];    // 각 팀의 머리 좌표
pair<int, int> team_tail[MAX_M];    // 각 팀의 꼬리 좌표
int cur_dist, loc_dist;

void Input(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
}

void Initialize(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;  // 방문 배열 초기화
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x, y) && !visited[x][y] && grid[x][y] != 0; 
}

void dfs(int x, int y){
    for(int d=0; d<4; d++){
        // (x,y)와 연결되어 있는 팀 확인
        int nx = x+dirs[d][0], ny = y+dirs[d][1];
        if(CanGo(nx, ny)){
            if(grid[nx][ny] == 3)
                team_tail[team_number] = make_pair(nx, ny);
            visited[nx][ny] = true;
            team[nx][ny] = team_number;
            dfs(nx, ny);
        }
    }
}

void MoveTeam(){
    for(int i=0; i<m; i++){
        int hX = team_head[i].first, hY = team_head[i].second;
        int tX = team_tail[i].first, tY = team_tail[i].second;

        // 2-1. 먼저 꼬리 이동시키기
        for(int d=0; d<4; d++){
            int nx = tX+dirs[d][0], ny = tY+dirs[d][1];

            if(InRange(nx, ny) && grid[nx][ny] == 2 && team[nx][ny] == i){
                // 범위 안에 있고, 같은 팀의 몸통이라면
                grid[nx][ny] = 3;                   // 그 다음 위치를 꼬리로
                grid[tX][tY] = 4;                   // 원래 위치를 이동선으로
                team_tail[i] = make_pair(nx,ny);    // 꼬리 위치에 넣기
                break; 
            }
        }

        // 2-2. 그 다음 머리 이동시키기
        for(int d=0; d<4; d++){
            int nx = hX+dirs[d][0], ny = hY+dirs[d][1];
            if(InRange(nx, ny) && grid[nx][ny] == 4 && team[nx][ny] == i){
                // 범위 안에 있고, 같은 팀의 이동 선상이라면
                grid[nx][ny] = 1;                   // 그 다음 위치를 머리로
                grid[hX][hY] = 2;                   // 원래 위치를 몸통으로
                team_head[i] = make_pair(nx,ny);    // 머리 위치 업데이트하기
                break;
            }
        }
    }


}

bool IsPerson(int x){
    return x == 3 || x == 2 || x == 1;
}

void Swich_head_and_tail(int team_num){
    int hX = team_head[team_num].first, hY = team_head[team_num].second;
    int tX = team_tail[team_num].first, tY = team_tail[team_num].second;
    grid[hX][hY] = 3;   // 머리를 꼬리로
    team_head[team_num] = make_pair(tX, tY);
    grid[tX][tY] = 1;   // 꼬리를 머리로
    team_tail[team_num] = make_pair(hX, hY);
    
}

queue<tuple<int, int, int> > q;

void find_dist(){
    while(!q.empty()){
        int x, y, dist;
        tie(x, y, dist) = q.front();
        q.pop();
        if(grid[x][y] == 1){
            loc_dist = dist;
            return;
        }
        for(int d=0; d<4; d++){
            int nx = x+dirs[d][0], ny = y+dirs[d][1];
            if(InRange(nx, ny) && !visited[nx][ny] && (grid[nx][ny] != 0 && grid[nx][ny] != 4) && team[x][y] == team[nx][ny]){
                visited[nx][ny] = true;
                //cout << "이제 여기 탐색: " << nx << ' ' << ny << ' ' << cur_dist << '\n';
                q.push(make_tuple(nx, ny, dist+1));
            }
        }
    }
}

/*
void find_dist_from_head(int x, int y){
    for(int d=0; d<4; d++){
        int nx = x + dirs[d][0], ny = y + dirs[d][1];
        //    return InRange(x, y) && !visited[x][y] && grid[x][y] != 0; 
        // 범위 안에 있고, 방문하지 않았으면서 team이 같으면
        if(CanGo(nx,ny) && (grid[nx][ny] == 2 || grid[nx][ny] == 1) && team[x][y] == team[nx][ny]){
            //cout << "다음 위치: " << nx << ' ' << ny << '\n';
            visited[nx][ny] = true;
            cur_dist++;
            if(grid[nx][ny] == 1)
                loc_dist = cur_dist;
            find_dist_from_head(nx, ny);
        }
    }
}
*/


void UpdateScore(int x, int y){     // 공과 최초로 만난 (x,y) 위치의 사람이 들어간 팀의 점수를 업데이트하기
    // (x,y) 위치의 사람으로부터 머리까지 몇번 가야하는지 탐색하기
    cur_dist = 1, loc_dist = 1;
    Initialize();
    while(!q.empty())   q.pop();
    visited[x][y] = true;
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout << "************\n";
    */
    q.push(make_tuple(x, y, cur_dist));
    
    
    //cout << "업데이트할 위치: " << x << ' ' << y << ' ' << cur_dist << '\n';
    find_dist();
    //find_dist_from_head(x, y);
    //cout << "위치:" << loc_dist << '\n';
    total_score += loc_dist * loc_dist;

    // 머리와 꼬리 바꾸기
    Swich_head_and_tail(team[x][y]);

}

void ThrowBall(int group_num, int idx){
    if(group_num == 0){
        // 위에서부터 idx번
        for(int j=0; j<n; j++){
            if(IsPerson(grid[idx][j])){
                UpdateScore(idx, j);
                break;
            }
        }
    }
    else if(group_num == 1){
        for(int i=n-1; i>=0; i--){
            if(IsPerson(grid[i][idx])){
                UpdateScore(i, idx);
                break;
            }
        }
    }
    else if(group_num == 2){
        for(int j=n-1; j>=0; j--){
            if(IsPerson(grid[n-1-idx][j])){
                UpdateScore(n-1-idx, j);
                break;
            }
        }
    }
    else{   // group_num == 3
        for(int i=0; i<n;i++){
            if(IsPerson(grid[i][n-1-idx])){
                UpdateScore(i, n-1-idx);
                break;
            }
        }
    }
}



void Simulate(int round){        // 시뮬레이션을 진행하는 함수
    // 0. 탐색 전 초기화
    Initialize();



    // 2. 각 팀 한 칸씩 이동하기
    //cout << "round: "<<round << "번째 먼저 이동후\n";
    MoveTeam();

    // 3. 공이 던져지고, 해당 선에 최초로 만나는 사람 점수 추가하기
    // round에 따라 공 던지기
    int group_num = (round / n)%4;
    int start_idx = round % n;
    //cout << "던질 볼의 위치 : " << group_num << ' ' << start_idx << '\n';
    ThrowBall(group_num, start_idx);



}

int main() {
    // 입력 받기:
    Input();    
    // 1. 연결되어 있는 팀의 머리와 꼬리 찾기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            team[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                team_number++;
                // 1-1. 방문하지 않은 머리 찾기
                team_head[team_number] = make_pair(i,j);
                visited[i][j] = true;   // 방문 표시
                team[i][j] = team_number;
                // 1-2. 연결되어 있는 꼬리 찾기 위해 탐색 진행
                dfs(i,j);
            }
        }
    }

    // k번의 턴에 대해 시뮬레이션 진행
    for(int cur_turn=0; cur_turn < k; cur_turn++){

        Simulate(cur_turn);
        /*
        cout << "현재 점수: "<< total_score << '\n';
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << grid[i][j] << ' ';
            }
            cout << '\n';
        }
*/
    }

    // 출력:
    cout << total_score;
    return 0;
}