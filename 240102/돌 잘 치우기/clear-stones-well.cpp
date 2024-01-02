#include <iostream>
#include <queue>
#define MAX_N 100

using namespace std;

int n, k, m;    // n: 격자 크기, k: 시작점 개수, m: 치울 돌 개수
queue<pair<int, int> > q;

int grid[MAX_N][MAX_N];             // 격자
bool visited[MAX_N][MAX_N];         // 방문 확인 배열
int start[MAX_N*MAX_N][2];          // 모든 시작점
vector<pair<int, int> > stones;     // 돌이 들어있는 좌표들 저장
vector<pair<int, int> > removed;     // 현재 턴에서 치워야할 돌
int ans;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && !grid[x][y] && !visited[x][y];
}

void do_remove(){
    for(int i=0; i<(int)removed.size(); i++){
        int cx = removed[i][0], cy = removed[i][1];
        grid[cx][cy] = 0;
    }
}

void do_recover(){
    for(int i=0; i<(int)removed.size(); i++){
        int cx = removed[i][0], cy = removed[i][1];
        grid[cx][cy] = 1;
    }
}
void choose_stone(int t, int index){   // t번째 돌을 고르는 함수, index는 현재 stones 벡터에서 선택할 시작
    if(t == m){
        // 만약 m개를 다 골랐다면
        // 그 돌들 치우고 bfs 탐색하여 이동한 칸 수 세기
        do_remove();
        for(int i=0; i<(int)removed.size(); i++)
            cout << removed[i][0] << ' ' << removed[i][1] << '\n';
        bfs();
        do_recover();
        return;
    }

    for(int i=index; i<(int) stones.size(); i++){
        // 돌을 하나 선택
        removed.push_back(make_pair(stones[i][0], stones[i][1]));
        // 다음 돌 선택
        choose_stone(t+1, i+1);
        // 선택 취소
        removed.pop_back();
    }


}

int main() {
    // 입력:
    cin >> n >> k >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];  // 0: 이동 가능, 1: 이동X
            if(grid[i][j])
                stones.push_back(make_pair(i,j));   // 만약 돌이 있다면 좌표 저장
        }
    }
    // 시작점 저장
    for(int i=0; i<k; i++){
        cin >> start[i][0] >> start[i][1];
        start[i][0]--; start[i][1]--;
    }

    // stones 중에서 m개 돌을 backtracking으로 고르기
    choose_stone(0,0);    // 0번째 stone 고르는 함수
    for(int i=0; i<(int)stones.size(); i++){
    // 2. 그리고 
    // 3. ans와 비교해서 업데이트 하기
    }
    return 0;
}