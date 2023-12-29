#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_N 100
#define MAX_K 10000

using namespace std;
int n, k;   // n개의 수, 최대 최소간의 차이가 k이하
int a[MAX_N];

int main() {
    // 입력:
    cin >> n >> k;
    int cur_min = MAX_K, cur_max = 1;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    bool turn_max = true;
    int cost = 0;

    while(true){
        int cur_min = MAX_K, minI=0, cur_max = 1, maxI = 0;
        for(int i=0; i<n; i++){
            // n개의 숫자를 보면서
            if(cur_min > a[i]){
                cur_min = a[i];
                minI = i;
            }
            if(cur_max < a[i]){
                cur_max = a[i];
                maxI = i;
            }
        }
        int min_cnt = 0, max_cnt = 0;
        for(int i=0; i<n; i++){
            if(cur_min == a[i]) min_cnt++;
            if(cur_max == a[i]) max_cnt++;
        }

        if(cur_max - cur_min <= k) break;
        else{
            if(min_cnt >= max_cnt){
                a[maxI]--;
                cost++;
            }
            else{
                a[minI]++;
                cost++;
            }
            /*
            for(int i=0; i<n; i++)
                cout << a[i] << ' ';
            cout << cost << '\n';
            */
        }
    }
    cout << cost;

    return 0;
}