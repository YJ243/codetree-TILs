#include <iostream>
int a,b;
using namespace std;
int main() {
    cin >> a >> b;
    if(a<b) cout << 1 << ' ';
    else cout << 0 << ' ';

    if(a==b) cout << 1;
    else cout << 0;
    return 0;
}