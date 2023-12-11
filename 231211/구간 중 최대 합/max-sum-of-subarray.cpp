#include <iostream>
#define MAX_N 100
using namespace std;

int n, k;
int arr[MAX_N];
int ans;
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    // 모든 구간의 시작점을 잡아보기
    for(int i=0; i<=n-k; i++){
        // 해당 구간 내 원소의 합을 구하기
        int cur_sum = 0;
        for(int j=i; j<i+k; j++){
            cur_sum += arr[j];
        }
        // 최댓값 구하기
        ans = max(cur_sum, ans);
    }
    cout << ans;
    return 0;
}