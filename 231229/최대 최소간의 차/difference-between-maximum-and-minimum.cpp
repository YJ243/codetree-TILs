/*
 * 2023.12.29
 * 내 풀이
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_N 100
#define MAX_K 10000

using namespace std;
int n, k;   // n개의 수, 최대 최소간의 차이가 k이하
int a[MAX_N];

int main() {
    // 입력:
    cin >> n >> k;
    int cur_min = MAX_K, cur_max = 1;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    bool turn_max = true;
    int cost = 0;

    while(true){
        int cur_min = MAX_K, minI=0, cur_max = 1, maxI = 0;
        // 현재 최대/최소값 찾기
        for(int i=0; i<n; i++){
            // n개의 숫자를 보면서
            if(cur_min > a[i]){
                cur_min = a[i];
                minI = i;
            }
            if(cur_max < a[i]){
                cur_max = a[i];
                maxI = i;
            }
        }
        // 최댓값, 최솟값 개수 구하기
        int min_cnt = 0, max_cnt = 0;
        for(int i=0; i<n; i++){
            if(cur_min == a[i]) min_cnt++;
            if(cur_max == a[i]) max_cnt++;
        }

        // 만약 최대-최소 차이가 k이하라면 반복문 나가기
        if(cur_max - cur_min <= k) break;
        else{
            // 최대, 최소 중 적은 개수부터 변화하기(비용을 낮추기 위해)
            if(min_cnt >= max_cnt){
                a[maxI]--;
                cost++;
            }
            else{
                a[minI]++;
                cost++;
            }
        }
    }
    cout << cost;

    return 0;
}

/*
 * 해설 풀이
 * 최솟값을 정하며 진행하는 완전탐색 이용
 * 변화 이후의 숫자들 중 최솟값이 a라면? => 주어진 숫자를 전부 [a, a+k] 사이의 숫자로 만들어야 함
 * 최솟값 a가 얼마가 되어야 가장 좋은지 확신을 갖기가 어려운 문제
 * 최솟값 a를 일일이 고정해보면서(새로운 기준), [a, a+k] 사이의 수로 만들기 위한 최소 비용을 구하는 완전탐색
 * a보다 작은 값은 a로, a+k보다 큰 값은 a+k로 만들기


#include <iostream>
#include <algorithm>
#inlcude <climits>

#define MAX_N 100
#define MAX_K 10000

using namespace std;

int n, k;
int arr[MAX_N];

int GetCost(int low, int high){
    int cost = 0;

    // 각 수에 대해 low ~ high 사이로 바꾸는데 드는 cost를 계산해줌
    for(int i=0; i<n; i++){
        // low보다 작을 경우 low로 만들어 주는게 최소 cost
        if(arr[i] < low)    cost += low-arr[i];
        // high보다 큰 경우 high로 만들어 주는게 최소 cost
        if(arr[i] > high)   cost += arr[i]-high;
        // 그 외의 경우는 이미 구간 안에 있기 때문에 cost가 필요하지 않음
    }
    return cost;
}
int main(){
    // 입력:
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int ans = INT_MAX;
    // 모든 구간 쌍 (num, num+k)를 잡아보면서
    // 그 구간으로 만들기 위한 비용을 계산하여
    // 그 중 최솟값을 계산
    for(int num=1; num <= MAX_K; num++)
        ans = min(ans, GetCost(num, num+k));
    cout << ans;
}
*/