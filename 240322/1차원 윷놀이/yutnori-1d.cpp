#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 12

using namespace std;
int ans;
int k, n, m;    // k개의 말, n번의 턴, m개 숫자
int turns[MAX_N];
int selected[MAX_N];
int result[4];

int Calc(){
    // Step 1. start 0으로 초기화하기
    for(int i=0; i<4; i++)
        result[i] = 0;

    // Step 2. selected 보면서 turns만큼 이동시키기
    for(int i=0; i<n; i++){
        int cur_knight = selected[i];   // 현재 선택한 말
        result[cur_knight] += turns[i];
    }

    int ret = 0;
    for(int i=0; i<4; i++){
        if(result[i] >= m-1)
            ret++;
    }
    return ret;
}

void Choose(int idx){
    if(idx  ==  n){
        ans = max(ans, Calc());
        return;
    }

    for(int i=0; i<k; i++){
        selected[idx]=i;       // idx번째 턴에 i번 말 움직이기
        Choose(idx+1);      // idx+1번째 선택하러 가기
    }
}

int main() {
    // 입력 받기
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> turns[i];
    
    Choose(0);  // 0번째 턴에 움직일 말의 수 선택
    cout << ans;
    return 0;
}