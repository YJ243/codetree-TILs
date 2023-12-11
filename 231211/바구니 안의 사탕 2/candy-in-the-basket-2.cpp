#include <iostream>
#define MAX_N 100
using namespace std;

int n, k;
int arr[MAX_N+1];

int ans;

int main() {
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int cnt, idx;       // cnt: 사탕 개수, idx: 바구니 좌표
        cin >> cnt >> idx;
        arr[idx] += cnt;    // 해당 바구니 좌표에 사탕 넣기
    }


    for(int i=0; i<=MAX_N; i++){
        //cout << i-k << ' '<< i << ' ' << i+k << '\n';
        // 중심점은 i, 구간 안에서 사탕 개수 구하기 (i-k ~ i+k, 2k+1)
        int cur_cnt=0; 
        for(int j=i-k; j<=i+k; j++){
            if(0 <= j && j <= MAX_N){        // j가 범위 안에 있을 경우에만 더해주기
                cur_cnt += arr[j];
            }
        }
        ans = max(cur_cnt, ans);
    }
    
    cout << ans << '\n';

    return 0;
}