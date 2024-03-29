#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int n;
unordered_map<int, int>  m;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        string s; int k, v;
        cin >> s;
        if(s == "add"){
            cin >> k >> v;
            m[k] = v;
        }
        else if(s == "remove"){
            cin >> k;
            m.erase(k);
        }
        else{
            cin >> k;
            if(m.find(k) != m.end())
                cout << m[k] << '\n';
            else
                cout << "None" << '\n';
        }
    }    
    return 0;
}