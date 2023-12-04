#include <iostream>
#include <queue>
//#define MAX_N 100000
using namespace std;

int n, m;   // n개의 숫자, m번 반복

priority_queue<int> pq;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        pq.push(v);
    }
    
    while(m--){
        int max_val = pq.top();
        pq.pop();
        pq.push(max_val-1);
    }
    cout << pq.top();
}