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

// 탐색하는 위치가 격자 내에 있는지 여부를 반환
bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}
// 탐색하는 위치로 움직일 수 있는지 여부를 반환
bool CanGo(int x, int y){
    // 범위 안에 있고, 아직 방문하지 않았고, 사람이 있는 경우
    return InRange(x,y) && !visited[x][y] && arr[x][y];
}

void DFS(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if(CanGo(nx,ny)){
            visited[nx][ny] = true;
            // 마을에 존재하는 사람을 한 명 추가해주기
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

    // 격자의 각 위치에서 탐색을 시작할 수 있는 경우
    // 한 마을에 대한 DFS 탐색을 수행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // (i,j)를 시작으로 DFS를 돌기
            if(arr[i][j] && !visited[i][j]){    // CanGo(i,j) 로 바꿔도 됨
                // 해당 위치를 방문할 수 있는 경우 visited 배열을 갱신하고
                // 새로운 마을을 탐색한다는 의미로 people_cnt를 1로 갱신
                person_cnt = 1;
                visited[i][j] = true;
                DFS(i,j);

                // 한 마을에 대한 탐색이 끝난 경우 마을 내의 사람 수 저장
                people.push_back(person_cnt);
            }
        }
    }
    // 각 마을 내의 사람 수를 오름차순으로 정렬
    sort(people.begin(), people.end());

    int village_cnt = (int)people.size();
    
    cout << village_cnt << '\n';
    
    for(int i=0; i<village_cnt; i++){
        cout << people[i] << '\n';
    }
    return 0;
}