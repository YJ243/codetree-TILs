#include <iostream>
#include <unordered_map>
#include <algorithm>

#define MAX_N 100
using namespace std;


int n, k;
int arr[MAX_N];
bool bombed[MAX_N];
unordered_map<int, int> cnt;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<=min(i+k, n-1); j++){
            if(arr[i] == arr[j]){
                bombed[i] = true;
                bombed[j] = true;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(bombed[i])
            cnt[arr[i]]++;
    }
    int max_cnt = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(bombed[i]){
            if(max_cnt < cnt[arr[i]]){
                max_cnt = cnt[arr[i]];
                ans = arr[i];
            }
        }
    }
    if(max_cnt == 0)
        cout << 0;
    else
        cout << ans;
    return 0;
}