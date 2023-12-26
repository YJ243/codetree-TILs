#include <iostream>
#include <algorithm>
#define MAX_N 100

using namespace std;

int n;
string s;
int a[MAX_N];
int ans;

int main() {
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++){
        a[i] = s[i] - '0';
    }

    for(int i=0; i<n; i++){
        if(a[i] == 1) continue; // 공석이 아니라면 무시
        for(int j=i+1; j<n; j++){
            if(a[j] == 1) continue; // 공석이 아니라면 무시
            // 이제 i와 j에 두명을 받을 것임
            a[i] = a[j] = 1;
            int cur_min = 100;
            for(int k=0; k<n; k++){
                for(int l=k+1; l<n; l++){
                    if(a[k] == 1 && a[l] == 1){
                        cur_min = min(cur_min, l-k);
                    }
                }
            }
            ans = max(ans, cur_min);
            a[i] = a[j] = 0;
        }
    }
    cout << ans;
    return 0;
}