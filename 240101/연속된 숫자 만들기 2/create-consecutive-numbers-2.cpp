#include <iostream>
using namespace std;
long long arr[3];
int ans;
int main() {
    for(int i=0; i<3; i++)
        cin >> arr[i];
    
    // Step 1. 시작부터 연속인 경우
    if(arr[1]-arr[0] == 1 && arr[2]-arr[1] == 1)
        ans = 0;
    
    // Step 2. 왼쪽/오른쪽을 힌 번 움직이기
    else if((arr[2]-arr[1] == 2) || (arr[1]-arr[0] == 2)){
        // 만약 세 사람 중 두사람이 2차이로 붙어있다면, 그 가운데로 이동하면 됨
        ans = 1;
    }
    
    // Step 3. 그 외에는 모두 2번 움직이면 됨
    else ans = 2;
    cout << ans;
    return 0;
}