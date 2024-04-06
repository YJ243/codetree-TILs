#include <iostream>
#define MAX_N 20

using namespace std;


int n, m, k, c;     // n: 격자 크기, m: 박멸이 진행되는 년 수, k: 제초제 확산 범위, c: 제초제가 남아있는 년수
int grid[MAX_N][MAX_N]; // -1: 벽, 0: 빈칸, 양수: 각 칸의 나무 수
int herbicide[MAX_N][MAX_N];    // 제초제가 뿌려져서 해당 시간까지는 남아있음
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int cdirs[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};   // 네 개의 대각선 방향
int ans;        // 총 박멸한 나무의 그루 수 

void Input(){   // 입력을 받는 함수
    cin >> n >> m >> k >> c;    // n: 격자 크기, m: 박멸이 진행되는 년 수, k: 제초제 확산 범위, c: 제초제가 남아있는 년수
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool ExistTree(int x, int y){
    return InRange(x, y) && grid[x][y] > 0;
}

void GrowTree(){    // 나무를 성장시키는 함수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] > 0){
                int cnt = 0;
                for(int d=0; d<4; d++){
                    // 인접한 네 개의 칸 중 나무가 있는 칸의 수 세기
                    int nx = i + dirs[d][0], ny = j + dirs[d][1];
                    if(ExistTree(nx, ny)){
                        cnt++;
                    }
                }
                grid[i][j] += cnt;      // 해당 개수만큼 나무 성장
            }
        }
    }
}

void SpreadTree(int year_num){  // 나무를 번식시키는 함수
    int temp[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = grid[i][j];    // 일단 temp에 복사해두기
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] > 0){
                int cnt = 0;
                for(int d=0; d<4; d++){
                    // 인접한 네 개의 칸 중 빈 칸 찾기
                    int nx = i + dirs[d][0], ny = j + dirs[d][1];
                    if(InRange(nx, ny) && grid[nx][ny] == 0 && herbicide[nx][ny] < year_num){
                        cnt++;
                    }
                }
                for(int d=0; d<4; d++){
                    int nx = i + dirs[d][0], ny = j + dirs[d][1];
                    if(InRange(nx, ny) && grid[nx][ny] == 0 && herbicide[nx][ny] < year_num){
                        // 각 칸의 나무 그루 수에서 총 번식이 가능한 칸의 개수만큼 나누어진 그루 수만큼 번식이 됨
                        temp[nx][ny] += grid[i][j] / cnt;   // 더해주어야 인접한 여러곳에서 번식이 더해짐 
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = temp[i][j];
        }
    }
}

int FindDeadTreeCnt(int x, int y){
    int ret = grid[x][y];   // 현재 칸 더하기

    for(int d=0; d<4; d++){
        for(int i=1; i<=k; i++){
            int nx = x + cdirs[d][0]*i, ny = y + cdirs[d][1]*i;
            if(InRange(nx, ny) && grid[nx][ny] == -1)
                break;
            if(ExistTree(nx, ny))
                ret += grid[nx][ny];
        }
    }
    return ret;
}

pair<int, int> FindHerbicideSpot(){
    int max_dead = -1, minI = n, minJ = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] > 0){ // 만약 나무가 있다면
                int to_be_dead = FindDeadTreeCnt(i, j);
                if(max_dead < to_be_dead)
                    max_dead = to_be_dead, minI = i, minJ = j;
            }
        }
    }
    return make_pair(minI, minJ);
}
void SprayHerbicide(int year_num){
    int delete_cnt = 0;
    // 1. 제초제가 뿌려질 위치 찾기
    pair<int, int> target = FindHerbicideSpot();
    int x = target.first, y = target.second;

    // 2. 제초제 뿌리기
    herbicide[x][y] = year_num+c;
    delete_cnt += grid[x][y];
    grid[x][y] = 0;
    
    for(int d=0; d<4; d++){
        for(int i=1; i<=k; i++){
            int nx = x + cdirs[d][0]*i, ny = y + cdirs[d][1]*i;
            if(InRange(nx, ny) && (grid[nx][ny] == -1 || grid[nx][ny] == 0)){
                // 해당칸까지는 제초제 뿌리기
                herbicide[nx][ny] = year_num+c;
                grid[nx][ny] = 0;
                break;
            }
            if(ExistTree(nx, ny)){
                herbicide[nx][ny] = year_num + c;
                delete_cnt += grid[nx][ny];
                grid[nx][ny] = 0;
            }
        }
    }
    ans += delete_cnt;
    
}

void Simulate(int year_num){
    // Step 1. 인접한 네 개의 칸 중 나무가 있는 칸의 수만큼 나무가 성장한다.
    GrowTree();

    // Step 2. 번식 진행
    SpreadTree(year_num);

    // Step 3. 제초제 뿌리기
    SprayHerbicide(year_num);
}

int main() {
    // 입력 받기:
    Input();    

    // m년에 걸쳐 시뮬레이션 진행하기
    for(int i=1; i<=m; i++){
        Simulate(i);
    }
    cout << ans;
    return 0;
}