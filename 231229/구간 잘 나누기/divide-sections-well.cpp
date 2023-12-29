#include <iostream>
#include <algorithm>

#define MAX_A MAX_N*MAX_N   // 100이 100번 나오는 경우
#define MAX_N 100

using namespace std;
int n, m;
int arr[MAX_N];
int ans;
int main(){
    cin >> n >> m;
    int max_num = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
    }
    // max_num ~ 전제 합까지 보기
    for(int cur_max = max_num; cur_max <= MAX_A; cur_max++){
        bool possible = true;   // 현재 구간 합들 중 최댓값이 cur_max가 되면서, m개의 구간으로 나눌 수 있는가?
        int section = 1;        // 구간 개수
        int cur_sum = 0;        // 구간에서의 합
        int tmp_max = 0;
        for(int i=0; i<n; i++){
            // 배열의 첫번째부터 볼 것인데,
            if(cur_sum + arr[i] > cur_max){
                // 지금 숫자를 더했을 때 구간 합의 최대값보다 커진다면
                section++;
                cur_sum = 0;
            }
            
            cur_sum += arr[i];  // 현재 값 더하기
            tmp_max = max(tmp_max, cur_sum);
        }
        if(tmp_max == cur_max && section <= m){
            //cout << tmp_max << ' ' << section << '\n';
            ans = cur_max;
            break;
        }

    }
    cout << ans;
    return 0;
}