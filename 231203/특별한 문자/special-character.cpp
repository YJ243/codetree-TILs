#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
string s;
unordered_map<char, int> freq;
int main() {
    cin >> s;
    for(auto a:s){
        freq[a]++;
    }
    char answer;
    bool flag = false;
    for(auto a:s){
        if(freq[a] == 1 && !flag){
            flag = true;
            answer = a;
        }
    }
    if(flag){
        cout << answer;
    }
    else{
        cout << "None";
    }
    return 0;
}