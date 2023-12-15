#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int n, b;   // n명의 학생에게 b만큼의 예산을 주기
int p[MAX_N];
int ans;
int main() {
    cin >> n >> b;    
    //int total = 0;
    for(int i=0; i<n; i++){
        cin >> p[i];
        //total += p[i];
    }
    sort(p, p+n);
    
    for(int i=0; i<n; i++){
        // i번 학생의 선물을 반값으로 할인하기
        p[i] /= 2;
        int sum_price = 0;
        for(int j=0; j<n; j++){
            // n명의 학생 선물 값 더해가면서 최대 명수 잡아보기
            sum_price += p[j];
            if(sum_price > b){ 
                ans = max(ans, j);
                break;
            }
        }
        if(sum_price <= b)
            ans = n;

        p[i] *= 2;
    }
    cout << ans;
    return 0;
}