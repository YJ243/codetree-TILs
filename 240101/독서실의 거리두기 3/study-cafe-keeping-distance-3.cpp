#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s;
int main() {
    cin >> n;
    cin >> s;

    // Step1. 가장 먼 거리에 있는 사람 위치 찾기
    int longest = 0, startX = 0, startY = 0;
    for(int i=0; i<n; i++){
        if(s[i] != '1') continue;
        for(int j=i+1; j<n; j++){
            if(s[j] == '1'){
                // 둘다 사람이 앉아 있다면
                if(longest < j-i){
                    longest = j-i;
                    startX = i;
                    startY = j;
                }
                break;
            }
        }
    }
    // Step2. 그 사이 가운데에다가 넣기
    s[(startY+startX)/2] = '1';

    // Step3. 가장 가까운 두 사람 거리 구하기
    int ans = 1000;
    for(int i=0; i<n; i++){
        if(s[i] != '1') continue;
        for(int j=i+1; j<n; j++){
            if(s[j] == '1')
                ans = min(ans, j-i);
        }
    }
    cout << ans;
    return 0;
}