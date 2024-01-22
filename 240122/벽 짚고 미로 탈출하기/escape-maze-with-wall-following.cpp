#include <iostream>
#include <string>
#define MAX_N 100
#define DIR_NUM 4
using namespace std;
int n;
char grid[MAX_N][MAX_N];
int r, c, curD;
int ans;
int dirs[DIR_NUM][2] = {{0,1},{-1,0},{0,-1},{1,0}};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return grid[x][y] != '#';
}

void Simulation(){
    int turn_cnt = 0;
    int firstX = r, firstY = c, firstD = curD;
    while(true){
        if(turn_cnt >= DIR_NUM){
            ans = -1;
            break;
        }
        if(ans != 0 && firstD == curD && r == firstX && c == firstY){
            ans = -1;
            break;
        }

        int nx = r + dirs[curD][0], ny = c + dirs[curD][1];
        if(!InRange(nx,ny)){    // 만약 바라보고 있는 방향으로 이동하면 탈출하는 경우
            ans++;
            break;              // 반복문 빠져나오고 미로 탈출
        }
        else{   // 이동할 곳이 격자 안인 경우
            if(!CanGo(nx,ny)){   // 만약 이동할 곳에 벽이 있는 경우
                curD = (curD+1) % DIR_NUM;  // 반 시계 방향으로 90'만큼 방향 바꾸기
                turn_cnt++;
            }
            else{       // 만약 이동할 곳이 비어있다면
                ans++;
                turn_cnt = 0;
                int wall_dir = (curD+DIR_NUM - 1) % DIR_NUM;
                int wallX = nx+dirs[wall_dir][0], wallY = ny+dirs[wall_dir][1];
                // 만약 해당 방향 기준으로 오른쪽에 짚을 벽이 있다면
                if(grid[wallX][wallY] == '#'){
                    r = nx, c = ny;
                }
                else{
                    // 만약 오른쪽에 짚을 벽이 없다면
                    curD = wall_dir;
                    ans++;
                    r = wallX, c = wallY;
                }
            }
        }
    }
}

int main() {
    // 입력:
    cin >> n;
    cin >> r >> c;
    r--; c--;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            grid[i][j] = s[j]; 
        }
    }
    Simulation();

    cout << ans;
    return 0;
}