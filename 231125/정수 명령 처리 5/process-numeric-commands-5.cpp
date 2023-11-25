#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> v;

int main() {
    cin >> N;
    while(N--){
        string cmd;
        int num;
        cin >> cmd;
        if(cmd == "push_back"){
            cin >> num;
            v.push_back(num);
        }
        else if(cmd == "get"){
            cin >> num;
            cout << v[num-1] << '\n';
        }
        else if(cmd == "pop_back"){
            v.pop_back();
        }
        else{
            cout << v.size() << '\n';
        }
    }    
    return 0;
}