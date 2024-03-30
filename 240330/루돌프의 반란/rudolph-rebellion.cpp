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

void Bump(int idx, int dir, int RudolfMove, int turn){     // idx번 산타가 있는 곳으로 dir 방향왔을 때 충돌이 남
    int sx = santa_loc[idx].first, sy = santa_loc[idx].second;
    int cur_dir, dist, plus_score;

    if(RudolfMove == 1){
        cur_dir = dir;
        dist = c;
        plus_score = c;
        faint[idx] = turn+1;
    }
    else if(RudolfMove == 0){
        //cout << dir << "방향으로 옴 " <<'\n';
        if(dir % 4 <= 1) cur_dir = dir + 2;
        else cur_dir = dir - 2;
        dist = d - 1;
        plus_score = d;
        faint[idx] = turn+1;
        //cout << cur_dir << "방향으로 가야 함" << '\n';
    }
    else{
        cur_dir = dir;
        dist = 1;
        plus_score = 0;
    }
    int firstX = sx + dirs[cur_dir][0]*dist, firstY = sy + dirs[cur_dir][1]*dist;
    if(!InRange(firstX, firstY)){
        faint[idx] = INT_MAX;
        santa_loc[idx] = LOSE;
        grid[sx][sy] = 0;
    }
    else{
        if(grid[firstX][firstY] != 0){
            if(firstX != sx || firstY != sy)
                Bump(grid[firstX][firstY], cur_dir, 2, turn);
        }
        grid[sx][sy] = 0;
        santa_loc[idx] = make_pair(firstX, firstY);
        grid[firstX][firstY] = idx;
    }

    score[idx] += plus_score;
    return;
}

void MoveRudolf(int turn){          // 루돌프를 움직이는 함수
    // Step 1. 루돌프에서 가장 가까운 산타 찾기
    int near_santa = GetNearestSanta();
    
    // Step 2. 해당 산타를 향해 가장 가까워지는 방향으로 돌진하기
    tuple<int, int, int> next_rudolf_loc = GetNextRudolfLocation(near_santa);
    int nx, ny, nd;
    tie(nx, ny, nd) = next_rudolf_loc;
    
    // Step 3. 충돌 여부 확인하기
    int idx = 0;
    if(grid[nx][ny] != 0){      // 만약 루돌프가 움직이려는 칸에 산타가 있다면 충돌 처리
        idx = grid[nx][ny];
        //faint[grid[nx][ny]] = turn+1;
        Bump(grid[nx][ny], nd, 1, turn);    // (nx, ny) 자리로 루돌프가 nd방향으로 이동해와서 충돌함
    }
    
    //faint[grid[nx][ny]] = turn+1;
    grid[rudolf.first][rudolf.second] = 0;      // 원래 있던 자리 0으로 만들기
    grid[nx][ny] = -1;                          // 새로운 자리에 루돌프 표시
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
        //score[idx] += d;
        //Bump(int idx, int dir, int RudolfMove, int turn)
        //cout << nx << ' ' << ny << ' ' << nd << "부딪힘" << '\n';
        Bump(idx, nd, 0, idx);
        faint[idx] = turn+1;
    }
    else{
        grid[sx][sy] = 0;
        santa_loc[idx] = make_pair(nx, ny);
        grid[nx][ny] = idx;
    } 
}

void Simulate(int turn){
    // 1. 루돌프 이동
    MoveRudolf(turn);
    /*
    cout << "Rudolf 이동" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    // 2. 산타 이동
    for(int i=1; i<=p; i++){
        if(santa_loc[i] == LOSE) continue;      // 이미 게임에서 탈락한 산타는 제외시키기
        if(faint[i] >= turn) continue;          // 기절해서 현재 턴까지도 움직일 수 없다면 제외시키기
        MoveSanta(i, turn);                     // i번 산타를 turn번째 턴에서 이동시키기 
        /*
        cout << i<<"번 산타 이동 " << '\n';
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
        }
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
    cout << '\n';
}

int main() {
    // 입력 받기:
    Input();

    // 시뮬레이션 시작
    for(int i=1; i<=m; i++){
        if(IsFinish())
            break;
        Simulate(i);
        //Output();
    }  

    // 출력하기:
    Output();
    return 0;
}