#include <iostream>
#define MAX_N 100
using namespace std;

int n, m, k;                // n: 격자 크기, m: 사과 개수, k: 뱀 방향 변환 횟수
int grid[MAX_N][MAX_N];     // 0: 빈칸, 1: 뱀 머리, 2: 뱀 몸통과 꼬리, 3: 사과
int sX, sY;                 // (sX, sY): 뱀의 시작 머리 좌표
int eX = -1, eY = -1;       // (eX, eY): 뱀의 마지막 꼬리 좌표
int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}}; // 위,아래,우,좌 순서
int ans;

int GetDirection(char d){
    if(d == 'U') return 0; 
    else if(d == 'D') return 1;
    else if(d == 'R') return 2;
    else return 3;
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 입력:
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = 3;
    }
    grid[0][0] = 1;
    // 시뮬레이션 시작
    for(int i=0; i<k; i++){
        // 뱀의 방향 전환 정보 입력받기
        char dir_info;
        int p, curD;
        cin >> dir_info >> p;
        curD = GetDirection(dir_info);
        
        // 이제 p만큼 움직이면서 확인해보기
        for(int d=1; d <= p; d++){
            ans++;      // 1초 증가
            // (nx,ny)는 뱀의 머리가 이동할 다음 위치임
            int nx = sX+dirs[curD][0], ny = sY+dirs[curD][1];
            // 만약 움직이는 도중에 격자를 벗어나면 종료
            if(!InRange(nx, ny)){
                cout << ans;
                return 0;
            }
            // 움직일 위치가 범위 안에 있다면
            else{
                // 1. 만약 몸이 꼬여 서로 겹쳐졌을 경우
                if(grid[nx][ny] == 1 || grid[nx][ny] == 2){
                    cout << ans;
                    return 0;
                }
                // 2. 만약 사과라면
                else if(grid[nx][ny] == 3){
                    grid[nx][ny] = 1;   // 사과 자리에 머리 옮기기
                    grid[sX][sY] = 2;   // 머리 있던 자리는 몸통으로 만들기
                    if(eX == -1 && eY == -1){
                        // 만약 처음 사과를 만났다면
                        eX = sX, eY = sY;   // 머리 있던 자리를 꼬리로 옮기기
                    }
                    sX = nx, sY = ny;   // 시작 위치 옮기기
                }
                // 3. 만약 빈칸이라면
                else{
                    grid[nx][ny] = 1;   // 빈칸에 머리 옮기기
                    if(eX == -1 && eY == -1){
                        // 만약 꼬리가 없다면
                        grid[sX][sY] = 0;
                        sX = nx, sY = ny;
                    }
                    else{
                        // 꼬리가 있었다면
                        grid[sX][sY] = 2;   // 머리 있던 자리는 몸통으로 만들기
                        // 꼬리 있던 자리를 0으로 만들고 꼬리 이전 몸통으로 옮기기
                        for(int dd=0; dd<4; dd++){
                            if(InRange(eX+dirs[dd][0], eY+dirs[dd][1]) && grid[eX+dirs[dd][0]][eY+dirs[dd][1]] == 2){
                                // 범위 안에 있고, 꼬리랑 붙어 있는 곳이라면
                                grid[eX][eY] = 0;
                                eX = eX+dirs[dd][0], eY = eY+dirs[dd][1];
                            }
                        }
                    }
                    sX = nx, sY = ny;
                }

            }
        }
    }
    cout << ans;
    return 0;
}