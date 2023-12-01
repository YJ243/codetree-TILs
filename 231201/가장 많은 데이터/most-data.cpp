#include <iostream>
#include <unordered_map>
#include <string>
#define MAX_N 100000
using namespace std;

int n;
string arr[MAX_N];
unordered_map<string, int> freq; 
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int max_freq = 0;
    for(auto i = freq.begin() ; i != freq.end() ; i++){
        max_freq = max(max_freq, i->second);
    }
    cout << max_freq;
    return 0;
}