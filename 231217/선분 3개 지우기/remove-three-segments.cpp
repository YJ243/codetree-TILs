#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 10

using namespace std;
int n;
int arr[MAX_N][2];
int ans;
int main() {
    // 입력
    cin >> n;
    int minX = INT_MAX, maxX = INT_MIN;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
        minX = min(minX, arr[i][0]);
        maxX = max(maxX, arr[i][1]);
    }
    
    // 3개의 선분을 모두 골라보면서
    // 모두 겹쳐지지 않도록 하는 가짓수를 구하기
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                // i, j, k번 선분을 제외했을 때
                // 모든 선분이 겹치지 않으면 정답을 1 추가

                int counting[maxX+1] = {};
                for(int l=0; l<n; l++){
                    // 제외한 3개의 선분이면 넘어가
                    if(l == i || l == j || l == k) continue;
                    for(int x=arr[l][0]; x <= arr[l][1]; x++)
                        counting[x]++;
                }
                // overlapped: 모든 선분이 겹치지 않으면 false
                bool overlapped = false;
                
                for(int l=0; l<=maxX; l++){
                    if(counting[l] > 1){
                        overlapped = true;
                        break;
                    }
                }
                if(!overlapped) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}