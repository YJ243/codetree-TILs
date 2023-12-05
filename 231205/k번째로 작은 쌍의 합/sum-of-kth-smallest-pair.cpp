#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX_N 100000

using namespace std;
int n, m, k;
priority_queue<tuple<long long, int, int, int> > pq;
int arr1[MAX_N];
int arr2[MAX_N];
long long ans;
int main() {
    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        cin >> arr1[i];
    sort(arr1, arr1+n);
    for(int i=0; i<m; i++)
        cin >> arr2[i]; 
    sort(arr2, arr2+m);
    int cnt = 0;
    for(int i=0; i<n; i++){
        // 일단 수열 A의 최솟값과 B와의 조합을 넣가
        pq.push(make_tuple(-arr1[i]-arr2[0], -arr1[i],-arr2[0],0));
        //cout << arr1[0] << ' ' << arr2[i] << '\n';
    }
    int x=0, y=0, idx=0;
    while(k--){
        //cout << k << ' ';
        tie(ans, x,y,idx) = pq.top();
        x = -x; y = -y;
        pq.pop();
        //cout << x << ' ' << y << '\n';
        pq.push(make_tuple(-x-arr2[idx+1],-x, -arr2[idx+1],idx+1));
    }
    cout << -ans << '\n';

    return 0;
}