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
    
    /*
    해설에서는 0부터 n까지 보고 범위 벗어나면 continue로 처리
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            // 3*3 격자가 n*n 격자를 벗어나는 경우는 계산하지 않음
            if(row+2 >= n || col+2 >= n) continue;
            
            // 금의 개수를 계산
            int num_of_gold = GetNumOfGold(row, col, row+2, col+2);

            // 최대 금의 개수를 저장
            max_gold = max(max_gold, num_og_gold);
        }
    }
    */
    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=n-3; j++){
            int cur = GetCoin(i,j);
            ans = max(ans, cur);
        }
    }
    cout << ans;
    return 0;
}