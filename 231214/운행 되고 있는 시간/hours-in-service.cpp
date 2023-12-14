#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int op_time[MAX_N][2];
int main() {
    // 입력
    cin >> n;
    int max_time = 0;
    for(int i=0; i<n; i++){
        cin >> op_time[i][0] >> op_time[i][1];
        max_time = max(max_time, op_time[i][1]);
    }
    int ans = 0;
    // 뺄 직원을 정하기
    for(int i=0; i<n; i++){
        // i번 직원의 구간을 제외한 나머지 구간에서
        // 운행 되고 있는 시간을 구하
        int counting[max_time+1] = {};
        
        for(int j=0; j<n; j++){
            // i번째 사람을 제외하기
            if(i == j) continue;
            int x1 = op_time[j][0], x2 = op_time[j][1];
            
            // 모든 구간을 카운팅하기
            for(int k=x1; k<x2; k++)
                counting[k]++;
        }
        // 모든 사람을 다 봤다면
        int cur = 0;
        for(int j=0; j<max_time+1; j++){
            if(counting[j]) cur++;
        }

        // 운행 되고 있는 시간 중 최댓값을 구하기
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}