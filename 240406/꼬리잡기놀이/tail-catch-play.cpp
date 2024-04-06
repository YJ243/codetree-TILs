#include <iostream>
#include <vector>

#define MAX_N 20
#define MAX_M 5 
using namespace std;

int n, m, k;                        // n: 격자 크기, m 팀의 개수, k: 라운드 수
int grid[MAX_N][MAX_N];             // 문제에서 주어진 격자 정보, 0: 빈칸 / 1: 머리 / 2: 나머지 / 3: 꼬리 / 4: 이동 선
int grid_for_turn[MAX_N][MAX_N];    // 머리를 1로 시작하여 꼬리까지 1씩 증가하여 표시
int grid_for_team[MAX_N][MAX_N];    // 각 팀의 이동선에 번호 표시
bool visited[MAX_N][MAX_N];         // 방문 여부

int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};   // 방향
int team_num = -1;                              // 팀 번호(0번부터 시작)
vector<pair<int, int> > team[MAX_M];            // vector[i]: i팀을 구성하는 전체 좌표
vector<int> tail_idx;                           // tail[i]: i팀의 꼬리 인덱스

int score;                                      // 획득한 점수의 합

void Input(){   // 입력을 받는 함수
    cin >> n >> m >> k;     // n: 격자 크기, m 팀의 개수, k: 라운드 수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];      // 0: 빈칸, 1: 머리사람, 2: 나머지, 3: 꼬리사람, 4: 이동선
        }
    }
}

bool InRange(int x, int y){     // 범위 안에 있는지 확인하는 함수 
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y){         // (x, y)와 이어지는 팀 탐색을 위한 함수
    for(int d=0; d<4; d++){
        int nx = x + dirs[d][0], ny = y + dirs[d][1];
        if(InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] != 0){
            visited[nx][ny] = true;
            team[team_num].push_back(make_pair(nx, ny));
            if(grid[nx][ny] == 3)   // 꼬리는 따로 몇번째인지 저장
                tail_idx.push_back((int)team[team_num].size());
            dfs(nx, ny);
        }
    }
}

void DivideTeam(){      // 문제에서 주어진 격자의 팀을 구분하는 함수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){    // 만약 머리를 만나면
                team_num++;         // 팀번호 증가
                team[team_num].push_back(make_pair(i,j));   // 머리 집어넣기
                visited[i][j] = true; // 방문 표시
                for(int d=0; d<4; d++){
                    int nI = i + dirs[d][0], nJ = j + dirs[d][1];
                    // 머리에서 붙어있는 몸통을 찾아서, 그 몸통에서 탐색을 진행
                    if(InRange(nI, nJ) && !visited[nI][nJ] && grid[nI][nJ] == 2){
                        visited[nI][nJ] = true;     // 방문 표시
                        team[team_num].push_back(make_pair(nI, nJ));    // 몸통 집어넣기
                        dfs(nI, nJ);    // 탐색 진
                    }
                }
            }
        }
    }
}

void MoveAll(){         // m명의 팀을 한칸씩 움직이는 함수 
    for(int i=0; i<m; i++){
        pair<int, int> last_pos = team[i][(int)team[i].size()-1];
        team[i].pop_back();     // 맨 마지막을 빼서
        team[i].insert(team[i].begin(), last_pos);  // 맨 앞에 넣으면 한 칸씩 이동하게 됨
    }
}

void DrawTurnGrid(){    // 머리 1번부터 시작해서 순서를 적어놓는 함수
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            grid_for_turn[i][j] = 0;    
            grid_for_team[i][j] = -1;
        }

    for(int i=0; i<m; i++){
        for(int j=0; j<(int)team[i].size(); j++){
            int x = team[i][j].first, y = team[i][j].second;
            if(j < tail_idx[i]){    // 꼬리까지는 번호 적기
                int num = j+1;
                grid_for_turn[x][y] = num;  // 몇 번째인지
                grid_for_team[x][y] = i;    // 어떤 그룹인지
            }
        }
    }
}

int ThrowBall(int group_num, int idx){      // group_num의 idx번째에서 공을 던지는 함수
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
    int group_num = (round / n) % 4;
    int idx_in_group = round % n;

    int i = ThrowBall(group_num, idx_in_group); // 공을 맞은 그룹 번호 찾기
    if(i == -1) return;     // 공을 맞은게 없으면 바로 리턴하기

    // Step 3. 머리와 꼬리 바꾸기
    vector<pair<int, int> > tmp;
    for(int j = tail_idx[i]-1; j >= 0; j--){    // 꼬리부터 머리까지 거꾸로 넣기
        tmp.push_back(team[i][j]);
    }
    for(int j=(int)team[i].size()-1; j >= tail_idx[i]; j--) // 제일 끝에서 이전의 꼬리 이후까지 거꾸로 넣기
        tmp.push_back(team[i][j]);

    team[i] = tmp;      // tmp를 그룹 정보에 넣기    
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