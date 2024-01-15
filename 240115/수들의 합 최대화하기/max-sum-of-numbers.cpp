#include <iostream>
#include <vector>
#define MAX_N 10

using namespace std;

int n;
int arr[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> columnNum;
int ans;

void FindMaxSum(){
    int curSum = 0;
    for(int i=0; i<n; i++){
        curSum += arr[i][columnNum[i]];
    }
    ans = max(ans, curSum);
}
void Choose(int row, int num){
    if(row == n){
        FindMaxSum();
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        visited[i] = true;
        columnNum.push_back(i);

        Choose(row+1, num+1);

        visited[i] = false;
        columnNum.pop_back();
    }
}
int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    Choose(0,0);    // 0번째 줄에서 0번째 숫자를 선택하는 함수
    cout << ans;
    return 0;
}