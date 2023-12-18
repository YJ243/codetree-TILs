/*
 * 2023.12.18
 * 마지막 자리수를 제외하고 남은 숫자들을 함수에 넘기는 재귀함수 만들어 해결
*/
#include <iostream>

using namespace std;
int n;

int f(int n){
    // 한 자리 숫자라면 제곱한 값이 결과가 됨
    if(n < 10)
        return n*n;

    // 마지막 자리 숫자의 제곱에
    // 남은 숫자들의 합을 계산한 결과를 더해서 반
    return f(n/10) + (n%10)*(n%10);
}
int main() {
    // 변수 입력:
    cin >> n;
    
    cout << f(n);
    return 0;
}