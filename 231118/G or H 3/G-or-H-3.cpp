#include <iostream>
#include <algorithm>
#define MAX_LOC 10001
using namespace std;

int N, K;   // N: 사람 명수, K: 사진 크기
char loc[MAX_LOC];
int main(){
    cin >> N >> K;
    int max_idx = 0;
    for(int i=0; i<N; i++){
        int idx;
        cin >> idx;
        cin >>  loc[idx];
        max_idx = max(idx, max_idx);
    }
    int ans = 0;

    for(int i=1; i<=max_idx-K; i++){
        int cur = 0;
        for(int j=i; j<=i+K; j++){

            if(loc[j] == 'G'){
                cur += 1;
            }
            else if(loc[j] == 'H'){
                cur += 2;
            }

        }
        ans = max(cur, ans);
    }
    cout << ans;
}