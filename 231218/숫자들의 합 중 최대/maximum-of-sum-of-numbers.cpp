#include <iostream>
using namespace std;

int x,y;
int ans = 1;

// 각 자리 숫자의 합을 구하여 반환
int DigitSum(int n){
    // 한 자리 숫자라면 그 숫자 그대로 반환
    if(n < 10)
        return n;

    // 두자리 이상의 숫자라면,
    // 맨 끝자리를 제외한 숫자들의 합을 재귀적으로 호출한 뒤,
    // 마지막 자리수를 계속 더해 반환
    return DigitSum(n/10) + (n%10);
}
int main() {
    // 입력
    cin >> x >> y;
    
    // 각 숫자에 대해 각 자리 숫자의 합을 구해 그 중 최댓값을 계산하기
    for(int i=x; i<=y; i++){
        ans = max(ans, DigitSum(i));
    }
    cout << ans << '\n';
    return 0;
}