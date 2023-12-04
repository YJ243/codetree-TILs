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
        if(x > 0){
            pq.push(x);
        }

        else{
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}