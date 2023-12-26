#include <iostream>
#include <unordered_map>
#include <algorithm>

#define MAX_N 100
using namespace std;


int n, k;
int arr[MAX_N];                 // 폭탄의 번호
bool bombed[MAX_N];             // bombed[i]: i번째 폭탄이 터졌는지
unordered_map<int, int> cnt;    // 해당 폭탄 번호의 터진 횟수

int main() {
    // 입력:
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // 거리가 k이내고 번호가 같다면 터졌다고 표시
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=min(i+k, n-1); j++){
            if(arr[i] == arr[j]){
                bombed[i] = true;
                bombed[j] = true;
            }
        }
    }
    // 만약 터진 폭탄이라면 카운트 증가
    for(int i=0; i<n; i++){
        if(bombed[i])
            cnt[arr[i]]++;
    }
    int max_cnt = 0;
    int ans = 0;

    for(int i=0; i<n; i++){
        // 터진 폭탄 중 최대 횟수 찾기
        if(bombed[i]){
            if(max_cnt < cnt[arr[i]]){
                max_cnt = cnt[arr[i]];
                ans = arr[i];
            }
        }
    }
    cout << ans;
    return 0;
}

/*
 * 해설 풀이
*/
#include <iostream>

#define MAX_N 100
#define MAX_A 1000000

using namespace std;

int n, k;
int num[MAX_N];
int bomb[MAX_A + 1];
bool explode[MAX_N];

int main(){
    // 입력
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> num[i];
    int maxval = 1;
    int maxidx = 0;

    // 모든 쌍에 대해서 터질 수 있는 폭탄을 찾고
    // 터진 폭탄의 개수를 저장
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++){
            // 거리가 k를 초과하는 경우 넘어가기
            if(j-i > k) break;

            // 두 폭탄의 번호가 다를 경우 터지지 않음
            if(num[i] != num[j]) continue;

            // 두 폭탄의 번호가 같을 경우 폭탄은 터짐
            // 해당 폭탄이 이미 터진 폭탄인지 확인하고,
            // 아직 터지지 않은 폭탄이라면 터진 폭탄의 개수를 갱신
            if(explode[i] == false){
                bomb[num[i]]++;
                explode[i] = true;
            }
            if(explode[j] == false){
                bomb[num[j]]++;
                explode[j] = true;
            }
        }
    for(int i=0; i<=MAX_A; i++)
        if(maxval <= bomb[i]){
            maxval = bomb[i];
            maxidx = i;
        }
    cout << maxidx;
    return 0;
}