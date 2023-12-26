#include <iostream>
#include <climits>

#define MAX_N 1000

using namespace std;
int n;
int arr[MAX_N];

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int ans = INT_MAX;
    for(int i=0; i<=100-17; i++){
        // 최대~최소 범위는 i ~ i+17까지임
        int cost = 0;
        for(int j=0; j<n; j++){
            if(arr[j] < i){
                cost += (i-arr[j])*(i-arr[j]); 
            }
            else if(arr[j] > i+17)
                cost += (arr[j]-(i+17))*(arr[j]-(i+17));
        }
        ans = min(cost, ans);
    }
    cout << ans;
    return 0;
}