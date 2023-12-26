#include <iostream>
#include <algorithm>
#define MAX_N 100

using namespace std;

int n;
string s;
int a[MAX_N];
int ans;

int main() {
    // 입력
    cin >> n;
    cin >> s;
    // 이렇게 int 배열로 바꿔서 풀어도 되지만, 아예 처음부터 string으로만 풀어도 됨
    // '0', '1'인지 아닌지 판단해서!
    for(int i=0; i<n; i++){
        a[i] = s[i] - '0';
    }
    // 들어갈 위치를 일일이 정해보며
    // 그 상황에서 가장 가까운 사람간의 거리를 구해
    // 가능한 경우 중 최댓값을 계산
    for(int i=0; i<n; i++){
        if(a[i] == 1) continue; // 공석이 아니라면 무시
        for(int j=i+1; j<n; j++){
            if(a[j] == 1) continue; // 공석이 아니라면 무시
            // 이제 i와 j에 두명을 받을 것임
            // 비어있는 위치에 인원을 배치
            a[i] = a[j] = 1;
            int cur_min = 100;
            for(int k=0; k<n; k++){
                for(int l=k+1; l<n; l++){
                    // 둘 다 1인 곳에 대해 모든 쌍을 조사해보면서
                    if(a[k] == 1 && a[l] == 1){
                        // 그 중 가장 가까운 거리를 구하기
                        cur_min = min(cur_min, l-k);
                    }
                }
            }
            ans = max(ans, cur_min);
            // 다시 채워졌던 값을 되돌려주기
            a[i] = a[j] = 0;
        }
    }
    cout << ans;
    return 0;
}