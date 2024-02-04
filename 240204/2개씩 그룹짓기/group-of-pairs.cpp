#include <iostream>
#include <algorithm>

#define MAX_N 1000
using namespace std;
int n;
int arr[MAX_N*2];

int main() {
    cin >> n;
    for(int i=0; i<n*2; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n*2);

    int tmp[MAX_N];
    for(int i=0; i<n; i++){
        tmp[i] = arr[i] + arr[2*n-1-i];
    }
    sort(tmp, tmp+n);
    cout << tmp[n-1];        
    return 0;
}