#include <iostream>
#define MAX_N 100
using namespace std;

int n;
char arr[MAX_N+1];
int ans;
int main() {
    cin >> n;
    int max_idx = 0;
    for(int i=0; i<n; i++){
        int idx;
        char c;
        cin >> idx >> c;
        arr[idx] = c;
        max_idx = max(max_idx, idx);
    }

    for(int i=0; i<=max_idx; i++){
        for(int j=i; j<=max_idx; j++){
            // (i ~ j) 까지
            if(arr[i] == '\0' || arr[j] == '\0') continue;
            int g_cnt = 0, h_cnt = 0;
            for(int k=i; k<=j; k++){
                if(arr[k] == 'G') g_cnt++;
                else if(arr[k] == 'H') h_cnt++;
            }
            bool updatable = false;
            if( g_cnt == h_cnt && g_cnt > 0 && h_cnt > 0)
                updatable = true;
            else if((g_cnt == 0 && h_cnt > 0)|| (h_cnt == 0 && g_cnt > 0))
                updatable = true;
            
            if(updatable){
                //cout << j-i << ' ' << j << ' ' <<i <<'\n';
                ans = max(ans, j-i);
            }

        }
    }
    cout << ans;
    return 0;
}