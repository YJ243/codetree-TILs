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

    // 시간복잡도: O(N^2)=> 시간초과 
    for(int K=N-2; K>=1; K--){
        for(int i=K; i<N; i++){
            pq.push(arr[i]);    // 앞에서부터 K개를 삭제하고 pq에 집어넣음

        }
        int sum_val = 0;
        while(pq.size() > 1){   // 
            int val = pq.top();
            pq.pop();
            sum_val += val;
        }
        int avg_val = sum_val / (N-K-1);

        ans = max(ans, avg_val);
        pq.pop();

    }
    cout << fixed;
    cout.precision(2);
    cout << (double)ans;
    return 0;
}