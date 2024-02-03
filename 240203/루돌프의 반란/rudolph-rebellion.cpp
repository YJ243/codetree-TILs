#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

#define MAX_N 50
#define MAX_P 30

using namespace std;
int n, m, p, c, d;          // n: 게임판 크기, m: 게임 턴 수, p: 산타의 수, c: 루돌프의 힘, d: 산타의 힘
int turn;
int grid[MAX_N][MAX_N];     // 게임판, grid[i][j] -> 0: 빈칸, 1~p 산타 번호, -1: 루돌프
// 상우하좌, 대각선 좌표 (산타는 0~3까지만 이용, 루돌프는 0~7모두 볼 수 있음)
int dirs[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};

/* 산타를 나타내는 자료구조 */
pair<int, int> santa[MAX_P+1];  // santa[i]: i번 산타의 위치
int scores[MAX_P+1];            // scores[i]: i번 산타의 점수
int freezeTime[MAX_P+1];        // freezeTime[i]: i번 산타는 해당 시간까지 기절, 1001이면 탈락

void Input(){               // 입력 받는 함수
    cin >> n >> m >> p >> c >> d;   
    int r,c;
    cin >> r >> c;
    grid[r-1][c-1] = -1;            // 루돌프 위치 입력
    for(int i=0; i<p; i++){         // 산타 번호, 위치 입력 받기
        int num, x, y;
        cin >> num >> x >> y;
        santa[num] = make_pair(x-1,y-1);
        grid[x-1][y-1] = num;
    }
}

void Output(){              // 정답 출력 함수
    for(int i=1; i<=p; i++)
        cout << scores[i] << ' ';
    cout << '\n';
}
bool IsFinish(){            // 게임이 끝났는지 확인하는 함수
    for(int i=1; i<=p; i++){
        if(freezeTime[i] != 1001)   // 하나라도 탈락하지 않은 산타가 있다면 아직 끝나지 않았음
            return false;
    }
    return true;
}

bool InRange(int x, int y){ // 범위 안에 있는지 확인하는 함수
    return 0 <= x && x < n && 0 <= y && y < n;
}

pair<int, int> RudolfLoc(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == -1)
                return make_pair(i,j);
        }
    }
}

int RudolfAndSanta(int RudolfX, int RudolfY, int SantaX, int SantaY){   // 루돌프와 산타 간의 거리를 리턴하는 함수
    return (RudolfX-SantaX)*(RudolfX-SantaX) + (RudolfY-SantaY)*(RudolfY-SantaY);
}

int FindClosestSanta(){     // 현재 루돌프의 위치에서 가장 가까운 산타를 찾는 함수
    pair<int, int> Rudolf = RudolfLoc();
    int minD = INT_MAX, curD = 0, minIdx = 0;
    for(int i=1; i<=p; i++){
        if(freezeTime[i] == 1001) continue;     // 만약 산타가 탈락했다면 해당 인덱스의 산타 무시
        curD = RudolfAndSanta(Rudolf.first, Rudolf.second, santa[i].first, santa[i].second);    // 현재 산타~루돌프 거리
        // 현재 최소 거리보다 더 가깝다면 업데이트
        if(curD < minD){    
            minD = curD;
            minIdx = i;
        }
        // 현재 최소 거리와 같지만, r이 크거나 / r이 동일한데 c가 크면
        else if(curD == minD && ((santa[minIdx].first < santa[i].first) || 
                (santa[minIdx].first == santa[i].first && santa[minIdx].second < santa[i].second))){
            minD = curD;
            minIdx = i;
        }
    }
    return minIdx;
}

tuple<int, int, int> FindClosestLoc(int minIdx){        // 현재 루돌프가 움직일 칸을 구해주는 함수
    pair<int, int> Rudolf = RudolfLoc();
    int santaX = santa[minIdx].first, santaY = santa[minIdx].second;
    
    int minD = INT_MAX, curD = 0, minI = 0, minJ = 0, minDirection;
    for(int i=0; i<8; i++){ // 8개의 방향을 보면서 가장 가까운 방향 찾기
        int nx = Rudolf.first + dirs[i][0], ny = Rudolf.second + dirs[i][1];
        
        if(InRange(nx,ny)){ // 만약 범위 안에 있다면
            curD = RudolfAndSanta(nx, ny, santaX, santaY);
            if(curD < minD){
                minD = curD;
                minI = nx, minJ = ny;
                minDirection = i;
            }
        }
    }
    return make_tuple(minI, minJ, minDirection);
}

void move(int santaIdx, int direction, int moveScore, bool fromRudolf){  // santaIdx번의 산타를 direction 반대 방향으로 moveScore만큼 이동시키는 함수
    // Step 1. 튕겨나갔을 때 위치하는 처음 좌표 구하기
    int firstX, firstY;     // santaIdx에 있는 산타가 반대방향으로 moveScore만큼 이동했을 때의 옮겨갈 처음 위치
    int santaX = santa[santaIdx].first, santaY = santa[santaIdx].second;    
    if(fromRudolf){
        firstX = santaX+(dirs[direction][0])*moveScore, firstY = santaY+(dirs[direction][1])*moveScore;
    }
    else{
        firstX = santaX+(-dirs[direction][0])*(moveScore-1), firstY = santaY+(-dirs[direction][1])*(moveScore-1);
    }

    // Step2. 그 좌표로 산타 이동
    //      2-1. 그 좌표가 격자 밖일때

    if(!InRange(firstX, firstY)){       // 만약 튕겨난 위치가 격자를 벗어난다면
        freezeTime[santaIdx] = 1001;    // 해당 산타 탈락
        grid[santaX][santaY] = 0;
        santa[santaIdx].first = -1, santa[santaIdx].second = -1;
    }
    //      2-2. 그 좌표가 격자 안일 때
    else{ 
        // grid[firstX][firstY]가 빌 때까지 해당 산타 이동해주기
        if(grid[firstX][firstY] > 0){
            while(grid[firstX][firstY] != 0){
            // 만약 튕겨나갔을 때 위치하는 좌표에 산타가 있다면
                move(grid[firstX][firstY], direction, 2, false);
            }
        }
        grid[santaX][santaY] = 0;
        grid[firstX][firstY] = santaIdx;
        santa[santaIdx].first = firstX, santa[santaIdx].second = firstY;
    }
}

void Bomb(int fromX, int fromY, int toX, int toY, bool fromRudolf, int direction){        // 충돌 함수
    // (fromX,fromY)에서 (toX,toY)로 direction 방향으로 이동해서 충돌이 났고, fromRudolf가 참이면 루돌프가 이동한 것, 거짓이면 산타가 이동한 것
    // Step 0. 기본 변수 세팅
    int moveScore, santaIdx;
    if(fromRudolf){     // 루돌프가 산타로 움직였다면
        moveScore = c;  // 움직이는 칸수와 추가되는 점수는 c
        santaIdx = grid[toX][toY];  // (toX, toY)의 산타가 움직이기
    }

    else{               // 산타가 루돌프로 움직였다면
        moveScore = d;  // 움직이는 칸수와 추가되는 점수는 d
        santaIdx = grid[fromX][fromY];  // (fromX, fromY)의 산타가 움직이기
    }
    
    // Step 1. 산타를 direction 방향으로 moveScore만큼 이동시키기

    move(santaIdx, direction, moveScore, fromRudolf);

    // Step 2. 산타 기절시키기
    if(freezeTime[santaIdx] != 1001)    // 움직인 산타가 탈락하지 않았다면
        freezeTime[santaIdx] = turn+1;

    // Step 3. 그 산타에게 점수 부여하기
    scores[santaIdx] += moveScore;
}

void moveRudolf(){          // 루돌프를 움직이는 함수
    pair<int, int> Rudolf = RudolfLoc();

    // Step 1. 가장 가까운 산타를 찾기
    int minIdx=0;
    minIdx = FindClosestSanta();

    // Step 2. 루돌프는 minIdx번의 산타로 이동
    int minI, minJ, minD;
    tie(minI, minJ, minD) = FindClosestLoc(minIdx);

    // Step 3. 만약 루돌프가 이동할 곳에 산타가 있다면 충돌 발생
    if(grid[minI][minJ] > 0){
        Bomb(Rudolf.first, Rudolf.second, minI, minJ, true, minD);     // 산타 충돌 발생하여 이동시키기
    }
    
    // Step 4. 움직일 곳이 빈칸이라면 루돌프 이동
    grid[Rudolf.first][Rudolf.second] = 0;
    grid[minI][minJ] = -1;
}

void moveSanta(int num){          // num번 산타를 움직이는 함수
    pair<int, int> Rudolf = RudolfLoc();
    pair<int, int> curSanta = santa[num];
    int minI = 0, minJ = 0, minD = 0;
    int curDistance = RudolfAndSanta(Rudolf.first, Rudolf.second, curSanta.first, curSanta.second);
    
    // Step 1. num 번 산타는 루돌프와 가까워지는 방향으로 이동
    for(int dir = 0; dir < 4; dir++){
        int nx = curSanta.first + dirs[dir][0], ny = curSanta.second + dirs[dir][1];
        if(InRange(nx,ny) && grid[nx][ny] <= 0){    // 범위 안에 있고, 격자에 산타가 없다면
            int movedDistance = RudolfAndSanta(nx,ny, Rudolf.first, Rudolf.second);
            if(curDistance > movedDistance){    // 현재 위치에서 루돌프까지의 거리보다 이동한 것이 더 가까워 진다면
                curDistance = movedDistance;                
                minI = nx, minJ = ny, minD = dir;
            }
        }
    }
    // 만약 움직일 수 없거나 움직일 수 있어도 가까워지지 않는다면
    if(curDistance == RudolfAndSanta(Rudolf.first, Rudolf.second, curSanta.first, curSanta.second)){
        return;
    }

    // 만약 움직일 곳에 산타가 있다면
    if(grid[minI][minJ] == -1)
        Bomb(curSanta.first, curSanta.second, minI, minJ, false, minD);
    else{
        // 만약 움직일 곳이 빈칸이라면
        grid[minI][minJ] = grid[curSanta.first][curSanta.second];       // 산타 번호 옮기고
        santa[grid[minI][minJ]] = make_pair(minI, minJ);            // 산타 위치 바꾸고
        grid[curSanta.first][curSanta.second] = 0;                  // 원래칸 0으로 만들기
    }
}

void giveScore(){           // 게임에 남아있는 산타들에게 1점씩 점수 부여
    for(int i=1; i<=p; i++)
        if(freezeTime[i] != 1001)
            scores[i]++;
}

void Simulate(){            // 시뮬레이션 진행
    // 총 m개의 턴에 걸쳐 게임 진행
    for(turn=1; turn<=m; turn++){
        // Step 1. 루톨프 이동
        moveRudolf();

        // Step 2. 산타 이동
        for(int s=1; s<=p; s++){
            // 만약 기절해있지 않거나 탈락하지 않았다면
            if(freezeTime[s] < turn){
                moveSanta(s);
            }
        }
        
        // Step 3. 종료 조건 확인
        if(IsFinish()) break;
        
        // Step 4. 탈락 안한 산타 들 1점씩 점수 부여
        giveScore();
        
        if( turn >= 7){
            for(int i=0; i<n; i++){}
        }
    }
}


int main() {
    // 입력:
    Input();

    // 시뮬레이션 시작
    Simulate();

    // 출력:
    Output();
    return 0;
}