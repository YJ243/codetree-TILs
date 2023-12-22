#include <iostream>
#include <algorithm>
#define MAX_N 100
#define MAX_M 10000

using namespace std;

int n,m;
int arr[MAX_N+1];
int ans;

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    // 시작위치를 0부터 끝까지 확인해보는데 합이 최대가 된다면?
    for(int i=1; i<=n; i++){
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