#include <iostream>
#include <climits>

#define MAX_N 1000

using namespace std;
int n;
int arr[MAX_N];

int main(){
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int ans = INT_MAX;
    
    // 크기가 17인 모든 구간을 잡아 해당 구간 안에 들어오게 언덕을 깎고
    // 그 비용 중 최솟값을 계산
    for(int i=0; i<=100-17; i++){
        // 최대~최소 범위는 [i ~ i+17]까지임
        // i+17보다 높은 언덕은 높이가 i+k가 되게 깎고,
        // i보다 낮은 언덕은 높이가 i가 되게 쌓으면 됨
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