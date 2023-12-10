#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 1003
int n;
int room[MAX_N];
int ans = INT_MAX;
int main() {
    cin >> n;
    int total=0;
    for(int i=0; i<n; i++){
        cin >> room[i]; // 각방에 들어가야 할 인원 넣기
        total += room[i];
    }
    for(int i=0; i<n; i++){
        // i번째 방에서 모두 시작하기
        int cur_total = total;
        int cur_distance = 0;
        for(int j=0; j<n; j++){
            int next = (i+j)%n;
            cur_distance += (j) * room[next]; // 거리*해당 룸의 사람 수
        }
        ans = min(cur_distance, ans);
    }
    cout << ans << '\n';
    return 0;
}