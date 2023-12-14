#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 5

using namespace std;

int arr[MAX_N];
int ans = INT_MAX;
int main() {
    int total = 0;
    for(int i=0; i<MAX_N; i++){
        cin >> arr[i];
        total += arr[i];
    }
    
    // 2명, 2명, 1명씩 팀 이루기
    // 일단 2명, 2명을 먼저 구하기
    for(int i=0; i<MAX_N; i++){
        for(int j=i+1; j<MAX_N; j++){
            for(int k=0; k<MAX_N; k++){
                for(int l=k+1; l<MAX_N; l++){
                    if(i == k || i == l || j == k || j == l) continue;
                    int tmp[3];
                    tmp[0] = arr[i]+arr[j];
                    tmp[1] = arr[k]+arr[l];
                    tmp[2] = total-tmp[0]-tmp[1];
                    if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[0]) continue;
                    sort(tmp, tmp+3);
                    ans = min(ans, tmp[2]-tmp[0]);
                }

            }
        }
    }
    cout << ans << '\n';
    return 0;
}