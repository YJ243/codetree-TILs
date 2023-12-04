#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int N;
int main(){
    cin >> N;
    while(N--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int A;
            cin >> A;
            pq.push(A);
        }
        else if(cmd == "pop"){
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if(cmd == "size"){
            cout << pq.size() << '\n';
        }
        else if(cmd == "empty"){
            if(pq.empty()){
                cout << "1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }
        else{   // top
            cout << pq.top() << '\n';
        }
    }
    return 0;
}