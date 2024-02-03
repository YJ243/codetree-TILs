#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<string> arr;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        arr.push_back(str);
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}