#include <iostream>
#include <queue>
#define MAX_N 100000
using namespace std;

priority_queue<int> pq;
int N;
int arr[3];
int a,b,c;

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        int val;
        cin >> val;
        pq.push(-val);
        if(i < 2) 
            cout << -1 << '\n';
        else{
            for(int j=0; j<3; j++){
                arr[j] = pq.top();
                pq.pop();
                arr[j] *= -1;
            }
            int ans = 1;
            for(int j=0; j<3; j++){
                ans *= arr[j];
                pq.push(-arr[j]);
            }
            cout << ans << '\n';            
        }
    }
    return 0;
}