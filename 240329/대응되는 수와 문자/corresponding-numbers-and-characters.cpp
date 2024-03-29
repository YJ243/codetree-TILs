#include <iostream>
#include <string>
#include <unordered_map>
#define MAX_N 100000
using namespace std;
int n, m;
string arr[MAX_N];
unordered_map<string, int> s_to_idx;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s_to_idx[arr[i]] = i+1;        
    }

    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(isdigit(s[0]))
            cout << arr[stoi(s)-1] << '\n';
        else
            cout << s_to_idx[s] << '\n';


    }
    return 0;
}