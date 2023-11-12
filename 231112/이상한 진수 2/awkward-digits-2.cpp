#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
string a;
int main() {
    cin >> a;
    //'1'==49, '0'==48
    int max_val = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] == '0') a[i] = '1';
        else            a[i] = '0';
        int cur_val = 0;
        for(int i=a.size()-1; i>=0; i--){
            int num = 0;
            if(a[i] == '0') num = 0;
            else            num = 1;
            cur_val += num * pow(2,3-i);
        }
        max_val = max(max_val, cur_val);
        
        if(a[i] == '0') a[i] = '1';
        else            a[i] = '0';
    }
    cout<<max_val;
    return 0;
}