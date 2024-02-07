#include <iostream>
#include <vector>
#include <tuple>

#define MAX_COORD 4000
#define OFFSET 2000
#define DIR_NUM 4
#define BLANK -1
#define ASCII_NUM 128

using namespace std;

typedef tuple<int, int, int, int, int> marble;
int T, N;                       // 테스트 케이스 수, 구슬의 수
vector<marble> marbles;         // (x,y), w, id, d 저장
vector<marble> next_marbles;    // 이동하면서 구슬 정보를 저장하는 중간 배열

int marble_index[MAX_COORD+2][MAX_COORD+2];
int dirs[DIR_NUM][2] = {{0,1},{0, -1},{1,0},{-1,0}}; // U, D, R, L
int direction[ASCII_NUM];
int elapsed_time;
int last_collision_time;

bool InRange(int x, int y){
    return 0 <= x && x <= MAX_COORD && 0 <= y && y <= MAX_COORD;
}

void Collision(int x, int y, marble origin, marble newbi){ // (x,y)에 이미 존재하는 marble origin과 marble newbi의 충돌 처리
    int x1, y1, w1, id1, d1;
    tie(x1, y1, w1, id1, d1) = origin;
    
    int x2, y2, w2, id2, d2;
    tie(x2, y2, w2, id2, d2) = newbi;

    // 우선순위 큰 것 골라내기
    if(w1 > w2 || (w1 == w2 && id1 > id2)){     // origin이 큼
        marble_index[x2][y2] = BLANK;
    }
    else{   // newbi가 큼
        for(int i=0; i<(int)next_marbles.size(); i++){
            int cx, cy, w, id, d;
            tie(cx, cy, w, id, d) = next_marbles[i];
            if(id == id1){
                // 만약 next_marbles에 사라질 구슬이 있다면 없애기
                next_marbles.erase(next_marbles.begin()+i);
                break;
            }
        }
        marble_index[x][y] = id2;
        next_marbles.push_back(make_tuple(x, y, w2, id2, d2));
        marble_index[x2][y2] = BLANK;

    }

}

void Move(int x, int y, marble m){      // (x,y) 자리로 marble m을 이동시키는 함수
    int nx = x, ny = y;         
    //cout << "여기로 옮길란다" << nx << ' ' << ny << ' ' << marble_index[nx][ny] << '\n';
    int cx, cy, w, id, d;
    tie(cx, cy, w, id, d) = m;

    // 만약 (nx, ny) 자리가 비어있다면
    if(marble_index[nx][ny] == BLANK){
        // 바로 그 곳으로 옮겨주기
        marble_index[cx][cy] = BLANK;
        marble_index[nx][ny] = id;
        next_marbles.push_back(make_tuple(nx, ny, w, id, d));
    }
    // 만약 그 자리에 다른 구슬이 있다면
    else{
        last_collision_time = elapsed_time;
        int origin_idx = marble_index[x][y];
        for(int i=0; i<(int)marbles.size(); i++){
            int x, y, w, id, d;
            tie(x, y, w, id, d) = marbles[i];
            if(origin_idx == id){
                Collision(x, y,  marbles[i],m);   // (nx, ny)로 이동하려는 marble m에 대한 충돌 처리
                break;
            }
        }
    }
}

void Simulate(){
    // 이동할 수 있는 만큼 움직여보기
    int move_cnt = MAX_COORD;
    while(move_cnt--){
        elapsed_time++;
        // 1. 구슬을 보면서 차례대로 이동시키기 
        //cout << "&&&&&&" << move_cnt << '\n';
        for(int i=0; i<(int)marbles.size(); i++){
            int x, y, w, id, d;
            tie(x, y, w, id, d) = marbles[i];

            //cout << x << ' ' << y << ' ' << id << '\n';

            int nx = x+dirs[d][0], ny = y+dirs[d][1];
            // 만약 다음 움직일 좌표가 범위를 넘어간다면 무시하기
            if(!InRange(nx,ny)) continue;
            //cout << "나는 범위내에 있지롱" << nx << ' ' << ny << '\n';
            Move(nx, ny, marbles[i]);     // (x,y) 자리로 marbles[i]를 이동시키기
        }
        // next_marbles를 marbles로 옮기기
        marbles.clear();
        for(int i=0; i<(int)next_marbles.size(); i++){
            int x, y, w, id, d;
            tie(x, y, w, id, d) = next_marbles[i];
            marbles.push_back(make_tuple(x, y, w, id, d));
        }
        next_marbles.clear();
        //cout << last_collision_time << ' ';
    }

    /*
    if(move_cnt == MAX_COORD && (int)marbles.size() == N)
        last_collision_time = -1;
    */
}

void Initialize(){
    // marble_index 배열 초기화하기
    for(int i=0; i<=MAX_COORD; i++){
        for(int j=0; j<=MAX_COORD; j++){
            marble_index[i][j] = BLANK;
        }
    }
}

int main() {
    // 변수 선언 및 입력:
    cin >> T;
    direction['U'] = 0;
    direction['D'] = 1;
    direction['R'] = 2;
    direction['L'] = 3;
    while(T--){
        Initialize();
        elapsed_time = 0;
        last_collision_time = -1;
        cin >> N;
        for(int i=1; i<=N; i++){
            int x, y, w; char d;
            cin >> x >> y >> w >> d;
            // 좌표계를 격자처럼 바꾸기
            int cx = x*2 + OFFSET, cy = y*2 + OFFSET;
            marble_index[cx][cy] = i;       // 해당 위치에 번호 담기
            marbles.push_back(make_tuple(cx,cy, w, i, direction[d]));

        }
        Simulate();
        cout << last_collision_time << '\n';
    }


    return 0;
}