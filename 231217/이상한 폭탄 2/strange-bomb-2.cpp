#include <iostream>
#define MAX_N 100
using namespace std;

int n, k;   // 폭탄 개수 n, 특정 거리 k
int ans = -1;
int bomb[MAX_N];    // 이상한 폭탄 번호들
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> bomb[i];
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((bomb[i] == bomb[j]) && (j-i <= k)){
                // 같은 번호의 폭탄이 k거리 내에 있으면
                ans = max(ans, bomb[i]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}