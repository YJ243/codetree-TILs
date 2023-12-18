#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

int n, c, g, h; // n:장비 개수, c/g/h: 작업량
int x[MAX_N];
int y[MAX_N];
int ans;

int GetWork(int t){
    int amount = 0;
    for(int i=0; i<n; i++){
        // n개의 장비를 보면서 작업량 구하기
        if(t < x[i])    amount += c;
        else if(x[i] <= t && t <= y[i]) amount += g;
        else    amount += h;
    }
    return amount;
}
int main() {
    // 입력
    cin >> n >> c >> g >> h;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i=0; i<=1000; i++){
        // 온도 i일 때의 장비들의 총 작업량
        ans = max(ans, GetWork(i));
    }
    cout << ans << '\n';
    return 0;
}