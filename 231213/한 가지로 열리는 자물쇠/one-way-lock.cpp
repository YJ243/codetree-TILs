#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int arr[3];
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int cnt = 0;

    // 1부터 n까지 숫자를 중복해서 뽑아 총 3자리 만들기
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                // 한 자리라도 주어지는 조합과 거리가 2 이내라면 열림
                if((abs(i-arr[0])<= 2) || (abs(j-arr[1]) <= 2) || (abs(k-arr[2]) <= 2)) cnt++;
    cout << cnt << '\n';

    return 0;
}