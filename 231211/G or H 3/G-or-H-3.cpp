// 실수 1: MAX_LOC를 MAX_N으로 적음
// 실수 2: k가 최대 범위보다 크게 주어질 경울를 생각 못
#include <iostream>
#define MAX_LOC 10000
using namespace std;
int n, k;

char arr[MAX_LOC+1];
int main(){
    cin >> n >> k;
    int max_idx = 0;
    for(int i=0; i<n; i++){
        int idx;
        cin >> idx >> arr[idx];
        max_idx = max(idx, max_idx);
    }


    int ans = 0;
    for(int i=1; i<=MAX_LOC-k; i++){
        int cur=0;
        for(int j=i; j<=i+k; j++){
            if(arr[j] == 'G') cur += 1;
            else if(arr[j] == 'H') cur+= 2;
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}