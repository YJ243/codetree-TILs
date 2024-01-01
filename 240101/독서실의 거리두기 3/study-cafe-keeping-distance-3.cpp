#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s;
int main() {
    // 입력:
    cin >> n;
    cin >> s;

    // Step1. 가장 먼 거리에 있는 사람 위치(최적) 찾기
    // 인접한 쌍들 중 가장 먼 1간의 쌍을 찾기
    int longest = 0, startX = 0, startY = 0;
    for(int i=0; i<n; i++){
        if(s[i] != '1') continue;
        for(int j=i+1; j<n; j++){
            if(s[j] == '1'){
                // 둘다 사람이 앉아 있다면
                // 즉 1간의 쌍을 골랐을 때 두 좌석간의 거리가 지금까지의 최적의 답보다 더 좋다면
                // 값을 갱신해주기
                if(longest < j-i){
                    longest = j-i;
                    // 이 때, 두 좌석의 위치를 기억하기
                    startX = i;
                    startY = j;
                }
                // 인접한 쌍을 찾았으므로 빠져나오기
                break;
            }
        }
    }
    // Step2. 그 사이 가운데에다가 넣기
    // 최적의 위치에 1을 놓음: 가장 먼 쌍의 위치 가운데에 놓기
    s[(startY+startX)/2] = '1';

    // Step3. 가장 가까운 두 사람 거리 구하기
    // 이 때 값이 답이 
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