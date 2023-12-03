#include <iostream>
#include <unordered_map>
#define MAX_N 100000
using namespace std;

int n;      // n: 정수 개수
int k;   // 두 수의 합
int arr[MAX_N];
unordered_map<long long, int> m;

int main(){
    cin >> n >> k;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        long long diff = (long long)k-arr[i];
        ans += m[diff];

        m[arr[i]]++;
    }
    cout << ans << '\n';
    return 0;
}