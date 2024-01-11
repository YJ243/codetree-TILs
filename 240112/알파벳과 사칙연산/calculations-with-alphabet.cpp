#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX_N 200
using namespace std;
string s;
int n;
int ans=INT_MIN;
vector<int> alpa_to_numbers;    // numbers[]
char operations[MAX_N];

void update(){
    int cur_sum = 0;

    for(int i=0; i<(n+1)/2; i++){
        //cout << i << ':' ;
        int cur=0;
        if(s[i*2] == 'a'){
            cur=alpa_to_numbers[0];
        }
        else if(s[i*2] == 'b'){
            cur=alpa_to_numbers[1];
        }
        else if(s[i*2] == 'c'){
            cur=alpa_to_numbers[2];
        }
        else if(s[i*2] == 'd'){
            cur=alpa_to_numbers[3];
        }
        else if(s[i*2] == 'e'){
            cur=alpa_to_numbers[4];
        }
        else{
            cur=alpa_to_numbers[5];
        }
        //cout << cur << '\n';
        if(i==0)   cur_sum = cur;
        else{
           // cout << s[i*2-1] << '\n';
            if(s[i*2-1]=='+'){
                cur_sum += cur;
            }
            else if(s[i*2-1]=='-'){
                cur_sum -= cur;
            }
            else{
                cur_sum *=cur;
            }
        }
       // cout << "cur_sum: " << cur_sum << '\n';
    }
   // cout << '\n';
    ans = max(ans, cur_sum);
}

void choose(int num){   //numbers 배열의 num번째를 선택하러 가는 함수
    if(num == 6){
        update();
        return;
    }

    for(int i=1; i<=4; i++){
        alpa_to_numbers.push_back(i);
        choose(num+1);
        alpa_to_numbers.pop_back();
    }

}
int main() {
    cin >> s;
    n = (int)s.size();

    choose(0);
    cout << ans;
    return 0;
}