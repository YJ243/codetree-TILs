#include <iostream>
#include <algorithm>

#define MAX_N 1000
#define MAX_K 10000

using namespace std;

int n, k;   // n: 원소의 개수, k: 최대로 차이날 수 있는 값
int a[MAX_N];
int ans;
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        // a[i]가 최소라고 가정
        int cnt = 1;
        for(int j=i+1; j<n; j++){
            if(a[j]-a[i] <= k)  cnt++;
            else    break;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}