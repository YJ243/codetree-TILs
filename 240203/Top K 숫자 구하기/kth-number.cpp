#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

int k, n;
int arr[MAX_N];
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    cout << arr[k-1];
    return 0;
}