#include <iostream>
#include <queue>
#include <tuple>
int n;
using namespace std;
priority_queue<tuple<long long, long long> > pq;

int main() {
    cin >> n;
    while(n--){
        long long x;
        cin >> x;
        if(x==0){
            if(!pq.empty()){
                long long val_abs, val;
                tie(val_abs, val) = pq.top();
                pq.pop();
                cout << -val << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }
        else{
            pq.push(make_tuple(-abs(x),-x));
        }
    }
    return 0;
}