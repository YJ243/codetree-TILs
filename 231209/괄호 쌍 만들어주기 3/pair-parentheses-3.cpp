#include <iostream>
#include <string>

using namespace std;
string s;
int ans;
int main(){
    cin >> s;
    for(int i=0; i<(int)s.size(); i++){
        for(int j=i+1; j<(int)s.size(); j++){
            if(s[i] == '(' && s[j] == ')'){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}