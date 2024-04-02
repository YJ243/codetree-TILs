#include <iostream>
#include <queue>
#include <tuple>
#define MAX_L 50
#define MAX_N 30

using namespace std;

int L, N, Q;        // L: 체스판 크기, N: 기사들 수, Q: 명령 수
int grid[MAX_L][MAX_L];
tuple<int, int, int, int, int, int> knights[MAX_N+1];    // 기사들 정보(r, c, h, w, k, damage);
bool IsMoving[MAX_N+1];
bool IsDead[MAX_N+1];
queue<int> q;
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void Input(){               // 입력을 받는 함수
    cin >> L >> N >> Q;
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        r--; c--;
        knights[i] = make_tuple(r, c, h, w, k, 0);
        IsDead[i] = false;
    }
    //for(int i=1; i<=N; i++)

}

bool InRange(int x, int y){
    return 0 <= x && x < L && 0 <= y && y < L;
}

void Move(int id, int d){
    // 1. 먼저 grid에 기사들 표시하기 & IsMoving 초기화
    int tmp_grid[L][L] = {0,};
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            tmp_grid[i][j] = 0;
        }
    }
    for(int i=1; i<=N; i++){
        if(!IsDead[i]){
            int r, c, h, w;
            tie(r, c, h, w, ignore, ignore) = knights[i];
            for(int x=r; x<r+h; x++){
                for(int y=c; y<c+w; y++){
                    tmp_grid[x][y] = i;
                }
            }
        }
        IsMoving[i] = false;
    }

    // 2. id와 연결되어 있는 기사 찾기
    q.push(id);
    IsMoving[id] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[curr];
        //cout << r << ' ' << c << ' ' << h << ' ' << w << ' ' << k << '\n';
        for(int x=r; x<r+h; x++){
            for(int y=c; y<c+w; y++){
                //cout << x << ' ' << y << '\n';
                int a = x, b = y;       // (a,b)는 curr 기사의 한 부분
                //cout << a << ' ' << b << "는 " << curr << " 일부" << '\n';
                for(;;){
                    a += dirs[d][0]; b += dirs[d][1];
                    //cout << a << ' ' << b << "보고 있음" << '\n';
                    if(!InRange(a, b))
                        return;         // 만약 범위를 벗어나면 
                    if(tmp_grid[a][b] == 0){    // 빈칸임
                        if(grid[a][b] == 2){
                            // 그런데 벽을 만났다면
                            return;             // 움직이지 못하니 리턴
                        }
                        //cout << curr << "에서 " << a << ' ' << b << "가 빈칸임" << '\n';
                        break;
                    }   
                    
                    if(!IsMoving[tmp_grid[a][b]]){
                        IsMoving[tmp_grid[a][b]] = true;
                        q.push(tmp_grid[a][b]);
                    
                    }
                }
            }
        }
    }

    for(int i=1; i<=N; i++){

        if(!IsMoving[i]) continue;
       
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[i];
        r += dirs[d][0]; c += dirs[d][1];
        knights[i] = make_tuple(r, c, h, w, k, damage);
        if(i != id){
            for(int x=r; x<r+h; x++){
                for(int y=c; y<c+w; y++){
                    if(grid[x][y] == 1){
                        damage++;
                        k--;
                    }
                }
            }
        }
        if(k <= 0)
            IsDead[i] = true;
        knights[i] = make_tuple(r, c, h, w, k, damage);
    }
    for(int i=1; i<=N; i++){
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[i];
    }

}

void Pro(){
    // Q번의 왕의 명령 수행하기
    for(int i=0; i<Q; i++){
        //cout << i << "번째 명령: " << '\n';
        int id, d;
        cin >> id >> d;
        if(!IsDead[id])     // 아직 사라지지 않았다면
            Move(id, d);    // 명령 수행하기
    }
}

void Output(){


int tmp_grid[L][L] = {0,};
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            tmp_grid[i][j] = 0;
        }
    }
    for(int i=1; i<=N; i++){
        if(!IsDead[i]){
            int r, c, h, w;
            tie(r, c, h, w, ignore, ignore) = knights[i];
            for(int x=r; x<r+h; x++){
                for(int y=c; y<c+w; y++){
                    tmp_grid[x][y] = i;
                }
            }
        }
        IsMoving[i] = false;
    }





    int ans = 0;
    for(int i=1; i<=N; i++){
        int r, c, h, w, k, damage;
        tie(r, c, h, w, k, damage) = knights[i];
        // << i << "번의 목숨: " << k << '\n';
        if(k > 0){
            int damage;
            tie(ignore, ignore, ignore, ignore, ignore, damage) = knights[i];
            ans += damage;
        }
    }
    cout << ans;
}

int main() {
    // 입력 받기:
    Input();
    // 명령 진행하기
    Pro();

    // 출력하기
    Output();
    return 0;
}