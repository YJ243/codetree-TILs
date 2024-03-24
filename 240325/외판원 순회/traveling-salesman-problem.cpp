#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 10
using namespace std;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> selected;
int ans = INT_MAX;

int Calc(){
    int curr_sum = 0, curr_idx = 0;
    for(int i=0; i<(int)selected.size(); i++){
        int next_idx = selected[i];
        if(grid[curr_idx][next_idx] == 0)
            return INT_MAX;
        curr_sum += grid[curr_idx][next_idx];
        curr_idx = next_idx;
    }
    if(grid[curr_idx][0] == 0)
        return INT_MAX;
    curr_sum += grid[curr_idx][0];
    return curr_sum;
}

void Choose(int idx){   // row번째 행에서 이동할 다음 행을 선택하는 함수
    if(idx == n-1){
        ans = min(ans, Calc());
        return;
    }

    for(int i=1; i<n; i++){
        if(visited[i]) continue;

        selected.push_back(i);
        visited[i] = true;
        Choose(idx+1);

        visited[i] = false;
        selected.pop_back();
    }

}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    Choose(0);  // 0번째로 이동할 지점 고르기
    cout << ans;
    return 0;
}