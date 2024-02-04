#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;
int n;
int A[MAX_N];
int B[MAX_N];
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];

    for(int i=0; i<n; i++)
        cin >> B[i];
    sort(A, A+n);
    sort(B, B+n);
    for(int i=0; i<n; i++)
        if(A[i] != B[i]){
            cout << "No";
            exit(0);
        }
    
    cout << "Yes";
    return 0;
}