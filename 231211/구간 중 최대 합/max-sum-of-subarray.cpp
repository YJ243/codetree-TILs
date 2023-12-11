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
    
    for(int i=0; i<=n-k; i++){
        int cur_sum = 0;
        for(int j=i; j<i+k; j++){
            cur_sum += arr[j];
        }
        ans = max(cur_sum, ans);
    }
    cout << ans;
    return 0;
}