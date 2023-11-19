#include <iostream>
using namespace std;

int n;
int main() {
    cin >> n;
    if(n == 1)
        cout << "John";
    else if(n == 2)
        cout << "Tom";
    else if(n == 3)
        cout << "paul";
    else cout << "Vacancy";
    return 0;
}