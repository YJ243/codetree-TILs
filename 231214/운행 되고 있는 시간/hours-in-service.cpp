#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int op_time[MAX_N][2];
int main() {
    cin >> n;
    int max_time = 0;
    for(int i=0; i<n; i++){
        cin >> op_time[i][0] >> op_time[i][1];
        max_time = max(max_time, op_time[i][1]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        // i번째 사람을 제외하기
        int counting[max_time+1] = {};
        
        for(int j=0; j<n; j++){
            if(i == j) continue;
            int x1 = op_time[j][0], x2 = op_time[j][1];
            for(int k=x1; k<x2; k++)
                counting[k]++;
        }
        // 모든 사람을 다 봤다면
        int cur = 0;
        for(int j=0; j<max_time+1; j++){
            if(counting[j]) cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}