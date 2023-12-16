#include <iostream>
using namespace std;
int a;
int main() {
    cin >> a;
    if(a == 5)
        cout << "A";
    else if(a % 2 == 0)
        cout << "B";
    else
        return 0;
    return 0;
}