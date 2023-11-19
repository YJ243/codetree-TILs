#include <iostream>
using namespace std;

int n;
int main() {
    cin >> n;
    if( n < 0)
        cout << "ice" << '\n';
    else if (0 <= n && n < 100){
        cout << "water" << '\n';
    }
    else    cout << "vapor"<<'\n';
    return 0;
}