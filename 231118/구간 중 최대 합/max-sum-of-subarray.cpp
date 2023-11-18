#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int n, k;
int arr[MAX_N];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int ans = 0;
    for(int i=0; i<=n-k; i++){
        int sum = 0;
        for(int j=i; j<i+k; j++){
            sum += arr[j];
        }
        ans = max(sum, ans);
    }
    cout << ans;
    return 0;
}