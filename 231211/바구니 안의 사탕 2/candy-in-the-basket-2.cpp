#include <iostream>
#define MAX_N 100
using namespace std;

int n, k;
int arr[MAX_N];
int ans;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int idx, cnt;
        cin >> cnt >> idx;
        arr[idx] += cnt;
        
    }

    for(int i=k; i<MAX_N-k; i++){
        int cur_cnt=0;
        for(int j=i-k; j<=i+k; j++){
            cur_cnt += arr[j];
        }
        ans = max(cur_cnt, ans);
    }
    cout << ans << '\n';
    return 0;
}