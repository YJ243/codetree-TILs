#include <iostream>
#include <unordered_set>
#define MAX_N 100000

using namespace std;

int n;
unordered_set<int> s;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        s.insert(val);
    }
    cout << s.size();
    return 0;
}