#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 10

using namespace std;

vector<int> selected;
int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
int ans = INT_MAX;
void FindMinCost(){
    int currCost = 0, curNum = 0;
    bool Movable = true;
    for(int i=0; i<(int)selected.size(); i++){
        if(grid[curNum][selected[i]] == 0){
            Movable = false;
        }
        currCost += grid[curNum][selected[i]];
        curNum = selected[i];
    }
    currCost += grid[curNum][0];
    if(grid[curNum][0] == 0) Movable = false;
    if(Movable)
        ans = min(ans, currCost);
}

void Choose(int num){
    if(num == n){
        FindMinCost();
        return;
    }

    for(int i=1; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        selected.push_back(i);

        Choose(num+1);

        visited[i] = false;
        selected.pop_back();
    }
}

int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    Choose(1);      // 1다음 첫 번째로 이동할 번호를 고르는 함수    
    cout << ans;
    return 0;
}