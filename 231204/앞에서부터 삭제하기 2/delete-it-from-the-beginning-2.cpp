#include <iostream>
#include <queue>
#define MAX_N 100000

using namespace std;
int N;
int arr[MAX_N];

priority_queue<int> pq;
int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    pq.push(arr[N-1]);
    pq.push(arr[N-2]);

    int sum_val = 0, cnt = 1;
    sum_val = pq.top();
    pq.pop();
    int cur_min = pq.top();
    ans = max(ans, sum_val/cnt);

    // 시간복잡도: O(N^2)=> 시간초과
    for(int K=N-3; K>=1; K--){
        pq.push(arr[K]);
        int val = pq.top();
        pq.pop();
        sum_val += val;
        cnt++;
        ans = max(ans,sum_val/cnt);
        if(val < cur_min){
            cur_min = val;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << (double)ans;
    return 0;
}