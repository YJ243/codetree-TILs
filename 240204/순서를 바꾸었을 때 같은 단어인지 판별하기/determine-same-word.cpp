#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a;
string b;
int main() {
    cin >> a;
    cin >> b;
    int len = (int)a.length();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a == b){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}