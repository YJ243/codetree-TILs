#include <iostream>
#include <cstdlib>
#include <climits>
#include <tuple>

#define MAX_P 30
#define MAX_N 50
#define LOSE make_pair(-1, -1)  // 게임밖으로 나간 산타의 위치(탈락)
using namespace std;

int n, m, p, c, d;      // n: 게임판의 크기, m: 게임 턴수, p: 산타 수, c: 루돌프 힘, d: 산타 힘
int dirs[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};

int grid[MAX_N][MAX_N]; // 0: 빈칸, 1 ~ 양수: 산타 번호, -1: 루돌프
pair<int, int> rudolf;
pair<int, int> santa_loc[MAX_P+1];
int score[MAX_P+1];
int faint[MAX_P+1];

void Input(){
    cin >> n >> m >> p >> c >> d;
    int r, c;
    cin >> r >> c;  r--; c--;
    rudolf = make_pair(r, c);
    grid[r][c] = -1;

    for(int i=0; i<p; i++){
        int num, sr, sc;
        cin >> num >> sr >> sc;
        sr--; sc--;
        santa_loc[num] = make_pair(sr, sc);
        grid[sr][sc] = num;
    }


}

bool IsFinish(){
    for(int i=1; i<=p; i++){
        // 한 명이라도 탈락을 안했다면
        if(santa_loc[i] != LOSE)
            return false;
    }   
    return true;
}

int GetDist(int rx, int ry, int sx, int sy){
    return (rx - sx)*(rx - sx) + (ry - sy)*(ry - sy);
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int GetNearestSanta(){
    int rx = rudolf.first, ry = rudolf.second;                  // 루돌프 위치
    int minD = INT_MAX, minI = INT_MAX, maxX = 0, maxY = 0;     // 루돌프에서 가장 가까운 산타까지 거리, 산타 인덱스와 그 좌표
    for(int i=1; i<=p; i++){
        if(santa_loc[i] == LOSE) continue;
        int sx = santa_loc[i].first, sy = santa_loc[i].second;
        int curD = GetDist(rx, ry, sx, sy);
        if(make_tuple(minD, -maxX, -maxY) > make_tuple(curD, -sx, -sy))
            minD = curD, minI = i, maxX = sx, maxY = sy;
    }
    return minI;
}

tuple<int, int, int> GetNextRudolfLocation(int near_santa){
    int rx = rudolf.first, ry = rudolf.second;
    int sx = santa_loc[near_santa].first, sy = santa_loc[near_santa].second;

    int minDist = INT_MAX, minDir = 0, minX = 0, minY = 0;
    for(int d=0; d<8; d++){
        int nx = rx + dirs[d][0], ny = ry + dirs[d][1];
        if(InRange(nx, ny)){
            int curD = GetDist(nx, ny, sx, sy);
            if(minDist > curD){
                minDist = curD, minDir = d, minX = nx, minY = ny;
            }
        }
    }
    return make_tuple(minX, minY, minDir);
}

void Bump(int x, int y, int dir, bool RudolfMove, int diff, int idx){     // (x,y) 자리에서 dir방향으로 이동해와서 충돌, 루돌프or산타가 움직였는지 고려해 처리
    int curD, santaIdx;
    if(RudolfMove){         // 루돌프가 움직인 경우
        curD = dir;
        santaIdx = idx;
    }
    else{                   // 산타가 움직인 경우
        if(dir % 4 <= 1)
            curD = dir + 2;
        else
            curD = dir - 2;
        santaIdx = idx;
    }
    int nx = x + dirs[curD][0]*diff, ny = y + dirs[curD][1]*diff;
    //cout << "탈락: " << santaIdx << ' ' << x << ' ' << y << "에서 " << curD << "방향으로 갈 것임 " << nx << ' ' << ny << '\n';
    if(!InRange(nx, ny)){       // 산타가 이동할 곳이 범위를 벗어난다면 탈락시키기
        grid[santa_loc[santaIdx].first][santa_loc[santaIdx].second] = 0;         // 원래 산타가 있던 곳 빈 곳으로 만들기 
        santa_loc[santaIdx] = LOSE;         // 산타 탈락했다고 위치 표시
        return;
    }
    else{       // 범위 안에 있다면
        if(grid[nx][ny] != 0){              // 이동할 칸에 다른 산타가 있다면 비워주기
            Bump(nx, ny, dir, 0, 1, grid[nx][ny]);          // 상호작용

            grid[nx][ny] = santaIdx;
        grid[santa_loc[santaIdx].first][santa_loc[santaIdx].second] = 0;    // 원래 있던 자리 0으로
        santa_loc[santaIdx] = make_pair(nx, ny);
        }
        // 그리고 넣어주기
        else{
        grid[nx][ny] = santaIdx;
        grid[santa_loc[santaIdx].first][santa_loc[santaIdx].second] = 0;    // 원래 있던 자리 0으로
        santa_loc[santaIdx] = make_pair(nx, ny);
        }
        //cout << "인덱스: " << santaIdx << '\n';
    }
}

void MoveRudolf(int turn){          // 루돌프를 움직이는 함수
    // Step 1. 루돌프에서 가장 가까운 산타 찾기
    int near_santa = GetNearestSanta();
    
    // Step 2. 해당 산타를 향해 가장 가까워지는 방향으로 돌진하기
    tuple<int, int, int> next_rudolf_loc = GetNextRudolfLocation(near_santa);
    int nx, ny, nd;
    tie(nx, ny, nd) = next_rudolf_loc;
    
    // Step 3. 충돌 여부 확인하기
    if(grid[nx][ny] != 0){      // 만약 루돌프가 움직이려는 칸에 산타가 있다면 충돌 처리
        score[grid[nx][ny]] += c;
        faint[grid[nx][ny]] = turn+1;
        Bump(nx, ny, nd, 1, c,grid[nx][ny]);    // (nx, ny) 자리로 루돌프가 nd방향으로 이동해와서 충돌함
    }
    
    grid[nx][ny] = -1;                          // 새로운 자리에 루돌프 표시
    grid[rudolf.first][rudolf.second] = 0;      // 원래 있던 자리 0으로 만들기
    rudolf = make_pair(nx, ny);                 // 루돌프 위치 업데이트
}

tuple<int, int, int> GetNextSantaLocation(int idx){
    int rx = rudolf.first, ry = rudolf.second;
    int sx = santa_loc[idx].first, sy = santa_loc[idx].second;

    int minDist = GetDist(sx, sy, rx, ry), minDir = 0, minX = sx, minY = sy;
    for(int d=0; d<4; d++){
        int nx = sx + dirs[d][0], ny = sy + dirs[d][1];
        int curDist = GetDist(nx, ny, rx, ry);
        if(InRange(nx, ny) && grid[nx][ny] <= 0 && curDist < minDist){
            minDist = curDist, minDir = d, minX = nx, minY = ny;
        }
    }
    
    return make_tuple(minX, minY, minDir);
}

void MoveSanta(int idx, int turn){      // idx번 산타를 turn번째에 이동시키기
    int sx = santa_loc[idx].first, sy = santa_loc[idx].second;
    tuple<int, int, int> next_santa = GetNextSantaLocation(idx);
    int nx, ny, nd;
    tie(nx, ny, nd) = next_santa;
    if(sx == nx && sy == ny)    return; // 만약 움직일 수 없으면 넘어가기
    
    if(grid[nx][ny] == -1){
        // 만약 이동하려는 자리에 산타가 있다면
        score[idx] += d;
        faint[idx] = turn+1;
        //cout << nd << "방향으로: " << '\n';
        Bump(nx, ny, nd, 0, d, idx);
    }
    else{
        grid[nx][ny] = idx;
        grid[sx][sy] = 0;
        santa_loc[idx] = make_pair(nx, ny);
    } 
}

void Simulate(int turn){
    // 1. 루돌프 이동
    MoveRudolf(turn);

    // 2. 산타 이동
    for(int i=1; i<=p; i++){
        if(santa_loc[i] == LOSE) continue;      // 이미 게임에서 탈락한 산타는 제외시키기
        if(faint[i] >= turn) continue;          // 기절해서 현재 턴까지도 움직일 수 없다면 제외시키기
        MoveSanta(i, turn);                     // i번 산타를 turn번째 턴에서 이동시키기 
        //cout << turn << "번째에 " << i << "번 산타 움직임" << '\n';
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    }
    // 3. 점수 업데이트
    for(int i=1; i<=p; i++){
        if(santa_loc[i] == LOSE) continue;
        score[i]++;         // 아직 탈락하지 않은 산타들에게는 1점씩 추가로 부여하기
    }

}

void Output(){      // 각 산타가 얻은 최종 점수를 출력하는 함수
    for(int i=1; i<=p; i++)
        cout << score[i] << ' ';
}

int main() {
    // 입력 받기:
    Input();

    // 시뮬레이션 시작
    for(int i=1; i<=m; i++){
        if(IsFinish())
            break;
        Simulate(i);
    }  

    // 출력하기:
    Output();
    return 0;
}