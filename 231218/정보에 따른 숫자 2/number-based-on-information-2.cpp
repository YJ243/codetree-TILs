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
        
        // 만약 배열로 선언했다면
        // if(x == 'S')      s[cnt_s++] = y; // 이렇게 하면 편 
    }

    // 각 숫자에 대해 s에 더 가까운지 n에 더 가까운지 판단
    // (k-d1) <= (k-d2): k는 특별한 위치
    for(int i=a; i<=b; i++){
        // 제일 가까운 S까지의 거리 찾기
        int d1 = 1000, d2 = 1000;
        for(int j=0; j<(int)S.size(); j++){
            d1 = min(d1, abs(S[j]-i));
        }
        // 제일 가까운 N까지의 거리 찾기
        for(int j=0; j<(int)N.size(); j++){
            d2 = min(d2,abs(N[j]-i));
        }
        
        if(d1 <= d2)    ans++;
    }
    cout << ans;
    return 0;
}