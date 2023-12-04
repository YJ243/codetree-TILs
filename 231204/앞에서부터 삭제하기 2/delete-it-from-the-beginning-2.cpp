#include <iostream>
#include <queue>
#define MAX_N 100000
using namespace std;
int N;
int arr[MAX_N];
priority_queue<int> pq; 
double ans;
int sum_val;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    pq.push(-arr[N-1]);
    sum_val = arr[N-1];

    for(int i=N-2; i>=1; i--){
        pq.push(-arr[i]);
        sum_val += arr[i];
        
        double cur_avg = (double)(sum_val + pq.top()) / (N-i-1);
        ans = max(cur_avg, ans);
    }

    cout << fixed;
    cout.precision(2);

    cout << ans;
    return 0;
}