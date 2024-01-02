#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

vector<int> blocks;
int ans;
int cur_block;

// 탐색하는 위치가 격자 범위 내에 있는지 여부를 반환
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 탐색하는 위치로 움직일 수 있는지 여부를 반환
bool CanGo(int x, int y, int k){
    return InRange(x,y) && !visited[x][y] && grid[x][y] == k;
}

void DFS(int x, int y, int k){
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    // 네 방향 각각에 대하여 DFS 탐색을 하기
    for(int d=0; d<4; d++){
        int nx = x + dirs[d][0], ny = y + dirs[d][1];
        if(CanGo(nx,ny,k)){
            visited[nx][ny] = true;
            // 블럭이 하나 추가됨
            cur_block++;
            DFS(nx,ny,k);
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    // 격자의 각 위치에서 탐색을 시작할 수 있는 경우
    // 한 블럭에 대한 DFS 탐색 수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                // 만약 방문하지 않았다면
                // 해당 블럭을 방문할 수 있음 => visited 배열 갱신하고
                // 새로운 블럭을 탐색한다는 의미로 cur_block을 1로 갱신
                visited[i][j] = true;
                cur_block = 1;

                DFS(i, j, grid[i][j]);

                blocks.push_back(cur_block);
            }
        }
    }

    // 이렇게 vector에다가 넣어도 되지만, DFS를 수행하고 바로바로 
    // 4보다 큰지, 그리고 최대 block개수는 몇인지 갱신해도 됨
    int max_block = 0;
    for(int i=0; i<(int) blocks.size(); i++){
        if(blocks[i] >= 4) ans++;
        max_block = max(max_block, blocks[i]);
    }

    cout << ans << ' ' << max_block;
    
    return 0;
}