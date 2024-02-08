#include <iostream>
#include <vector>
#include <tuple>
#define ASCII_NUM 128
#define MAX_XY 4000
#define OFFSET 2000
#define BLANK -1
using namespace std;

int T, N;
int elapsed_time;
int last_collision_time;
int dirIdx[ASCII_NUM];
int next_marble_numbers[MAX_XY+2][MAX_XY+2];
typedef tuple<int, int, int, int, int> marble;
vector<marble> cur_marble;
vector<marble> next_marble;
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};       // u, d, r, l (x,y)로 보

void Initialize(){
    for(int i=0; i<=MAX_XY; i++){
        for(int j=0; j<=MAX_XY; j++){
            next_marble_numbers[i][j] = BLANK;
        }
    }
}

void collide(int x, int y, marble new_m){     // (x,y) 자리에서 원래 있던 구슬과 새로운 구슬 new_id 처리하기
    int nw, nd, nid;
    tie(ignore, ignore,nw,nd,nid) = new_m;


    int old_id = next_marble_numbers[x][y];
    //cout << nid << "와 " << old_id << '\n';
    int cx, cy, cw, cd, cid;    // 현재 다음 구슬의 목록을 확인하면서
    for(int i=0; i<(int)next_marble.size(); i++){
        tie(cx, cy, cw, cd, cid) = next_marble[i];
        if(cid == old_id){
            //cout << "찾음" << cid << '\n';
            if(nw > cw || (nw == cw && nid > cid)){
                //cout << nid << "가 우선순위가 더 높음" << '\n';
                // 새로 들어갈 애가 더 우선순위가 높다면
                next_marble.erase(next_marble.begin()+i);
                next_marble_numbers[x][y] = nid;
                next_marble.push_back(make_tuple(x,y,nw,nd,nid));
            }
            else{
                //cout << cid<< "가 높음 " << '\n';
            }
            break;
        }
    }
    //cout << next_marble.size() << '\n';
}

void Move(){        // 현재 있는 구슬을 한칸씩 옮겨주는 함수
    for(int i=0; i<(int)cur_marble.size(); i++){
        int x, y, w, d, id;
        tie(x, y, w, d, id) = cur_marble[i];

        int nx = x+dirs[d][0], ny = y+dirs[d][1];
        //cout << nx << ' ' << ny << "=>" << id << ' ' << "가 위치할 다음 좌표"<<'\n';
        if(nx < 0 || nx > MAX_XY+1 || y < 0 || ny > MAX_XY+1) {
            //cout << "범위 벗어남" << '\n';
            //cout << nx << ' ' << ny << ' ' << id << '\n';
            //cout << '\n';
            continue;     // 만약 이동한 위치가 범위를 벗어난다며 무시
        
        }
        if(next_marble_numbers[nx][ny] == BLANK){
            //cout << "집어넣기" << id << '\n';
            // 만약 그 다음에 이동할 위치가 비어있다면
            next_marble_numbers[nx][ny] = id;   // 해당 칸에 구슬 번호 집어넣기
            next_marble.push_back(make_tuple(nx,ny,w,d,id));        // 다음 구슬 목록에 추가하기
        }
        else if(next_marble_numbers[nx][ny]>0){
            // 만약 그 다음에 이동할 위치에 다른 번호가 있다면
            //cout << "bump" << id<<"와"<< next_marble_numbers[nx][ny] << '\n';
            //cout << "여기서" << nx << ' ' << ny << '\n';
            last_collision_time = elapsed_time;
           // cout << last_collision_time << '\n';
            collide(nx,ny,cur_marble[i]);      // (nx,ny) 자리에서 원래 있는 구슬과 새로운 구슬과의 충돌 처리
        }
    }
}

void Simulate(){
    int turn_cnt = MAX_XY;
    // 0. 구슬 번호가 어디있는지 배열 초기화
    Initialize();
    while(turn_cnt--){
        elapsed_time++;
        // 1. 모든 구슬을 하나씩 보면서 이동시키기
        Move();

        // 2. cur_marble에 next_marble 복사하기
        cur_marble.clear();
        for(int i=0; i<(int)next_marble.size(); i++){
            int x, y, w, d, id;
            tie(x, y, w, d, id) = next_marble[i];
            next_marble_numbers[x][y] = BLANK;
        }
        cur_marble = next_marble;
        next_marble.clear();
 //cout << '\n';
    }
}

int main() {
    dirIdx['U'] = 0;
    dirIdx['D'] = 1;
    dirIdx['R'] = 2;
    dirIdx['L'] = 3;
    cin >> T;   // 테스트 케이스 수 입력받기
    while(T--){
        cur_marble.clear(); // 현재 구슬 정보 초기화
        elapsed_time = 0;
        last_collision_time = -1;
        // 구슬 개수
        cin >> N;
        // 해당 구슬들 정보 입력받기
        for(int i=1; i<=N; i++){
            int x, y, w; char d;
            cin >> x >> y >> w >> d;
            x = x*2 + OFFSET, y = y*2 + OFFSET;
            cur_marble.push_back(make_tuple(x, y, w, dirIdx[d], i));    // (x,y), 무게, 방향, 번호 집어넣기            
           // cout << x << ' ' << y << ' ' << i << '\n';
        }
        // 시뮬레이션 시작
        Simulate();

        cout << last_collision_time << '\n';
    }
    return 0;
}