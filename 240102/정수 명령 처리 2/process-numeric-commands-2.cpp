#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int> q;
int n;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        string cmd;
        int num;
        cin >> cmd;
        if(cmd == "push"){
            cin >> num;
            q.push(num);
        }
        else if(cmd == "pop"){
            cout << q.front() << '\n';
            q.pop();
        }
        else if(cmd == "size"){
            cout << q.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << q.empty() << '\n';
        }
        else{
            cout << q.front() << '\n';
        }
    }
    return 0;
}