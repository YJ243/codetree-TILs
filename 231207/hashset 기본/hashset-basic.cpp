#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;
int n;
unordered_set<int> s;

int main(){
    cin >> n;
    while(n--){
        string cmd;
        cin >> cmd;

        int val;
        cin >> val;

        if(cmd == "add"){
            s.insert(val);
        }
        else if(cmd == "remove"){
            s.erase(val);
        }
        else{
            if(s.find(val) != s.end()){
                cout << "true" << '\n';
            }
            else
                cout << "false" << '\n';
        }
    }
}