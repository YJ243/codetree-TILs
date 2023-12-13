#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int arr[3];
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int cnt = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                if((abs(i-arr[0])<= 2) || (abs(j-arr[1]) <= 2) || (abs(k-arr[2] <= 2))) cnt++;
    cout << cnt;
    return 0;
}