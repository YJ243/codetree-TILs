#include <iostream>

using namespace std;
int n;

int f(int n){
    if(n < 10)
        return n*n;
    return f(n/10) + (n%10)*(n%10);
}
int main() {
    cin >> n;
    cout << f(n);
    return 0;
}