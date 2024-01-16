#include <iostream>
#include <algorithm>
#define MAX_NM 20

using namespace std;
int n, m;
int grid[MAX_NM][MAX_NM];
int ans;        // 최대 크기의 양수 직사각형

int GetPositiveCnt(int x, int y, int k, int l){
    int cnt = 0;
    for(int i=x; i<=x+k; i++){
        for(int j=y; j<=y+l; j++){
            if(grid[i][j] < 0)
                return 0;
            cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int k=0; k<n; k++)
                for(int l=0; l<m; l++){
                    if(i + k >= n || j + l >= m) continue;
                    ans = max(ans, GetPositiveCnt(i,j,k,l));
                }
    if(ans==0)
        ans = -1;
    cout << ans;
    return 0;
}