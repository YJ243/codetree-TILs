#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define MAX_N 100

using namespace std;

int n;
vector<int> arr;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout <<'\n';
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0; i<n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}