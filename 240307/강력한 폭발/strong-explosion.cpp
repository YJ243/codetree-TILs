#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 20

using namespace std;

int n;
int grid[MAX_N][MAX_N];
int bomb_cnt;
vector<pair<int, int> > bomb;
vector<int> selected_bomb;
int bomb_dir[3][4][2] = {
    {{-1,0},{-2,0},{1,0},{2,0}},
    {{-1,0},{0,1},{1,0},{0,-1}},
    {{-1,-1},{-1,1},{1,-1},{1,1}}
};

int ans;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void DoBomb(){
    // selected_bomb
    for(int i=0; i<bomb_cnt; i++){
        int x = bomb[i].first, y = bomb[i].second;
        int bomb_idx = selected_bomb[i];
        for(int d=0; d<4; d++){
            int nx = x + bomb_dir[bomb_idx][d][0];
            int ny = y + bomb_dir[bomb_idx][d][1];
            if(InRange(nx, ny)){
                grid[nx][ny] = 1;
            }
        }
    }

}

void Calculate(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt += grid[i][j];
        }
    }
    ans = max(ans, cnt);
}

void UnDoBomb(){
    for(int i=0; i<bomb_cnt; i++){
        int x = bomb[i].first, y = bomb[i].second;
        int bomb_idx = selected_bomb[i];
        for(int d=0; d<4; d++){
            int nx = x + bomb_dir[bomb_idx][d][0];
            int ny = y + bomb_dir[bomb_idx][d][1];
            if(InRange(nx, ny)){
                grid[nx][ny] = 0;
            }
        }
    }
    for(int i=0; i<bomb_cnt; i++){
        int x = bomb[i].first, y = bomb[i].second;
        grid[x][y] = 1;
    }
}

void Choose(int idx){   // 폭탄 idx번째 선택하는 함수
    if(idx == bomb_cnt){
        DoBomb();
        Calculate();
        UnDoBomb();
        return;
    }

    for(int i=0; i<3; i++){
        selected_bomb.push_back(i);
        Choose(idx+1);
        selected_bomb.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j]){
                bomb_cnt++;     // 폭탄 개수 증가
                bomb.push_back(make_pair(i, j));
            }
        }

    Choose(0);
    cout << ans;
    return 0;
}