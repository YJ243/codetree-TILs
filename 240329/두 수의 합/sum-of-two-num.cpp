#include <iostream>
#include <unordered_map>
#define MAX_N 100000

using namespace std;
int n, k;
int arr[MAX_N];
unordered_map<int, int> m;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        m[arr[i]]++;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(m.find(k-arr[i]) != m.end())
            ans++;
    }
    cout << ans / 2;
    return 0;
}