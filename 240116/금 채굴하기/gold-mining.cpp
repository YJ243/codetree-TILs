#include <iostream>
#include <cstdlib>
#define MAX_N 20

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
int ans;

// 주어진 k에 대하여 채굴 가능한 금의 개수를 반환하
int GetGold(int x, int y, int d){
    int curr = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(abs(x-i)+abs(y-j) <= d){
                curr += grid[i][j];
            }
        }
    }
    return curr;
}

int main(){
    // 입력:
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    // 격자의 각 위치가 마름모의 중앙일 때 채굴 가능한 금의 개수를 구하
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // (i,j)가 마름모의 중심
            for(int k=0; k<=(n-1)*2; k++){
                int curGold = GetGold(i,j,k);

                // 손해를 보지 않으면서 채굴할 수 있는 최대 금의 개수 업데이
                if((k*k)+(k+1)*(k+1) <= m*curGold){
                    ans = max(ans, curGold);
                }
            }
        }
    }
    cout << ans;
    return 0;
}