#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 25
using namespace std;
int n;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

vector<int> people;
int person_cnt;
int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 위, 우, 하, 좌
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    // 범위 안에 있고, 아직 방문하지 않았고, 사람이 있는 경우
    return InRange(x,y) && !visited[x][y] && arr[x][y];
}

void DFS(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if(CanGo(nx,ny)){
            visited[nx][ny] = true;
            person_cnt++;
            DFS(nx,ny);
            
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];   // 사람: 1, 벽: 0
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // (i,j)를 시작으로 DFS를 돌기

            if(arr[i][j] && !visited[i][j]){
                person_cnt = 1;
                visited[i][j] = true;
                DFS(i,j);
                people.push_back(person_cnt);
            }
        }
    }
    int village_cnt = (int)people.size();
    sort(people.begin(), people.end());
    cout << village_cnt << '\n';
    for(int i=0; i<village_cnt; i++){
        cout << people[i] << '\n';
    }
    return 0;
}