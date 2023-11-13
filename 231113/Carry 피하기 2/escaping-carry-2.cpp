#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX_N 20

using namespace std;
int N;
int arr[MAX_N];
int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    // 3개의 숫자를 고르고
    int ans = -1;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                // 그 숫자를 10의 0승부터 4승까지 늘리면서 확인해나가기
                int cur_sum = 0;
                bool IsCarry = false;
                int a = arr[i],b=arr[j],c=arr[k];
                for(int l=1; l<=3; l++){
                    //1의자리 숫자부터 5번째 자리 숫자까지 확인해야하는
                    if(a%10+b%10+c%10 >= 10) IsCarry = true;
                    a = (a-a%10) / 10;
                    b = (b-b%10) / 10;
                    c = (c-c%10) / 10;
                }
                if(!IsCarry){
                    cur_sum = arr[i]+arr[j]+arr[k];
                    ans = max(cur_sum, ans);
                }
            }
        }
    }
    cout << ans<<'\n';
    return 0;
}