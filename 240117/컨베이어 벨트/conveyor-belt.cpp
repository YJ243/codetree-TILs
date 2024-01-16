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
/*
 * 해설 풀이

#include <iostream>

#define MAX_N 200

using namespace std;

// 전역 변수 선언
int n, t;

int u[MAX_N+1];
int d[MAX_N+1];

int main(){
    // 입력:
    cin >> n >> t;

    for(int i=0; i<n; i++)
        cin >> u[i];
    for(int i=0; i<n; i++)
        cin >> d[i];

    while(t--){
        // Step 1
        // 위에서 가장 오른른쪽에 있는 숫자를 따로 temp값에 저장해놓기
        int temp = u[n-1];

        // Step 2
        // 위에 있는 숫자들을 완성
        // 오른쪽에서부터 채워넣어야하며, 맨 왼쪽 숫자는 아래에서 가져와야 함
        for(int i=n-1; i>=1; i--)
            u[i] = u[i-1];
        u[0] = d[n-1];
    
        // Step 3
        // 아래에 있는 숫자들을 완성
        // 마찬가지로 오른른쪽에서부터 채워넣어야 하며
        // 맨 왼쪽 숫자는 위에서 미리 저장해놨던 tempm 값을 가져와야 함
        for(int i=n-1; i>=1; i--)
            d[i] = d[i-1];
        d[0] = temp;
    }
    // 출력:
    for(int i=0; i<n; i++)
        cout<< u[i] << ' ';
    cout<< '\n';

    for(int i=0; i<n; i++)
        cout << d[i] << ' ';
    return 0;
}
*/