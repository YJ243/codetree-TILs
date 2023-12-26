#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;
int n;
int arr[MAX_N];
int change[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    bool maxTurn = true;
    while(true){
        int cur_max = 0, cur_min = 1000, maxI=0, minI=0;
        for(int i=0; i<n; i++){
            if(cur_max<arr[i]){
                cur_max = arr[i];
                maxI = i;
            }
            if(cur_min > arr[i]){
                cur_min = arr[i];
                minI = i;
            }
        }

        // 높이 차이가 17 이하가 된다면 반복문 나가기
        if(cur_max - cur_min <= 17) break;
        if(maxTurn){
            change[maxI]++;
            arr[maxI]--;
            maxTurn = false;
        }
        else{
            change[minI]++;
            arr[minI]++;
            maxTurn = true;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(change[i]){
            ans += change[i]*change[i];
        }
    }
    cout << ans;
    return 0;
}