#include <iostream>
#include <algorithm>
#define MAX_N 50
#define MAX_M 50
#define MAX_HEIGHT 100
#define DIR_NUM 4
using namespace std;

// 안전영역: K초과
int n, m;
int grid[MAX_N][MAX_N];
int ans=-1;     // 가능한 안전 영역의 최솟값이 0이므로 -1로 초기
int max_k;
bool visited[MAX_N][MAX_N];

// 탐색하는 위치가 격자 범위 내에 있는지 여부를 반환
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

// 탐색하는 위치로 움직일 수 있는지 여부 반
bool CanGo(int x, int y, int k){
    return InRange(x,y) && grid[x][y] > k && !visited[x][y];
}

// visited 배열을 초기화해주
void Initialize(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
}

void DFS(int x, int y, int k){
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    // 네 방향 각각에 대하여 DFS 탐색을 수행
    for(int i=0; i<4; i++){
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if(CanGo(nx,ny,k)){
            visited[nx][ny] = true;
            DFS(nx,ny,k);
        }
    }
}

int main() {
    int max_h = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            max_h = max(max_h, grid[i][j]);
        }
    }

    // 각 가능한 비의 높이에 대하여 안전 영역의 수를 탐색하기
    for(int k=1; k<=max_h; k++){
        // 이 부분을 GetZoneNum으로 나누
        // 새로운 탐색을 시작한다는 의미로 cur(zone 개수)을 0으로 갱신
        // visited배열 초기화
        Initialize();
        int cur = 0;

        // 격자의 각 위치에 대하여 탐색을 시작할 수 있는 경우
        // 해당 위치로부터 시작한 DFS 탐색을 수행
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(CanGo(i,j,k)){
                    // 해당 위치를 탐색할 수 있는 경우 visited 배열을 갱신하고
                    // 안전 영역을 하나 추가해주
                    visited[i][j] = true;
                    cur++;
                    DFS(i,j,k);
                }
            }
        }
        // 기존 최대 영역의 수(ans)보다 클(cur) 경우 이를 갱신하고 인덱스(k)를 저장
        if(ans < cur){
            ans = cur;
            max_k = k;
        }
    }

    cout << max_k << ' ' << ans;
    return 0;
}