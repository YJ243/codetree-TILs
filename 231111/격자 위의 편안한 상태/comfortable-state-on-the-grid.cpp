#include <iostream>
#define MAX_N 100
using namespace std;
int N, M;
int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 위, 아래, 왼쪽, 오른쪽
int maze[MAX_N][MAX_N];
bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool IsComfort(int x, int y){
    int cnt=0;
    for(int i=0; i<4; i++){
        int nx = x+dirs[i][0], ny = y+dirs[i][1];
        if(InRange(nx,ny) && maze[nx][ny])  cnt++;
    }
    if(cnt==3)
        return true;
    else    return false;
}
int main() {
    cin >> N >> M;
    while(M--){
        int r, c;
        cin >> r >> c;
        r--; c--;
        maze[r][c] = 1;
        if(IsComfort(r,c)){
            cout<< 1<<'\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    return 0;
}