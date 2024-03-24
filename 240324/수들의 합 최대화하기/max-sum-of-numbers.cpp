#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10

using namespace std;
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

void Choose(int idx){
    if(idx == n){
        ans = max(ans, Calc());
        return;
    }

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
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    Choose(0);      // 0번째 행의 칸을 선택하는 함수    
    cout << ans;
    return 0;
}