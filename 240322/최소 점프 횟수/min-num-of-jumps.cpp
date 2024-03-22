#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 10
using namespace std;

int n;
int arr[MAX_N];
int ans = INT_MAX;
int cur;
void Choose(int idx){
    if(idx == n-1){
        ans = min(ans, cur);
        return;
    }
    for(int i=1; i<=arr[idx]; i++){
        // 1부터 칸에 써져있는 수만큼 이동 가능
        if(idx+i <= n-1){   // 만약 다음에 이동할 칸이 범위 안에 있다면
            cur++;
            Choose(idx+i);
            cur--;
        }
    }
}

/*
 * 해설에서 backtracking 함수
void FindMin(int idx, int cnt){
    // 마지막 위치를 넘었을 때 그 중 최소 이동 횟수를 갱신한다
    if(idx >= n-1){
        ans = min(ans, cnt);
        return;
    }
    for(int dist = 1; dist <= num[idx]; dist++){
        FindMin(idx+dist, cnt+1);
    }
}

*/
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    Choose(0);
    if(ans == INT_MAX){
        ans = -1;
    }
    cout << ans;
    return 0;
}