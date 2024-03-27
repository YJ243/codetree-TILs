#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 4
#define MAX_DIR 8
#define NOT_EXIST make_pair(-1, -1)

using namespace std;

int n = MAX_N;
pair<int, int> grid[MAX_N][MAX_N];
int sx, sy;     // 술래(seeker)의 위치
int sd;         // 술래의 방향
int dirs[MAX_DIR][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
int ans;
int curr;
void Input(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num, dir;
            cin >> num >> dir;
            grid[i][j] = make_pair(num, dir-1);
        }
    }

}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool IsFinish(){        // 술래가 이동할 수 있는 곳에 도둑말이 더이상 존재하지 않는지 확인하기
    bool IsExist = false;
    for(int i=1; i<n; i++){
        int nx = sx + dirs[sd][0], ny = sy + dirs[sd][1];
        if(InRange(nx, ny) && grid[nx][ny] != NOT_EXIST){
            IsExist = true;
        }
    }
    return !IsExist;
}

tuple<int, int, int, int> CatchTheif(int x, int y){
    int priorX = sx, priorY = sy, priorD = sd;
    int priorS = curr;
    curr += grid[x][y].first;        // 점수 증가
    sd = grid[x][y].second;
    sx = x, sy = y;                 // 술래 위치 바꿔주기
    grid[x][y] = NOT_EXIST;         // 해당 칸에 아무도 존재하지 않는다고 표시
    return make_tuple(priorX, priorY, priorD, priorS);
}

void MoveThief(){
    for(int num=1; num<=16; num++){
        bool IsMoved = false, cannotMovable = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int curN = grid[i][j].first, curD = grid[i][j].second;
                if(curN == num){
                    //cout << curN << ' ' << i << ' ' << j << ' ' << curD << '\n';
                    // 이제 (i,j)에 있는 도둑 옮기기
                    int nx = i + dirs[curD][0], ny = j + dirs[curD][1];
                    int startX = nx, startY = ny;
                    if(!InRange(nx, ny) || (nx == sx && ny == sy)){   // 만약 범위를 벗어나거나 술래가 있다면
                        for(int d=1; d<=8; d++){    //  이동할 수 있을 때까지 45도 반시계 방향으로 회전하기
                            nx = i + dirs[(curD+d)%MAX_DIR][0], ny = j + dirs[(curD+d)%MAX_DIR][1];
                            if(InRange(nx,ny) && (nx != sx || ny != sy)){
                                curD = (curD + d) % MAX_DIR;
                                break;
                            }
                        }
                        if(nx == startX && ny == startY){
                            cannotMovable = true;
                            continue;       // 이동할 수 없다면 움직이지 않기
                        }
                    }
                    // 이제 (i,j)에서 (nx,ny)로 바꾸기
                    //cout << i << ' ' << j << "에서 " << nx << ' ' << ny << ' ' << curD << "로 바꾸기\n";
                    int movingNum = grid[nx][ny].first, movingDir = grid[nx][ny].second;
                    grid[nx][ny] = make_pair(num, curD);
                    grid[i][j] = make_pair(movingNum, movingDir);
                    IsMoved = true;
                }
                if(IsMoved || cannotMovable)
                    break;
            }
            if(IsMoved || cannotMovable)
                break;
        }
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << grid[i][j].first << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */
    }
}

void ChooseNext(int cnt){
    if(IsFinish()){
        // 만약 끝났다면 점수 업데이트하기
        ans = max(ans, curr);
        return;
    }
    for(int i=1; i<n; i++){
        //cout << cnt << "번째: " << '\n';
        int nx = sx + dirs[sd][0]*i, ny = sy + dirs[sd][1]*i;
        if(InRange(nx, ny) && grid[nx][ny] != NOT_EXIST){
            // 만약 술래가 이동할 곳이 범위 안이고, 도둑이 존재한다면
            //cout << "술래 원래 위치: " << sx << ' ' << sy << '\n';
            pair<int, int> tmp[MAX_N][MAX_N];
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    tmp[i][j] = grid[i][j];
            int priorX, priorY, priorD, priorS;
            tie(priorX, priorY, priorD, priorS) = CatchTheif(nx, ny);
            //cout << "술래 이동한 위치: " << sx << ' ' << sy << '\n';
            MoveThief();
            
            ChooseNext(cnt+1);

            // 도둑 움직이기 이전으로 되돌리기
            sx = priorX, sy = priorY, sd = priorD, curr = priorS;
            // catchTheif도 되돌리기
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    grid[i][j] = tmp[i][j];
            //cout << "ㅁㅇㄻㄴㅇㄹ" << cnt << '\n';
        }
    }
}

int Simulate(){
    // Step 1. 먼저 번호가 작은 순서대로 이동시키기
    MoveThief();
    ans = curr;
    // Step 2. 이후 술래말 이동하기
    if(IsFinish())
        return 0;
    
    // backtracking으로 술래가 이동할 곳 정하기
    ChooseNext(1);      // 술래가 (0,0)에서 1번째 이동할 곳을 정하러 가기

    return 0;
}

int main() {
    // 입력 받기:
    Input();    

    // 시뮬레이션 시작
    // 먼저 (0,0)에 있는 도둑을 잡고 시작
    CatchTheif(0,0);        

    Simulate();

    cout << ans;
    return 0;
}