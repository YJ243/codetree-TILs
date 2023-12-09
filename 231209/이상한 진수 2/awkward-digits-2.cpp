#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX_N 10
using namespace std;
string a;
int num[MAX_N];
int main(){
    cin >> a;
    int length = (int)a.size();
    int ans = 0;
    
    for(int i=1; i<length; i++){
        string tmp = a;
        int cur_number=0;
        // 한자리수 바꿔보기
        if(tmp[i] == '0') tmp[i] = '1';
        else    tmp[i] = '0';
        for(int idx = 0; idx < length; idx++){
            int number = 0;
            if(tmp[idx] == '0'){
                number = 0;
            }
            else{
                number = 1;
            }
            cur_number += pow(2,length-1-idx)*number;
        }
        ans = max(ans, cur_number);

    }
    cout << ans << '\n';
    return 0;
}