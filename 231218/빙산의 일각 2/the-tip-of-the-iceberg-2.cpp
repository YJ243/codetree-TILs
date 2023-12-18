#include <iostream>
#include <algorithm>

#define MAX_N 100
#define MAX_H 1000

using namespace std;
int n;
int arr[MAX_N];
int ans;

int main() {
    // 입력
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // 1부터 1000사이의 모든 높이 i에 대해 탐색 진행
    for(int i=1; i<=MAX_H; i++){
        bool newPart = false;   // 새로운 빙산 덩어리가 시작했는가
        int cnt = 0;            // 빙산 덩어리 개수
        
        for(int j=0; j<n; j++){ // 모든 빙산을 보는데
            if(arr[j] >= i){    // 만약 해수면보다 위에 있다면
                if(!newPart){   // 그런데 해수면보다 위에 있으면서 새로운 빙산 파트가 시작됐다면
                    newPart = true;
                    cnt++;      //카운트 증가
                }                
            }
            else{               // 만약 해수면보다 아래에 있다면
                newPart = false;  // 새로운 빙산 부분은 끝났다고 처리
            }
        }
        ans = max(ans, cnt);    // 탐색이 끝나고 빙산 덩어리 개수 업데이트
    }
    cout << ans << '\n';
    return 0;
}