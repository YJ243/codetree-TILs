#include <iostream>
using namespace std;
int a, b;
int main() {
    cin >> a >> b;

    for(int i=a; i<=b; i+=2){
        cout << i << ' ';
    }
    return 0;
}