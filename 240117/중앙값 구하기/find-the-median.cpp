#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
int main() {
    cin >> a >> b >> c;
    if(a<b){
        if(a<c){
            if(b<c){
                cout << b;
            }
            else{
                cout << c;
            }
        }
        else{
            cout << a;
        }
    }
    else{
        if(a<c){
            cout << a;
        }
        else{
            if(b<c){
                cout << c;
            }
            else    cout << b;
        }
    }
    return 0;
}