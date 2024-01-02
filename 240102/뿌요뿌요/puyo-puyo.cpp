#include <iostream>
#include <vector>
#define MAX_N 100
using namespace std;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> blocks;
int ans;
int cur_block;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int k){
    return InRange(x,y) && !visited[x][y] && grid[x][y] == k;
}

void DFS(int x, int y, int k){
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int d=0; d<4; d++){
        int nx = x + dirs[d][0], ny = y + dirs[d][1];
        if(CanGo(nx,ny,k)){
            visited[nx][ny] = true;
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

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                // 만약 방문하지 않았다면
                cur_block = 1;
                visited[i][j] = true;
                DFS(i, j, grid[i][j]);
                blocks.push_back(cur_block);
            }
        }
    }
    int max_block = 0;
    for(int i=0; i<(int) blocks.size(); i++){
        if(blocks[i] >= 4) ans++;
        max_block = max(max_block, blocks[i]);
    }

    cout << ans << ' ' << max_block;
    
    return 0;
}