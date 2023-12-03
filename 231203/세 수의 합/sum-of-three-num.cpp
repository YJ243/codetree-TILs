#include <iostream>
#include <unordered_map>
#define MAX_N 1000

using namespace std;

// 변수 선언
int n, k;
int arr[MAX_N];
unordered_map<int, int> cnt;

int main(){
    // 입력:
    cin >> n >> k;
    // 각 숫자가 몇 번씩 나왔는지 hashmap에 기록
    for(int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int ans = 0;
    // 배열을 앞에서부터 순회하면서 쌍을 만들어 줌
    for(int i=0; i<n; i++){
        // 이미 순회한 적이 있는 숫자는 빼서 같은 조합이 여러번 세어지는 것을 방지
        cnt[arr[i]]--;

        for(int j=0; j<i; j++){
            // 전처리를 해주었기 때문에 이미 순회한적이 있는 값은 hashmap에 없음
            // 이렇게 같은 좋바이 중복되어 세어지는 것을 방지할 수 있음
            int diff = k-arr[i]-arr[j];
            ans += cnt[diff];
        }
    }
    cout << ans;

}