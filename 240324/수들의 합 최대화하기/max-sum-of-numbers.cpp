#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10

using namespace std;
// 변수 선언
int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
int ans;
vector<int> selected;

int Calc(){
    int curr = 0;
    for(int i=0; i<(int)selected.size(); i++)
        curr += selected[i];
    return curr;
}


// 현재 색칠할 칸을 선택하는 행 번호는 idx, 계속 탐색을 이어서 진행한다.
// 첫 번재 행에 색칠할 열의 위치부터 2, 3, ..., n-1번째 행에 색칠할 열의 위치까지
// 각 열의 위치에 대한 순열을 만들어준다.
void Choose(int idx){
    // 색칠된 칸에 적힌 수들의 합 중 최댓값을 갱신한다.
    if(idx == n){
        ans = max(ans, Calc());
        return;
    }

    // 현재 행에 색칠할 열을 선택한다.
    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        visited[i] = true;
        selected.push_back(grid[idx][i]);

        Choose(idx+1);

        selected.pop_back();
        visited[i] = false;
    }
}



int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    // 합이 최대가 되도록 탐색을 진행한다.
    Choose(0);      // 0번째 행의 칸을 선택하는 함수    
    cout << ans;
    return 0;
}