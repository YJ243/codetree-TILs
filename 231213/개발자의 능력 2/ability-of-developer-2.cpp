#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int arr[6];
int ans = INT_MAX;
int main() {
    int total = 0;
    for(int i=0; i<6; i++){
        cin >> arr[i];
        total += arr[i];
    }
    
    for(int i=0; i<6; i++){
        for(int j=i+1; j<6; j++){
            for(int k=0; k<6; k++){
                for(int l=k+1; l<6; l++){
                    if(k == i || k == j || l == i || l == j) continue;
                    int sum[3];
                    sum[0] = arr[i]+arr[j];
                    sum[1] = arr[k]+arr[l];
                    sum[2] = total-sum[0]-sum[1];
                    sort(sum, sum+3);
                    ans = min(ans, sum[2]-sum[0]);

                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}