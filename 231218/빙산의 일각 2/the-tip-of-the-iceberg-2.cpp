#include <iostream>
#include <algorithm>
#define MAX_N 100

using namespace std;
int n;
int arr[MAX_N];
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=1; i<=1000; i++){
        bool newPart = false;
        int cnt = 0;
        for(int j=0; j<n; j++){
            // 모든 빙산을 보는데
            if(arr[j] >= i){    // 만약 해수면보다 위에 있다면
                if(!newPart){
                    // 그런데 새로운 파트가 시작됐다면 카운트 증가
                    newPart = true;
                    cnt++;
                }                
            }
            else{
                // 해수면보다 아래에 있다면
                newPart = false;    // 일단 새로운 파트는 끝났다고 처리/유
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}