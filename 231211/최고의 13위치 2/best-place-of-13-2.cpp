#include <iostream>
#define MAX_N 20
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> arr[i][j];   // 동전:1, 없으면:0
    }
    // 두 격자가 같은 행에 있을 때
    for(int i=0; i<n; i++){
        for(int j=0; j<n-2; j++){
            // 첫번째 격자는 (i,j)에서 시작
            for(int k=j+3; k<n-2; k++){
                int val = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                val += arr[i][k]+arr[i][k+1]+arr[i][k+2];
                ans = max(val, ans);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-2; j++){
            for(int x=i+1; x<n; x++){
                for(int y=j; y<n-2; y++){
                    int val = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                    val += arr[x][y]+arr[x][y+1]+arr[x][y+2];
                    ans = max(val, ans);
                }
            }
        }
    }
    cout << ans;

    return 0;
}