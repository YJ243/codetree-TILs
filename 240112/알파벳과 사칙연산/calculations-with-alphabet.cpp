#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_N 200
using namespace std;
string s;
int n;
int ans;
vector<int> numbers;
char operations[MAX_N];

void update(){
    int cur_sum = numbers[0];
    for(int i=1; i<(int)numbers.size(); i++){
        if(operations[i-1]=='+'){
            cur_sum += numbers[i];
        }
        else if(operations[i-1]=='-'){
            cur_sum -= numbers[i];
        }
        else{
            cur_sum *=numbers[i];
        }
    }
    ans = max(ans, cur_sum);
}

void choose(int num){   //numbers 배열의 num번째를 선택하러 가는 함수
    if(num == (n+1)/2){
        update();
        return;
    }

    for(int i=1; i<=4; i++){
        numbers.push_back(i);
        choose(num+1);
        numbers.pop_back();
    }

}
int main() {
    cin >> s;
    n = (int)s.size();
    for(int i=0; i<(n+1)/2; i++){
        operations[i] = s[i*2+1];
    }
    choose(0);
    cout << ans;
    return 0;
}