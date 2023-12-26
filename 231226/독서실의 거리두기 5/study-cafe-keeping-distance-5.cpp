#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 20
using namespace std;

int n;
int seats[MAX_N];
int ans;
int main() {
    cin >> n;
    string s;
    cin >> s;

    for(int i=0; i<n; i++){
        seats[i] = s[i] - '0';
    }
    for(int i=0; i<n; i++){
        if(seats[i] == 1) continue;
        seats[i] = 1;
        int cur_min = 20;   // 현재 가장 가까운 두 사람의 거리
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(seats[j] == 0 || seats[k] == 0) continue;    // 사람이 없으면 넘어가기
                cur_min = min(cur_min, k-j);
            }
        }
        ans = max(ans, cur_min);

        seats[i] = 0;
    }
    cout << ans;
    return 0;
}