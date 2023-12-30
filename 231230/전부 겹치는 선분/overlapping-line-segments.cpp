#include <iostream>
#define MAX_N 100
using namespace std;
int n;
int arr[MAX_N][2];
int count[MAX_N];
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i=0; i<n; i++){
        for(int x=arr[i][0]; x <= arr[i][1]; x++){
            count[x]++;
        }
    }
    bool allOverlapping = false;
    for(int i=0; i<MAX_N; i++){
        if(count[i] == n){
            allOverlapping = true;
        }
    }
    if(allOverlapping) cout << "Yes";
    else    cout << "No";
    return 0;
}