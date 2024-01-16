#include <iostream>
#define MAX_N 200
#define BELT_CNT 2
using namespace std;
int n, t;
int arr[BELT_CNT][MAX_N];

int main() {
    cin >> n >> t;
    for(int j=0; j<n; j++)
        cin >> arr[0][j];
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        arr[1][i] = a[n-i-1];
    while(t--){
        // 먼저 위에 있는 컨베이어 오른쪽으로 밀기
        int tmp1 = arr[0][n-1];
        for(int i=n-2; i >= 0; i--)
            arr[0][i+1] = arr[0][i];
        arr[0][0] = arr[1][0];
        for(int i=0; i<n-1; i++)
            arr[1][i] = arr[1][i+1];
        arr[1][n-1] = tmp1;
    }

    for(int j=0; j<n; j++)
        cout << arr[0][j] << ' ';
    cout << '\n';

    for(int j=n-1; j>=0; j--)
        cout << arr[1][j] << ' ';    
    return 0;
}