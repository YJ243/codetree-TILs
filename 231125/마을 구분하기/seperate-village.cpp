#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 25
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int person;
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !visited[x][y] && arr[x][y];
}

void dfs(int x, int y){
    int dirs[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    for(int i=0; i<4; i++){
        int nx = x+dirs[i][0], ny = y+dirs[i][1];
        if(CanGo(nx,ny)){
            person++;
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j]; // 사람:1, 벽:0
        }
    }

    int village_cnt = 0;
    vector<int> people;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // (i,j)부터 시작하는데
            if(!visited[i][j] && arr[i][j]){
                // 만약 방문하지 않은 사람 만났다면
                visited[i][j] = true;
                person = 1;
                village_cnt++;
                dfs(i,j);   // 그 격자점에서 방문 진행
                people.push_back(person);
            }
        }
    }
    cout << village_cnt << '\n';
    sort(people.begin(), people.end());
    for(auto p : people){
        cout << p << '\n';
    }
    
    return 0;
}