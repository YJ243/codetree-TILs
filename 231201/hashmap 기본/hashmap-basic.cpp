#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n;
int main(){
    unordered_map<int, int> m;
    cin >> n;
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            int k,v;
            cin >> k >> v;
            m[k] = v;
        }
        else if(cmd == "remove"){
            int k;
            cin >> k;
            m.erase(k);
        }
        else{
            int k;
            cin >> k;
            if(m.find(k) == m.end()){
                cout << "None" << '\n';
            }
            else{
                cout << m[k] << '\n';
            }
        }
    }
}