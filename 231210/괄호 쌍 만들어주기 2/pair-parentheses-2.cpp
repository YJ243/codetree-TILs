#include <iostream>
#include <string>

using namespace std;
string s;
int ans;
int main() {
    cin >> s;
    int n = (int) s.size();
    // i, i+1 // j, j+1
    for(int i=0; i<n-3; i++){
        for(int j=i+2; j<n-1; j++){
            if(s[i] == '(' && s[i+1] == '(' && s[j] == ')' && s[j+1] == ')')
                ans++;
        }
    }
    cout << ans;
    return 0;
}