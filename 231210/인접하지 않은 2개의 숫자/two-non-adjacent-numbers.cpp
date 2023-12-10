#include <iostream>
#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N];
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        for(int j=i+2; j<n; j++)
            ans = max(ans, arr[i]+arr[j]);
    }
    cout << ans;
    return 0;
}