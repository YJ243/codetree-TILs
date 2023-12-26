#include <iostream>
#include <algorithm>
#define MAX_N 10
#define MAX_M 100
using namespace std;

int n, m;
int arr[MAX_M][2];
int ans;
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=0; i<m; i++){
        // i번째와 같은 숫자 쌍이 몇개가 나오는지
        int cur = 0;
        for(int j=0; j<m; j++){
            if(arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1])    cur++;
            else if(arr[i][0] == arr[j][1] && arr[i][1] == arr[j][0])   cur++;
        }
        // 그 쌍이 가장 많은 개수라면
        ans = max(ans, cur); 
    }
    cout << ans;
    
    return 0;
}