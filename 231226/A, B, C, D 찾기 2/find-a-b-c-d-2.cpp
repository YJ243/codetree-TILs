#include <iostream>
#include <algorithm>
using namespace std;
int arr[15];
int main() {
    // 입력
    for(int i=0; i<15; i++)
        cin >> arr[i];
    
    // 모든 a,b,c,d를 확인해서 이 합들이 arr과 같은지 여부를 확인하기
    for(int a=1; a<=40; a++){
        for(int b=a; b<=40; b++){
            for(int c=b; c<=40; c++){
                for(int d=c; d <= 40; d++){
                    int tmp[15] = {a, b, c, d, a + b, b + c, c + d, d + a,
                    a + c, b + d, a + b + c, a + b + d, a + c + d, b + c + d,
                    a + b + c + d};

                    sort(tmp, tmp+15);
                    sort(arr, arr+15);

                    bool passed = true; // arr 배열과 tmp 배열이 완전히 같을 경우 true
                    for(int i=0; i<15; i++){
                        if(tmp[i] != arr[i]){
                            passed = false;
                        }
                    }
                    // 만약 두 배열이 완전히 같다면 a,b,c,d 조합을 찾아냄
                    if(passed){
                        cout << a << ' ' << b << ' ' << c << ' ' << d;
                    }
                }

            }
        }
    }
    return 0;
}