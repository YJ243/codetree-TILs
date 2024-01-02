#include <iostream>
#include <queue>
#define MAX_N 100
using namespace std;

int n, k;                   // n: 격자 크기, k: 반복할 횟수
int grid[MAX_N][MAX_N];     // 격자
bool visited[MAX_N][MAX_N]; // 방문 확인 배열
int r, c;                   // 초기 위치
int maxI, maxJ, maxNum;     // 이동할 좌표
queue<pair<int, int> > q;   // bfs를 위한 

void Initialize(){
    // 방문 배열 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
    // 현재 턴에서 갈 수 있는 곳의 숫자 초기화 
    maxNum = 0;
}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int std_num){
    // 범위 안에 있고, 방문한 적이 없고, 기준 값보다 작을 경우 이동 가능
    return InRange(x,y) && !visited[x][y] && grid[x][y] < std_num;
}

void BFS(int std_num){      // 조건을 만족하는 탐색 진행, std_num을 기준으로 작은 곳으로만 이동 가능
    int dirs[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; // 위,왼,아래,오 방향
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int d=0; d<4; d++){
            int nx = cur.first + dirs[d][0];
            int ny = cur.second + dirs[d][1];
            if(CanGo(nx,ny,std_num)){
                // 만약 이동할 수 있다면
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
                if(maxNum < grid[nx][ny]){      // maxNum: 도달할 수 있는 칸들에 적혀 있는 숫자 중 최댓값
                    maxI = nx, maxJ = ny, maxNum = grid[nx][ny];
                }
                else if((maxNum == grid[nx][ny]) && (maxI > nx || (maxI == nx && maxJ > ny))){
                    // 최댓값이 같은 것이 여러개 일 경우, 행번호가 가장 작은 것 -> 행이 같으면 열번호가 가장 작은 곳으로 
                    maxI = nx, maxJ = ny, maxNum = grid[nx][ny];
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;                  // n: 격자 크기, k: 반복할 횟수
    for(int i=0; i<n; i++){         // 격자에다가 숫자 채우기
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    cin >> r >> c;                  // 시작 위치 담기
    r--; c--;
    while(k--){                     // k번 반복
        Initialize();               // 방문 배열, 이동할 수 있는 수 중 가장 큰 수 초기화
        visited[r][c] = true;       // 시작점 방문 표시
        q.push(make_pair(r,c));     // 시작점 큐에 넣기
        BFS(grid[r][c]);            // 탐색 시작
        // 종료 조건: 더이상 새로 이동할 위치가 없다면
        if(maxI == r && maxJ == c) break;
        r = maxI, c = maxJ;         // 시작점 이동해주기
    }
    cout << r+1 << ' ' << c+1;      // 최종 위치 출
    return 0;
}