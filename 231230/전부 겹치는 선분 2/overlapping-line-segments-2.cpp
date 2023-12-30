#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100
using namespace std;

int n;
int a[MAX_N][2];
int minX1 = INT_MAX, minX2 = INT_MAX;
int maxX1, maxX2;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1];
        maxX1 = max(maxX1, a[i][0]);
        minX1 = min(minX1, a[i][1]);
    }

    for(int i=0; i<n; i++){
        if(maxX2 < a[i][0] && a[i][0] != maxX1)   maxX2 = a[i][0];
        if(minX2 > a[i][1] && a[i][1] != minX1)   minX2 = a[i][1];
    }
    //cout << minX1 << ' ' << minX2 << ' ' << maxX1 << ' ' <<maxX2 << '\n';
    if(maxX2 >= minX1 || minX2 >= maxX1)  cout << "Yes";
    else    cout << "No";



    return 0;
}