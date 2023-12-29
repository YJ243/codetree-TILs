/*
 * 2023.12.29
 * 가능한 모든 최댓값 중 하나를 최댓값으로 임의 설정, 그 최댓값에 맞게 구간이 m개로 나누어지는지 판단, 그 중 가장 작은 값을 구하기
*/

#include <iostream>
#include <algorithm>

#define MAX_A MAX_N*MAX_N   // 100이 100번 나오는 경우
#define MAX_N 100

using namespace std;
int n, m;
int arr[MAX_N];
int ans;
int main(){
    // 입력:
    cin >> n >> m;
    int max_num = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
    }
    // max_num ~ 전제 합까지 보기
    // 구간의 합의 최댓값을 결정한다면, 구간을 몇 개로 나눠야 하는지 손쉽게 찾을 수 있음
    for(int cur_max = max_num; cur_max <= MAX_A; cur_max++){
        int section = 1;        // 구간 개수
        int cur_sum = 0;        // 구간에서의 합
        for(int i=0; i<n; i++){
            // 배열의 첫번째부터 볼 것인데,
            if(cur_sum + arr[i] > cur_max){
                // 지금 숫자를 더했을 때 구간 합의 최대값보다 커진다면
                section++;
                cur_sum = 0;
            }
            
            cur_sum += arr[i];  // 현재 값 더하기
        }
        if(section <= m){
            ans = cur_max;
            break;
        }

    }
    cout << ans;
    return 0;
}