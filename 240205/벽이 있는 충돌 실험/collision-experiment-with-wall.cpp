#include <iostream>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, T;
int grid[MAX_N][MAX_N];
pair<int, int> marble[MAX_N][MAX_N];
pair<int, int> next_count[MAX_N][MAX_N];
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};   // 상 <-> 하, 좌 <=> 우 (2를 더하기)

void Initialize(){      // next_count 배열을 초기화하는 함수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            next_count[i][j].first = 0, next_count[i][j].second = 0;
        }
    }
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n; 
}

void Move(int x, int y, int d){    // (x,y)를 d 방향으로 움직이는 함수
    // 1. 다음에 움직일 좌표 구하기
    int nx = x+dirs[d][0], ny = y+dirs[d][1];
    // 2-1. 만약 다음 좌표가 범위 안에 있다면
    if(InRange(nx,ny)){
        next_count[nx][ny].first++;
        next_count[nx][ny].second = d;
        //cout << x << ' ' << y << ' ' << d << ' '<<nx << ' ' << ny << ' ' << d << '\n';
    }
    // 2-2. 만약 범위를 벗어난다면
    else{
        // 방향을 바꿔서 이동

        int next_d = (d+2)%4;
        next_count[x][y].first++;
        next_count[x][y].second = next_d;
        /*
        nx = x+dirs[next_d][0], ny = y+dirs[next_d][1];
        //cout << x << ' ' << y << ' ' << d << ' '<<nx << ' ' << ny << ' ' << next_d << '\n';
        next_count[nx][ny].first++;
        next_count[nx][ny].second = next_d;
        */
    }

}

void Simulate(){
    // 0. next_count 배열 초기화
    Initialize();

    // 1. 구슬이 있다면 이동시키기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(marble[i][j].first == 1){
                Move(i,j, marble[i][j].second);
            }
        }
    }
    // 2. next_count에서 구슬이 2개 이상 있다면 없애기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(next_count[i][j].first > 1){
                next_count[i][j].first = 0, next_count[i][j].second = 0;
            }
        }
    }
    // 3. next_count를 marble로 옮기기   
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            marble[i][j].first = next_count[i][j].first;
            marble[i][j].second = next_count[i][j].second;
        }
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << marble[i][j].first << ' ' ;

        }
        cout << '\n';
    }
    cout << '\n';
    */
}

int GetDirectionNumber(char d){     // 입력값이 d에 해당하는 방향 정보 넘기기
    int ret = 0;
    if(d == 'U') ret = 0;
    else if(d == 'D') ret = 2;
    else if(d == 'R') ret = 1;
    else ret = 3;

    return ret;
}

int main() {
    cin >> T;
    for(int i=0; i<T; i++){
        // 변수 입력받기
        cin >> n >> m;
        while(m--){     // m개의 구슬 입력받
            int x, y; char d;
            cin >> x >> y >> d;
            marble[x-1][y-1] = make_pair(1, GetDirectionNumber(d));
        }
        // 시뮬레이션 시작
        int test_cnt = 1000000;
        while(test_cnt--)
            Simulate();
        
        
        // 출력:
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(marble[i][j].first == 1){
                    ans++;  // 남아있는 구슬의 개수 세기
                }
            }
        }
        cout << ans << '\n';
    }


    return 0;
}