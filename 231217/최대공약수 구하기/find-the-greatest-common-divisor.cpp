#include <iostream>
using namespace std;
int n, m;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    else 
        return gcd(b, a%b);
}
int main() {
    cin >> n >> m;
    cout << gcd(n,m);
    return 0;
}