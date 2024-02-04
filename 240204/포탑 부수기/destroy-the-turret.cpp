#include <iostream>
#include <queue>
#include <tuple>

#define MAX_NM 10
#define MAX_K 5000
using namespace std;
int n, m, k;                    // n,m: 격자 크기, k: 턴수
int grid[MAX_NM][MAX_NM];       // 포탑을 나타내는 격자 => 0: 부서진 포탑, 양수: 공격력
int atk_time[MAX_NM][MAX_NM];    // 각 포탑의 공격 시각
bool isRelated[MAX_NM][MAX_NM]; // 이번 턴에 공격에 연루되었는지
pair<int, int> atk;             // 공격자 좌표
pair<int, int> tgt;             // 공격 대상 좌표


queue<pair<int, int> > q;               // bfs 탐색을 위한 큐
bool visited[MAX_NM][MAX_NM];           // 레이저 공격을 시도하기 전 bfs 탐색을 위한 방문 배열
pair<int, int> from[MAX_NM][MAX_NM];    // 레이저 공격을 시도하기 전 bfs 탐색을 진행하면서 어디에서 왔는지 표기하기 위한 배열
int dirs[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};   // 우/하/상/좌 우선순위, 나머지 대각선 방향은 포탄 공격을 위함

void Input(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
}

void Choose_attacker(){         // 공격자를 찾는 함수
    int minPower = MAX_K+1, minX=0, minY=0;     // 현재 가장 작은 공격력을 가진 포탑
    for(int sum = n+m-2; sum >= 0; sum--){    // 행+열의 합이 큰 순으로 확인
        for(int j=m-1; j>=0; j--){            // 열 값이 큰 순으로 확인
            int i=sum-j;
            if(i < 0 or i >= n) continue;   // 범위 벗어나면 나가기
            if(grid[i][j] == 0) continue;   // 이미 부서진 포탑이면 넘어가기
            if(minPower > grid[i][j]){      // 공격력이 현재 최소 공격력보다 낮다면 업데이트
                minX = i, minY = j, minPower = grid[i][j];
            }
            else if(minPower == grid[i][j] && atk_time[i][j] > atk_time[minX][minY]){   // 공격력이 같지만 공격 시간이 더 최근이라면 업데이트
                minX = i, minY = j, minPower = grid[i][j];
            }
        }
    }
    atk = make_pair(minX, minY);
    //cout << minX << ' ' << minY << '\n';

}

void Choose_target(){           // 공격 대상을 찾는 함수
    int maxPower = 0, maxX=0, maxY=0;     // 현재 가장 작은 공격력을 가진 포탑
    for(int sum = 0; sum <= n+m-2; sum++){    // 행+열의 합이 작은 순으로 확인
        for(int j=0; j < m; j++){            // 열 값이 큰 순으로 확인
            int i=sum-j;
            if(i < 0 or i >= n) continue;   // 범위 벗어나면 나가기
            if(grid[i][j] == 0) continue;   // 부서진 포탑이면 넘어가기
            if(maxPower < grid[i][j]){      // 공격력이 현재 최소 공격력보다 낮다면 업데이트
                maxX = i, maxY = j, maxPower = grid[i][j];
            }
            else if(maxPower == grid[i][j] && atk_time[i][j] < atk_time[maxX][maxY]){   // 공격력이 같지만 공격 시간이 더 예전이라면 업데이트
                maxX = i, maxY = j, maxPower = grid[i][j];
            }
        }
    }
    tgt = make_pair(maxX, maxY);

}

void Initialize_visited(){
    // 방문 배열 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(){         // 레이저 공격을 위해 최단경로 탐색을 진행
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        // 네 가지 방향에 대해서 확인
        for(int d=0; d<4; d++){
            int nx = (x+dirs[d][0]+n)%n, ny = (y+dirs[d][1]+m)%m;   // 가장자리에서 넘어가는 경우까지 처리
            if(!visited[nx][ny] && grid[nx][ny] != 0){       // 방문하지 않은 경우에만
                visited[nx][ny] = true; // 방문처리
                from[nx][ny] = make_pair(x,y);  // 어디에서 왔는지 표기
                q.push(make_pair(nx,ny));       // 큐에다가 넣기
            }
        }
    }
}

void attack(int x, int y, int p){       // grid[x][y]에 p만큼의 공격을 입히기
    int cur_power = max(0, grid[x][y]-p);
    grid[x][y] = cur_power;
    isRelated[x][y] = true;
}

bool do_laser(){    // 레이저 공격 함수 
    // 1. 먼저 atk에서 tgt까지 bfs 탐색
    Initialize_visited();
    // 2. 만약 tgt까지 갈수 있다면 공격
    visited[atk.first][atk.second] = true;
    q.push(atk);
    bfs();

    // 3. 만약 공격 대상까지 도달할 수 없다면
    if(!visited[tgt.first][tgt.second])
        return false;
    // 4. 도달할 수 있다면 경로를 따라가면서 피해입히기
    // 4-1 공격 대상 먼저 공격
    isRelated[atk.first][atk.second] = true;
    int power = grid[atk.first][atk.second];
    attack(tgt.first, tgt.second, power);
    // 4-2. 이제 따라가면서 공격 입히기
    int curX = tgt.first, curY = tgt.second;

    //cout << "공격자" << atk.first << ' ' <<atk.second << '\n';
    //cout << "대상" << tgt.first << ' ' << tgt.second << '\n';
    while(true){
        // 공격자에게 도달하기 전까지
        int nx = from[curX][curY].first, ny = from[curX][curY].second;
        //cout << nx << ' ' << ny << '\n';
        if(nx == atk.first && ny == atk.second) break;      // 만약 공격자에 도달했다면 반복문 나가기
        attack(nx, ny, power/2);       // 경로에 있는 포탑은 공격자의 공격력의 절반만큼만!
        curX = nx, curY = ny;
    }
    
    return true;
}

void bombshell(){   // 포탄 공격 함수 
    // 공격 대상 먼저 공격
    isRelated[atk.first][atk.second] = true;
    int power = grid[atk.first][atk.second];
    attack(tgt.first, tgt.second, power);
    // 이제 공격 대상의 주변 8개 방향에 대해서 공격 입히기
    int x = tgt.first, y = tgt.second;
    for(int d=0; d<8; d++){
        int nx = (x+dirs[d][0]+n)%n, ny = (y+dirs[d][1]+m)%m;   // 가장자리에서 넘어가는 경우까지 처리
        //cout << nx << ' ' << ny << '\n';
        if(grid[nx][ny] != 0){       // 부서지지 않은 포탑에 대해서
            if(nx == atk.first && ny == atk.second) continue;
            //cout << nx << ' ' << ny << '\n';
            attack(nx, ny, power/2);
        }
    }


}

bool IsFinish(){    // 부서지지 않은 포탑이 1개인지 확인하기
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != 0)
                cnt++;
        }
    }
    if(cnt == 1)
        return true;
    return false;
} 
void Simulation(){
    for(int i=1; i<=k; i++){        // k번의 턴에 대해서
        // 0. 이번 턴에 공격에 관련되었는지 초기화
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                isRelated[i][j] = false;
            }
        }
        // 1. 공격자 선정
        Choose_attacker();
        // 2. 공격 대상 선정
        Choose_target();
        // 공격자에게 핸디캡 적용하기
        grid[atk.first][atk.second] += n+m;     // 공격 대상을 찾은 다음에 더해주기
        atk_time[atk.first][atk.second] = i;    // 공격대상의 공격 시간 업데트
        // 공격자
        //cout << grid[atk.first][atk.second] << '\n';
        
        //cout << "공격자와 대상" <<atk.first << ' ' << atk.second << ' ' <<tgt.first << ' ' <<tgt.second << '\n';
        // 3. 레이저 공격 시도
        if(!do_laser())
            // 4. 레이저가 안되면 포탄 공격
            bombshell();
        // 5. 포탑 정비
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!isRelated[i][j] && grid[i][j] != 0){
                    // 공격과 무관하고 0이 아니라면
                    grid[i][j]++;   // 공격력 1씩 증가
                }
            }
        }
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout <<grid[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */
        // 6. 부서지지 않은 포탑이 1개가 된다면 중지
        if(IsFinish())
            break;
    }
}


int main() {
    // 변수 입력 받기:
    Input();

    // 시뮬레이션 시작:
    Simulation();
    
    // 가장 강한 포탑 공격력 출력:
    Choose_target();
    cout << grid[tgt.first][tgt.second];
    return 0;
}