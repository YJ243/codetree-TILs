#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#define MAX_N 1000
using namespace std;

int n;
unordered_map<string, int> freq;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string input_str;
        cin >> input_str;
        sort(input_str.begin(), input_str.end());
        freq[input_str]++;
    }
    int ans = 0;
    for(unordered_map<string, int>::iterator it=freq.begin(); it != freq.end(); it++){
        ans = max(ans, it->second);
    }
    cout << ans << '\n';
    return 0;
}