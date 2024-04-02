#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <unordered_set>

#define MAX_L 40
#define MAX_N 30

using namespace std;
unordered_set<int> s;
int L, N, Q;                                        // L: 체스판 크기, N: 기사 수, Q: 명령의 수
int chess[MAX_L][MAX_L];                            // 체스판, 0: 빈칸, 1: 함정, 2: 벽
int knight_loc[MAX_L][MAX_L];                       // 0: 빈칸, 양수: 기사 번호, -2: 벽
tuple<int, int, int, int, int> knights[MAX_N+1];    // 기사들 정보 (r, c, h, w, k)
int damage[MAX_N+1];            // 기사들이 받은 데미지
bool IsDead[MAX_N+1];           // 기사들이 죽었는지 확인하는 변수
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 상우하좌
bool ExistWalls;            // 현재 보고 있는 기사와 연결되있는 끝에 벽이 있는지 확인하는 변수
bool visited[MAX_L][MAX_L];
queue<int> q;
vector<int> connected_knights;

void Init(){                    // 입력을 받는 함수:
    cin >> L >> N >> Q;         // L: 체스판 크기, N: 기사 수, Q: 명령의 수
    for(int i=0; i<L; i++){     // 체스판 입력 받기
        for(int j=0; j<L; j++){
            cin >> chess[i][j];
            if(chess[i][j] == 2)
                knight_loc[i][j] = -2;      // 기사들 격자에도 벽 표시하기
        }
    }

    for(int i=1; i<=N; i++){
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        r--; c--;
        //cout << r << ' ' << c << ' ' << h << ' ' << w << ' ' << k << '\n';
        knights[i] = make_tuple(r, c, h, w, k);
        //cout << "Adfadsfa " << '\n';
        for(int x = r; x < r + h; x++){
            for(int y=c; y < c+w; y++){
                knight_loc[x][y] = i;       // 기사들 위치 표시하기
            }
        }
    }
    
}

void Initialize_before_search(){
    ExistWalls = false;
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            visited[i][j] = false;
        }
    }
    connected_knights.clear();
    s.clear();
}

bool InRange(int x, int y){
    return 0 <= x && x < L && 0 <= y && y < L;
}

void bfs(int d){
    while(!q.empty()){
        int cur_id = q.front();
        q.pop();
        int r, c, h, w, k;
        tie(r, c, h, w, k) = knights[cur_id];
        for(int x=r; x<r+h; x++){
            for(int y=c; y<c+w; y++){
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if(InRange(nx, ny) && knight_loc[nx][ny] > 0 && knight_loc[nx][ny] != cur_id){
                    // 범위안에 있고, 다른 기사라면
                    q.push(knight_loc[nx][ny]);
                    connected_knights.push_back(knight_loc[nx][ny]);
                }
                if(knight_loc[nx][ny] == -2 || !InRange(nx, ny)){
                    // 벽을 만났다면
                    ExistWalls = true;

                }
            }
        }
        if(ExistWalls) return;
    }
}

void PushKnights(int id, int d){
    // 먼저 현재 id와 연결되어 있는 모든 칸 빈칸으로 만들기
    for(int i: s){
        int r, c, h, w, k;
        tie(r, c, h, w, k) = knights[i];
        //cout << r << ' ' << c << ' ' << h << ' ' << w << ' ' << k << '\n';
        for(int x=r; x<r+h; x++){
            for(int y=c; y<c+w; y++){
                //cout << "0으로 만듦: " << x << ' ' << y << '\n';
                knight_loc[x][y] = 0;   // 빈칸으로 만들기
            }
        }
    }

    for(int i:s){
        int r, c, h, w, k;
        tie(r, c, h, w, k) = knights[i];
        r += dirs[d][0]; c += dirs[d][1];
        //cout << r << ' ' << c << ' ' << h << ' ' << w << ' ' << k << '\n';
        for(int x=r; x < r+h; x++){
            for(int y=c; y<c+w; y++){
                knight_loc[x][y] = i;
            }
        }
        if(i != id){
            
            for(int x=r; x<r+h; x++){
                for(int y=c; y<c+w; y++){
                    if(chess[x][y] == 1){
                        // << "damage받음: " << i << '\n';
                        damage[i]++;
                        k--;
                    }
                }
            }
            if(k <= 0){
                for(int x=r; x < r+h; x++){
                    for(int y=c; y<c+w; y++){
                        knight_loc[x][y] = 0;
                        k = 0;
                        IsDead[i] = true;
                    }
                }
            }
        }
        
        knights[i] = make_tuple(r, c, h, w, k);
    }

}

void Move(int id, int d){       // id번 기사를 d 방향으로 이동시키는 함수
    // Step 1. id번 기사와 d방향으로 이어져있는 기사들 찾기
    Initialize_before_search();
    q.push(id);
    bfs(d);

    // Step 2. 만약 끝이 벽이 아니라면 밀기
    if(ExistWalls) return;
    connected_knights.push_back(id);
    for(int i=0; i<(int)connected_knights.size(); i++){
        s.insert(connected_knights[i]);
        //cout << "연결되어 있는 애들: " << connected_knights[i] << '\n';
    }

    PushKnights(id, d);
}

void Output(){
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(!IsDead[i]){
            ans += damage[i];

        }
    }
    cout << ans << '\n';
}

int main() {
    // 변수 입력 및 초기화:
    Init();
    
    // 명령 입력받고 기사 이동시키기
    for(int i=0; i<Q; i++){
        int id, d;
        cin >> id >> d;
        if(IsDead[id]) continue;
        Move(id, d);

    }

    // 출력하기
    Output();
    return 0;
}