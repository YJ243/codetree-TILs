#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 20
using namespace std;

int n;
int seats[MAX_N];
int ans;
int main() {
    // 입력
    cin >> n;
    string s;
    cin >> s;

    for(int i=0; i<n; i++){
        seats[i] = s[i] - '0';
    }
    // 들어갈 위치를 일일이 정해보며
    // 그 상황에서 가장 가까운 사람간의 거리를 구해
    // 가능한 경우 최댓값을 계산
    for(int i=0; i<n; i++){
        if(seats[i] == 1) continue;
        seats[i] = 1;   // 비어있는 위치에 인원 배치
        int cur_min = 20;   // 현재 가장 가까운 두 사람의 거리
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                // 가장 가까운 사람간의 거리를 구해 최댓값을 갱신
                if(seats[j] == 0 || seats[k] == 0) continue;    // 사람이 없으면 넘어가기
                cur_min = min(cur_min, k-j);
            }
        }
        ans = max(ans, cur_min);
        // 다시 채워졌던 값 되돌리기
        seats[i] = 0;
    }
    cout << ans;
    return 0;
}