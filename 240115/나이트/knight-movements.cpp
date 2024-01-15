#include <iostream>
#include <queue>
#define MAX_N 100
using namespace std;

int n;

bool visited[MAX_N][MAX_N];
queue<pair<int, int> > q;
int step[MAX_N][MAX_N];
int dirs[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int r1, c1, r2, c2;
int ans = -1;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y];
}

void Push(int x, int y, int d){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    step[x][y] = d;
}

void bfs(){
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<8; i++){
            int nx = curr.first + dirs[i][0], ny = curr.second + dirs[i][1];
            if(CanGo(nx,ny)){
                Push(nx,ny,step[curr.first][curr.second]+1);
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;c1--;r2--;c2--;
    Push(r1, c1, 0);
    bfs();

    if(visited[r2][c2])
        ans = step[r2][c2];

    cout << ans;
    return 0;
}