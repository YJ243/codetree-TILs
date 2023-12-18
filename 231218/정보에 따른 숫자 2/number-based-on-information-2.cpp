#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX_T 100
#define MAX_C 1000

using namespace std;
int t, a, b;
vector<int> S;  // S의 좌표만 모아놓음
vector<int> N;  // N의 좌표만 모아놓음
int ans;
int main() {
    // 입력
    cin >> t >> a >> b;
    for(int i=0; i<t; i++){
        char c;
        int loc;
        cin >> c >> loc;
        if(c == 'S')
            S.push_back(loc);
        else
            N.push_back(loc);
    }

    // 1부터 1000까지 탐색하면서 (k-d1) <= (k-d2): k는 특별한 위치
    for(int i=a; i<=b; i++){
        // 제일 가까운 S까지의 거리 찾기
        int d1 = 1000, d2 = 1000;
        int s_index, n_index;
        for(int j=0; j<(int)S.size(); j++){
            if(d1 > abs(S[j]-i)){
                d1 = min(d1, abs(S[j]-i));
                s_index = S[j];
            }
        }
        // 제일 가까운 N까지의 거리 찾기
        for(int j=0; j<(int)N.size(); j++){
            if(d1 > abs(N[j]-i)){
                d2 = min(d2,abs(N[j]-i));
                n_index = N[j];
            }
        }
        
        if(d1 <= d2)    ans++;
    }
    cout << ans;
    return 0;
}