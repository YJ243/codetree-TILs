#include <iostream>
using namespace std;
int a, b;
int main() {
    cin >> a >> b;
    while(a<=b){
        cout << a << ' ';
        a += 2;
    }
    return 0;
}