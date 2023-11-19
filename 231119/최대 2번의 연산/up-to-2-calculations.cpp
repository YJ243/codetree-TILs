#include <iostream>
using namespace std;
int a;
int main() {
    cin >> a;
    if(a % 2 == 0)  a /= 2;
    if(a % 2 == 1)   a = (a+1)/2;
    cout << a;
    return 0;
}