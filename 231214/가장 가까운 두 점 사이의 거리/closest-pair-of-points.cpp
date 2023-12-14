#include <iostream>
#include <climits>
#include <cstdlib>

#define MAX_N 100

using namespace std;

int n;
int c[MAX_N][2];

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> c[i][0] >> c[i][1];
    
    int min_diff = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //(i번 ~ j번 사이의 거리)
            min_diff = min(min_diff, (abs(c[i][0]-c[j][0])*abs(c[i][0]-c[j][0])+abs(c[i][1]-c[j][1])*abs(c[i][1]-c[j][1])));
        }
    }
    cout << min_diff << '\n';
    return 0;
}