#include <iostream>
#define MAX_A 100
using namespace std;
int a,b,c,d;
int arr[MAX_A];

int main() {
    cin >> a >> b;
    cin >> c >> d;
    for(int i=a; i<b; i++)
        arr[i]++;
    for(int i=c; i<d; i++)
        arr[i]++;
    int ans = 0;
    for(int i=0; i<MAX_A; i++){
        if(arr[i]) ans++;
    }
    cout << ans;
    return 0;
}