#include <iostream>
#include <queue>
#define MAX_M 100000
using namespace std;
int t, m;

int main() {
    cin >> t;
    while(t--){
        int arr[MAX_M];
        int tmp[MAX_M/2];
        priority_queue<int> pq;
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> arr[i];
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            cnt++;
            pq.push(arr[i]);
            if(i%2==0){
                for(int j=0; j<cnt/2; j++){
                    int val = pq.top();
                    tmp[j] = val;
                    pq.pop();
                }
                cout<< pq.top() << ' ';
                for(int j=0; j<cnt/2; j++){
                    pq.push(tmp[j]);
                }
            }
        }
        cout << '\n';
    }
    return 0;
}