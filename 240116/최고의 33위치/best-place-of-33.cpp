#include <iostream>
#define MAX_N 20
using namespace std;

int n;
int grid[MAX_N][MAX_N];
int ans;

int GetCoin(int x, int y){
    int cur_coin = 0;
    for(int i=x; i<x+3; i++)
        for(int j=y; j<y+3; j++){
            cur_coin += grid[i][j];
        }

    return cur_coin;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=n-3; j++){
            int cur = GetCoin(i,j);
            ans = max(ans, cur);
        }
    }
    cout << ans;
    return 0;
}