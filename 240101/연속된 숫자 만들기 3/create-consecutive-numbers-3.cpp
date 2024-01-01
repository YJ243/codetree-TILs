#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_N 3
using namespace std;

int loc[MAX_N];
int ans;

int main() {
    // 입력:
    for(int i=0; i<MAX_N; i++)
        cin >> loc[i];
    
    // step 0. 주어진 값들을 먼저 정렬하기
    sort(loc, loc+MAX_N);   

    // step 1. 만약 주어진 경우가 연속인 세 개 수라면
    // 이동할 필요가 없으므로 최대 이동 횟수는 0
    if(loc[1]-loc[0] == 1 && loc[2]-loc[1] == 1)
        ans = 0;

    // step 2. 연속된 수가 아니라면
    // 각각 거리를 한칸씩 좁혀가면서 이동하는 방식이 최대 이동횟수를 만들기 때문에
    // 두 간격중 큰 것을 선택해, 해당간격-1이 답이 됨.
    else{
        int cur = max(loc[1]-loc[0], loc[2]-loc[1]);
        ans = cur-1;
    }
    cout << ans;

    return 0;
}