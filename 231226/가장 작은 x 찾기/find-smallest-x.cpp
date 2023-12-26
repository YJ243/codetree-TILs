#include <iostream>
#include <cstdlib>
#define MAX_N 10
#define MAX_AB 10000
using namespace std;

int n;
int range[MAX_N][2];

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> range[i][0] >> range[i][1];

    for(int x=1; x<MAX_AB; x++){
        // 처음의 양의 정수 x
        int cur_num = x;
        bool passed = true;
        for(int i=0; i<n; i++){
            cur_num *= 2;
            if(cur_num < range[i][0] || cur_num > range[i][1]){
                passed = false;
                break;
            }
        }
        if(passed){
            cout << x;
            return 0;
        }
    }
    return 0;
}