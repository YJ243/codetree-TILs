#include <iostream>
using namespace std;
int b, a;
int main() {
    cin >> b >> a;
    for(int i=b; i>=a; i -= 2)
        cout << i << ' ';
    return 0;
}