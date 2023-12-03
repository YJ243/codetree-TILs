#include <iostream>
#include <unordered_map>
#define MAX_N 1000

using namespace std;

int n, k;
int arr[MAX_N];
unordered_map<int, int> cnt;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        cnt[arr[i]]--;
        for(int j=0; j<i; j++){

            int diff = k-arr[i]-arr[j];
            ans += cnt[diff];
        }
    }
    cout << ans;

}