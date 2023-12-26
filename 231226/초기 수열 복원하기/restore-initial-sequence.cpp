#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_N 1000

using namespace std;
int n;
int a[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n-1; i++)
        cin >> a[i];
    
    for(int i=1; i<=n; i++){
        // i는 첫번째 위치의 원소
        int tmp[n] = {};
        int last_idx = 0;
        tmp[last_idx] = i;
        for(int j=0; j<n-1; j++){
            int new_num = abs(a[j]-tmp[last_idx]);
            tmp[++last_idx] = new_num;
        }
        int tmp2[n] = {};
        for(int i=0; i<n; i++)
            tmp2[i] = tmp[i];
        sort(tmp, tmp+n);
        bool passed = true;
        for(int i=0; i<n; i++){
            if(tmp[i] != i+1) 
                passed = false;    
        }
        if(passed){
            for(int i=0; i<n; i++)
                cout << tmp2[i] << ' ';
            break;
        }
    }
    return 0;
}