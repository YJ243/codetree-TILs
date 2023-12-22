#include <iostream>
#include <algorithm>
#define MAX_N 100
#define MAX_M 10000

using namespace std;

int n,m;
int arr[MAX_N+1];
int ans;

int main() {
    // 입력
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    // 시작위치를 0부터 끝까지 확인해보는데 합이 최대가 된다면?
    // 어느 지점에서 시작할 지 전부 시도해보기
    // 모든 경우의 수에 대해 최대가 되도록 하는 수를 계산
    for(int i=1; i<=n; i++){
        // 시작점은 i
        int curCnt = m-1, curSum = arr[i], cur_idx = i;
        while(curCnt--){
            curSum += arr[arr[cur_idx]];
            cur_idx = arr[cur_idx]; 
        }
        ans = max(ans, curSum);
    }
    cout << ans;
    return 0;
}