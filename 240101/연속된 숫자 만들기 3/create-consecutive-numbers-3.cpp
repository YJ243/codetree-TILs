#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_N 3
using namespace std;

int loc[MAX_N];
int ans;

int main() {
    for(int i=0; i<MAX_N; i++)
        cin >> loc[i];
    
    // step 0. 먼저 정렬하기
    sort(loc, loc+MAX_N);   

    // step 1. 만약 주어진 경우가 연속인 세 개 수라면
    if(loc[1]-loc[0] == 1 && loc[2]-loc[1] == 1)
        ans = 0;
    // step 2. 연속된 수가 아니라면
    else{
        int cur = max(loc[1]-loc[0], loc[2]-loc[1]);
        ans = cur-1;
    }
    cout << ans;

    return 0;
}