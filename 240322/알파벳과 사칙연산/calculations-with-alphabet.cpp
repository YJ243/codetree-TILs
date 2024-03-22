#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 200
#define CHAR_CNT 6
using namespace std;

int mapping[CHAR_CNT]; // 0:a, 1:b, 2:c, ..., 5: f
string s;
int ans;
void Cal(){
    int curr = mapping[s[0]-'a'];
    for(int i=1; i<s.size(); i++){
        if('a' <= s[i] && s[i] <= 'f'){
            // 만약 알파벳이라면
            int num = mapping[s[i]-'a'];
            if(s[i-1] == '+'){
                curr += num;
            }
            else if(s[i-1] == '-'){
                curr -= num;
            }
            else{       // '*'
                curr *= num;
            }
        }
    }

    ans = max(ans, curr);
}


void Choose(int idx){
    if(idx == CHAR_CNT){
        Cal();
        return;
    }

    for(int i=1; i<=4; i++){
        mapping[idx] = i;
        Choose(idx+1);
    }
}

int main() {
    cin >> s;
    Choose(0);  // a에 해당하는 숫자를 고르기
    cout << ans;
    return 0;
}