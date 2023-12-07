#include <iostream>
#include <unordered_set>
#define MAX_N 100000

using namespace std;

int a,b;
int arr[MAX_N];
unordered_set<int> s;

int main() {
    cin >> a;
    for(int i=0; i<a; i++){
        int val;
        cin >> val;
        s.insert(val);
    }
    cin >> b;
    for(int i=0; i<b; i++){
        int val;
        cin >> val;
        if(s.find(val) != s.end()){
            cout << 1 << '\n';
        }
        else
            cout << 0 << '\n';
    }
    return 0;
}