#include <iostream>
#include <string>
#include <unordered_map>
#define MAX_N 100000
using namespace std;
int n,m;    // n개의 문자열, 조사할 m개 문자
string arr[MAX_N+1];
unordered_map<string, int> string_idx;
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        string_idx[arr[i]] = i;
    }
    while(m--){
        string s;
        cin >> s;
        if(s[0] >= '0' && s[0] <= '9'){
            cout << arr[stoi(s)] << '\n';
        }
        else{
            cout<<string_idx[s]<<'\n';
        }
    }
    return 0;
}