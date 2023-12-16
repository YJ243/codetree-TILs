#include <iostream>
using namespace std;
int a;
int main() {
    cin >> a;
    if(a % 2 == 1)
        a += 3;
    if(a % 3 == 0)
        a /= 3;
    cout << a;
    return 0;
}