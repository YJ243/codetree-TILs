#include <iostream>
#include <queue>
#define MAX_N 100
using namespace std;

int n, k;   // n: 격자 크기, k: 반복할 횟수
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int r, c;
int maxI, maxJ, maxNum;
queue<pair<int, int> > q;
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
    // 범위 안에 있고, 방문한 적이 없고, 기준 값보다 작을 경우 이동 가
    return InRange(x,y) && !visited[x][y] && grid[x][y] < std_num;
}

void BFS(int std_num){
    //int maxI, maxJ, maxNum;
    int dirs[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; // 위,왼,아래,오
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
                if(maxNum < grid[nx][ny]){
                    maxI = nx, maxJ = ny, maxNum = grid[nx][ny];
                }
                else if((maxNum == grid[nx][ny]) && (maxI > nx || (maxI == nx && maxJ > ny))){
                    maxI = nx, maxJ = ny, maxNum = grid[nx][ny];
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    cin >> r >> c;
    r--; c--;
    while(k--){
        // 종료 조건: 더이상 새로 이동할 위치가 없다면
        Initialize();
        // 탐색 시작
        visited[r][c] = true;
        q.push(make_pair(r,c));
        BFS(grid[r][c]);
        if(maxI == r && maxJ == c) break;
        r = maxI, c = maxJ;
    }
    cout << r+1 << ' ' << c+1;
    return 0;
}