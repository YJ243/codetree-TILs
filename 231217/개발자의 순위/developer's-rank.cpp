#include <iostream>
#define MAX_K 10
#define MAX_N 20
using namespace std;
int k, n;
int play[MAX_K][MAX_N];
int win_cnt[MAX_N+1][MAX_N+1];
int ans;
int main() {
    cin >> k >> n;  // k번 경기에 대해 n명의 개발자 순위가 주어짐
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++)
            cin >> play[i][j];
        
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                win_cnt[play[i][j]][play[i][k]]++;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(win_cnt[i][j] == k) ans++;
            
        }
    }
    cout << ans << '\n';
    return 0;
}