#include <iostream>
#include <unordered_map>
#include <string>
#define MAX_N 100000
using namespace std;

int n, m; // n: 문자열 개수, m: 조사할 숫자/문자열의 개수
string arr[MAX_N];
unordered_map<string, int> str_idx;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        str_idx[arr[i]] = i+1;
    }
    
    while(m--){
        // 1. 입력받기
        string s;
        cin >> s;

        // 2. 숫자인지 문자인지 확인
        // 2-1. 숫자라면
        bool is_digit = true;
        for(auto a : s){
            if(!isdigit(a)){
                is_digit = false;
                break;
            }
        }
        if(is_digit){
            int idx = stoi(s);
            cout << arr[idx-1] << '\n';
        }
        // 2-2. 문자라면
        else{
            cout << str_idx[s] << '\n';
        }
    }
    
    return 0;
}