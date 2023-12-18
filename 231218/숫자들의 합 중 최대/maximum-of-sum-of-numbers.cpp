#include <iostream>
using namespace std;

int x,y;
int ans = 1;
int main() {
    cin >> x >> y;
    for(int i=x; i<=y; i++){
        int d1 = i/10000;
        int d2 = i/1000;
        int d3 = (i/100)%10;
        int d4 = (i/10)%10;
        int d5 = i%10;
        ans = max(ans, d1+d2+d3+d4+d5);
    }
    cout << ans << '\n';
    return 0;
}