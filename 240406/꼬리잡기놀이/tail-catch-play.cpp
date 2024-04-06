#include <iostream>
#include <vector>

#define MAX_N 20
#define MAX_M 5 
using namespace std;

int n, m, k;        // n: 격자 크기, m 팀의 개수, k: 라운드 수
int grid[MAX_N][MAX_N];
int grid_for_turn[MAX_N][MAX_N];
int grid_for_team[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int team_num = -1;
vector<pair<int, int> > team[MAX_M];  // vector[i]: i팀을 구성하는 좌표
vector<int> tail_idx;     // tail[i]: i팀의 머리와 꼬리 인덱스

int score;      // 획득한 점수의 합
void Input(){   // 입력을 받는 함수
    cin >> n >> m >> k;     // n: 격자 크기, m 팀의 개수, k: 라운드 수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];      // 0: 빈칸, 1: 머리사람, 2: 나머지, 3: 꼬리사람, 4: 이동선
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y){
    for(int d=0; d<4; d++){
        int nx = x + dirs[d][0], ny = y + dirs[d][1];
        if(InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] != 0){
            visited[nx][ny] = true;
            team[team_num].push_back(make_pair(nx, ny));
            if(grid[nx][ny] == 3)
                tail_idx.push_back((int)team[team_num].size());
            dfs(nx, ny);
        }
    }
}

void DivideTeam(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                team_num++; // 팀번호 증가
                team[team_num].push_back(make_pair(i,j));
                visited[i][j] = true;
                for(int d=0; d<4; d++){
                    int nI = i + dirs[d][0], nJ = j + dirs[d][1];
                    if(InRange(nI, nJ) && !visited[nI][nJ] && grid[nI][nJ] == 2){
                        visited[nI][nJ] = true;
                        team[team_num].push_back(make_pair(nI, nJ));
                        dfs(nI, nJ);
                    }
                }
            }
        }
    }

}

void MoveAll(){
    for(int i=0; i<MAX_M; i++){
        if((int)team[i].size() == 0) continue;
        if(team[i].size() == tail_idx[i]){  // 만약 맨 마지막이 꼬리라면
            // 맨 앞을 맨뒤로 보내기
            vector<pair<int, int> > tmp;
            for(int j=1; j<(int)team[i].size(); j++){
                tmp.push_back(team[i][j]);
            }
            tmp.push_back(team[i][0]);

            team[i] = tmp;  // 이동 반영하기
        }
        else{ // 경로가 남아있다면
            pair<int, int> last_pos = team[i][(int)team[i].size()-1];
            team[i].pop_back();
            team[i].insert(team[i].begin(), last_pos);

        }
    }
}

void DrawTurnGrid(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            grid_for_turn[i][j] = 0;
            grid_for_team[i][j] = -1;
        }

    for(int i=0; i<MAX_M; i++){
        if((int)team[i].size() == 0) continue;
        for(int j=0; j<(int)team[i].size(); j++){
            int x = team[i][j].first, y = team[i][j].second;
            if(j < tail_idx[i]){
                int num = j+1;
                grid_for_turn[x][y] = num;
                grid_for_team[x][y] = i;
            }
        }
    }
}

int ThrowBall(int group_num, int idx){
    if(group_num == 0){
        for(int j=0; j<n; j++){
            if(grid_for_turn[idx][j] > 0){
                score += grid_for_turn[idx][j] * grid_for_turn[idx][j];
                return grid_for_team[idx][j];
            }
        }
    }
    else if(group_num == 1){
        for(int i=n-1; i >= 0; i--){
            if(grid_for_turn[i][idx] > 0){
                score += grid_for_turn[i][idx] * grid_for_turn[i][idx];
                return grid_for_team[i][idx];
            }
        }
    }
    else if(group_num == 2){
        for(int j=n-1; j >= 0; j--){
            if(grid_for_turn[n-1-idx][j] > 0){
                score += grid_for_turn[n-1-idx][j]*grid_for_turn[n-1-idx][j];
                return grid_for_team[n-1-idx][j];
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(grid_for_turn[i][n-1-idx] > 0){
                score += grid_for_turn[i][n-1-idx]*grid_for_turn[i][n-1-idx];
                return grid_for_team[i][n-1-idx];
            }
        }
    }
    return -1;
}

void Simulate(int round){
    // Step 1. 각 팀은 머리사람을 따라 한 칸 이동하기
    MoveAll();
    DrawTurnGrid();

    // Step 2. 각 라운드마다 공이 정해진 선을 따라 던져진다.
    int group_num = round / 4;
    int idx_in_group = round % n;
    int i = ThrowBall(group_num, idx_in_group);
    if(i == -1) return;
    // Step 3. 머리와 꼬리 바꾸기
    vector<pair<int, int> > tmp;
    for(int j = tail_idx[i]-1; j >= 0; j--){
        tmp.push_back(team[i][j]);
    }
    for(int j=(int)team[i].size()-1; j >= tail_idx[i]; j--)
        tmp.push_back(team[i][j]);

    team[i] = tmp;
    
}

int main() {
    // 입력 받기:
    Input();

    // 탐색을 통해 팀 나누기
    DivideTeam();

    // k번의 라운드 동안 시뮬레이션 진행하기
    for(int i=0; i<k; i++){
        Simulate(i);
    }
    cout << score;
    return 0;
}