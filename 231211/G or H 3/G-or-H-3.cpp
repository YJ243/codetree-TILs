#include <iostream>
#define MAX_N 100
using namespace std;
int n, k;

char arr[MAX_N+1];
int main(){
    cin >> n >> k;
    int max_idx = 0;
    for(int i=0; i<n; i++){
        int idx;
        cin >> idx >> arr[idx];
        max_idx = max(idx, max_idx);
    }
    int ans = 0;
    for(int i=1; i<=max_idx-k; i++){
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