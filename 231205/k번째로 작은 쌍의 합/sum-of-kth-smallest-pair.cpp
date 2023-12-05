#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX_N 100000

using namespace std;
int n, m, k;
priority_queue<tuple<long long, int,int> > pq;
int arr1[MAX_N];
int arr2[MAX_N];
long long ans;
int main() {
    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        cin >> arr1[i];
    //sort(arr1, arr1+n);
    for(int i=0; i<m; i++)
        cin >> arr2[i]; 
    //sort(arr2, arr2+m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            pq.push(make_tuple(-arr1[i]-arr2[j],-arr1[i], -arr2[j]));
        }
    }

    while(k--){
        tie(ans, ignore, ignore) = pq.top();
        pq.pop();
    }
    cout << -ans << '\n';
    /*
    if(k%2 == 0){
        int idx = (k/2)-1;
        cout << idx << ' ';
        ans = (long long)arr1[idx]+arr2[idx];
    }
    else{
        int idx1 = (k/2)-1;
        int idx2 = k-idx1-1;
        if(arr1[idx1]+arr2[idx2] > arr1[idx2]+arr2[idx1]){
            ans = arr1[idx2]+arr2[idx1];
        }
        else{
            ans = arr1[idx1]+arr2[idx2];
        }
    }
    cout << ans << '\n';
    */
    return 0;
}