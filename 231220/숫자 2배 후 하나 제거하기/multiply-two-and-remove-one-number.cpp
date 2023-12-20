#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>

#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N];
int ans = INT_MAX;
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        // i번 숫자를 2배하기
        arr[i] *= 2;
        
        for(int j=0; j<n; j++){
            // j번 숫자를 선택해 제거하기
            int tmp[n] = {};
            int cnt = 0, cur_sum = 0;
            for(int k=0; k<n; k++){
                if(k != j)
                    tmp[cnt++] = arr[k];
            }
            for(int k=0; k<n-2; k++){
                cur_sum += abs(tmp[k]-tmp[k+1]);
            }
            ans = min(ans, cur_sum);
        }

        // 2배한 i번 숫자 원래대로 돌리기
        arr[i] /= 2;
    }
    cout << ans;
    return 0;
}