#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX_L 40
#define MAX_N 30
#define MAX_Q 100
using namespace std;

int L, N, Q;                                        // L: 체스판 크기, N: 기사들 수, Q: 왕의 명령 수
int chess[MAX_L][MAX_L];                            // 체스판, 0: 빈칸, 1: 함정, 2: 벽
int knight_grid[MAX_L][MAX_L];                      // 기사들의 영역 표시, 0: 빈칸, 양수: 기사 번호, -2: 벽
tuple<int, int, int, int, int> knights[MAX_N+1];    // 기사 정보: (r, c) 좌측 상단/ (h,w) 길이 / k 초기 체력
int damaged[MAX_N+1];                               // i번 기사가 받은 데미지
bool IsFinished[MAX_N+1];                           // i번 기사가 사라졌는지 유무
bool IsMovable;
queue<int> q;                        // 탐색을 위한 큐
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};       // 상우하좌
vector<int> connected_knight;                       // 왕의 명령을 받은 기사와 연결되어있는 기사 번호
void Init(){       // 입력을 받는 함수
    cin >> L >> N >> Q;                     // L: 체스판 크기, N: 기사들 수, Q: 왕의 명령 수
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cin >> chess[i][j];
            if(chess[i][j] == 2)
                knight_grid[i][j] = -2;     // 기사들 영역에도 벽 표시하기
        }
    }

    for(int i=1; i<=N; i++){
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k; r--; c--;
        knights[i] = make_tuple(r, c, h, w, k);
        for(int x=r; x < r+h; x++){
            for(int y=c; y < c+w; y++){
                knight_grid[x][y] = i;      // 기사들 영역 표시하기
            }
        }
    }

}

bool InRange(int x, int y){
    return 0 <= x && x < L && 0 <= y && y < L;
}

void Move(int d){
    while(!q.empty()){
        int curr_idx = q.front();
        //cout << "현재 " << curr_idx<<"번 보고 있음" << '\n';
        q.pop();
        int x, y, h, w;
        tie(x, y, h, w, ignore) = knights[curr_idx];     // idx번 좌측 상단과 길이 받아오기
        for(int i=x; i<x+h; i++){
            for(int j=y; j < y+w; j++){
                int nx = i + dirs[d][0], ny = j + dirs[d][1];   // 연결되어 있는 다른 칸수 확인하기
                //cout << nx << ' ' << ny << '\n';
                if(InRange(nx, ny) && knight_grid[nx][ny] != curr_idx && knight_grid[nx][ny] > 0){
                    q.push(knight_grid[nx][ny]);
                    connected_knight.push_back(knight_grid[nx][ny]);
                }
                if(chess[nx][ny] == 2 || !InRange(nx, ny)){
                    //cout << "벽 만남" << '\n';
                    IsMovable = false;
                }
            }
        }
    }
    //cout << IsMovable << "IsMovable" << '\n';
}

void PushKnight(int d, int cmd_idx){
    int next_knight_grid[MAX_L][MAX_L];
    for(int i=0; i<L; i++){
        for(int j=0; j < L; j++){
            next_knight_grid[i][j] = 0;
        }
    }

    for(int i=1; i<=N; i++){
        if(IsFinished[i]) continue;
        bool IsExist = false;
        for(int j=0; j<(int)connected_knight.size(); j++){
            if(connected_knight[j] == i)
                IsExist = true;
        }
        //if(cmd_idx == 2) return;
        if(!IsExist){
            int r, c, h, w;
            tie(r, c, h, w, ignore) = knights[i];
            for(int x=r; x < r+h; x++){
                for(int y=c; y < c+w; y++){
                    next_knight_grid[x][y] = i;
                }
            }
        }
    }

    // 이제 connected_knight에 있는 말들 차례로 보면서 d방향으로 밀어내기 
    for(int i=0; i<(int)connected_knight.size(); i++){
        int cur_idx = connected_knight[i];
        //cout << cur_idx << "번 밀어내기" << '\n';
        int r, c, h,w, k;
        tie(r, c, h, w, k) = knights[cur_idx];
        r += dirs[d][0]; c += dirs[d][1];
        for(int x=r; x < r+h; x++){
            for(int y=c; y<c+w; y++){
                next_knight_grid[x][y] = cur_idx;
                if(chess[x][y] == 1 && cur_idx != connected_knight[0]){   // 함정이 있다면
                    //cout << x << ' ' << y << "에 함정 있음" << '\n';
                    k--;                // 체력 깎이고
                    damaged[cur_idx]++;
                }
            }
        }
        //cout << "체력은: " << k << '\n';
        if(k <= 0){     // 체스판에서 사라짐
            IsFinished[cur_idx] = true;
            for(int x=r; x < r+h; x++){
                for(int y=c; y<c+w; y++){
                    next_knight_grid[x][y] = 0;
                }
            }
        }
        else{
            knights[cur_idx] = make_tuple(r, c, h, w, k);
        }
    }

    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            if(knight_grid[i][j] != -2)
                knight_grid[i][j] = next_knight_grid[i][j];
        }
    }
}

void MoveKnight(int idx, int d, int cmd_idx){        // idx번 기사를 d방향으로 1칸 미는 함수
    // 1. idx번 기사와 연결된 다른 인덱스 확인하기
    IsMovable = true;
    connected_knight.clear();

    q.push(idx);
    connected_knight.push_back(idx);
    Move(d);
    //cout << IsMovable << '\n';
    if(!IsMovable)
        return;
    // 2. idx번 기사와 연결된 다른 기사들 d방향으로 1칸씩 밀기

    
    PushKnight(d, cmd_idx);
    
}

void Output(){
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(IsFinished[i]) continue;
        ans += damaged[i];
    }
    cout << ans;
}

int main() {
    // 입력 받기:
    Init();    
    
    for(int i=0; i<Q; i++){
        // << "****************" << i<<"번 명령 " << '\n';
        int id, d;
        cin >> id >> d;
        if(IsFinished[id]) continue;
        //if(i == 2) break;
        MoveKnight(id, d, i);
        //for(int i=0; i<L; i++){
        //    for(int j=0; j<L; j++){
        //        cout << knight_grid[i][j] << ' ';
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
    }

    // 출력하기:
    Output();    
    return 0;
}