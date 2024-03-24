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
    int curr = 0;
    for(int i=0; i<(int)selected.size(); i++)
        curr += selected[i];
    return curr;
}

void Choose(int row){   // row번째 행에서 이동할 다음 행을 선택하는 함수
    if((int)selected.size() == n){
        ans = min(ans, Calc());
        return;
    }

    for(int i=0; i<n; i++){
        if(row == i || grid[row][i] == 0)
            continue;
        if(visited[i]) continue;

        visited[i] = true;
        selected.push_back(grid[row][i]);

        Choose(row+1);

        selected.pop_back();
        visited[i] = false;

    }

}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    Choose(0);
    cout << ans;
    return 0;
}