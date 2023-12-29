#include <iostream>
using namespace std;

int x1, x2, x3, x4;
int main() {
    cin >> x1 >> x2 >> x3 >> x4;
    if((x1 <= x3 && x3 <= x2) || (x3 <= x1 && x1 <= x4)){
        cout << "intersecting";
    }
    else
        cout << "nonintersecting";
    return 0;
}