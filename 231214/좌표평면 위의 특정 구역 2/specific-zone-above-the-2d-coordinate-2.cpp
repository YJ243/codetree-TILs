#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100
using namespace std;

int n;
int c[MAX_N][2] = {};
int ans = INT_MAX;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c[i][0] >> c[i][1];  // 좌표 입력받기 
    }

    // i번 점을 빼기
    for(int i=0; i<n; i++){
        int minX=INT_MAX, minY=INT_MAX, maxX=INT_MIN, maxY=INT_MIN;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            minX = min(minX, c[j][0]);
            maxX = max(maxX, c[j][0]);
            minY = min(minY, c[j][1]);
            maxY = max(maxY, c[j][1]);
        }
        //cout << (maxX-minX)*(maxY-minY) << '\n';
        ans = min(ans, (maxX-minX)*(maxY-minY));
    }
    cout << ans;
    return 0;
}