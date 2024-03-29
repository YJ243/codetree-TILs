#include <iostream>
#include <string>
#include <unordered_map>

#define MAX_N 100000

using namespace std;
int n;
string s[MAX_N];
unordered_map<string, int> freq;
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    for(int i=0; i<n; i++){
        freq[s[i]]++;
        ans = max(ans, freq[s[i]]);
    }
    cout << ans;
    return 0;
}