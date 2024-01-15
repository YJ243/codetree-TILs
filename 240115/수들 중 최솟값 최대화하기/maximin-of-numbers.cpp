#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 10
using namespace std;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> selected;
int ans;
void FindMinMax(){
    int currMin = 10000;
    for(int i=0; i<n; i++){
        currMin = min(currMin, grid[i][selected[i]]);
    }
    ans = max(ans, currMin);
}

void Choose(int row){
    if(row == n){
        FindMinMax();
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        selected.push_back(i);

        Choose(row+1);

        visited[i] = false;
        selected.pop_back();
    }
}

int main() {
    cin >> n;    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    Choose(0);  // 0번째 행에서 열을 선택하는 함수
    cout << ans;
    return 0;
}