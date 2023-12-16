#include <iostream>
using namespace std;
int a, b;
int main() {
    cin >> a >> b;
    if(a % 2 == 0)
        cout << "even" << '\n';
    else
        cout << "odd" << '\n';

    if(b % 2 == 0)
        cout << "even" << '\n';
    else
        cout << "odd" << '\n';
    return 0;
}