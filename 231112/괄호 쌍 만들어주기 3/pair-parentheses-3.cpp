#include <iostream>
#include <string>
using namespace std;
string s;

int main(){
    cin >> s;
    int result = 0;
    for(int i=0; i<s.size(); i++)
        for(int j=i+1; j<s.size(); j++){
            if(s[i] == '(' && s[j] == ')'){
                result++;
            }
        }
    cout << result << '\n';
    return 0;
}