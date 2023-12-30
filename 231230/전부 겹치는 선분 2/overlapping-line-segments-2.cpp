#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100
using namespace std;

int n;
int a[MAX_N][2];

int minX1[2] = {INT_MAX,0}, minX2[2] = {INT_MAX,0};
int maxX1[2] = {0,-1}, maxX2[2] = {0,-1};
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1];
        if(maxX1[0] < a[i][0]){
            maxX1[0] = a[i][0];
            maxX1[1] = i;
        }
        if(minX1[0] > a[i][1]){
            minX1[0] = a[i][1];
            minX1[1] = i;
        }
    }

    for(int i=0; i<n; i++){
        if(maxX2[0] < a[i][0] && i != maxX1[1]){
            maxX2[0] = a[i][0];
            maxX2[1] = i;
        }
        if(minX2[0] > a[i][1] && i != minX1[1]){
            minX2[0] = a[i][1];
            minX2[1] = i;
        }
    }
    //cout << minX1 << ' ' << minX2 << ' ' << maxX1 << ' ' <<maxX2 << '\n';
    if(maxX2[0] >= minX1[0] || minX2[0] >= maxX1[0])  cout << "Yes";
    else    cout << "No";



    return 0;
}