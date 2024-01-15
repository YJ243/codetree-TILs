/*
 * Backtracking을 사용해 0부터 n-1번 행까지 순서대로 어떤 열을 색칠해야 하는지 가능한 모든 순열 탐색
 * 가능한 모든 순열: N!, 순열 만든 이후 각각 n개의 색칠된 칸을 보며 수들의 합을 구해줘야 함
 * 시간복잡도: O(N!*N)
*/
#include <iostream>
#include <vector>
#define MAX_N 10

using namespace std;

// 변수 선언
int n;
int arr[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> columnNum;
int ans;

// 합을 구해주는 함수
void FindMaxSum(){
    int curSum = 0;
    for(int i=0; i<n; i++){
        curSum += arr[i][columnNum[i]];
    }
    // 답을 갱신
    ans = max(ans, curSum);
}

// 현재 색칠하기 위해 선택할 행을 row, num번째 숫자 고름
// 계속 탐색을 이어서 진행
// 0 번째 행에 색칠할 열의 위치부터
// 두 번째, 세 번째, ... n-1번째 행에 색칠할 열의 위치까지
// 각 열의 위치에 대한 순열 만들어 줌
void Choose(int row, int num){
    // 색칠된 칸에 적힌 수들의 합 중 최댓값 갱신
    if(row == n){
        FindMaxSum();
        return;
    }

    // 현재 행에 색칠할 열을 선택
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

    // 합이 최대가 되도록 탐색 진행
    Choose(0,0);    // 0번째 줄에서 0번째 숫자를 선택하는 함수
    cout << ans;
    return 0;
}