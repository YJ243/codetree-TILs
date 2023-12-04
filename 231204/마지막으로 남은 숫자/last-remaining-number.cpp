#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;
int main() {
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1){
        int a,b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        if(a==b) continue;
        int diff = a-b;
        pq.push(diff);
    }
    if(pq.empty()){
        cout << -1;
    }
    else{
        cout << pq.top();
    }
    return 0;
}