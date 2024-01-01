#include <iostream>
#define MAX_N 100
using namespace std;
int n;
int arr[MAX_N][2];
int ans;
int rcp[2][3] = {
    // 가위, 바위, 보를 정의
    // 항상 0(가위)을 1(바위)이 이기고, 1(바위)을 2(보)가 이기고, 2(보)를 0(가위)이 이김
    {1,2,3},
    {1,3,2},
};

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int t=0; t<6; t++){
        int cur = 0;
        for(int i=0; i<n; i++){
            if(arr[i][0] == rcp[t][1] && arr[i][1] == rcp[t][0]) cur++;
            if(arr[i][0] == rcp[t][2] && arr[i][1] == rcp[t][1]) cur++;
            if(arr[i][0] == rcp[t][0] && arr[i][1] == rcp[t][2]) cur++;
        }
        ans = max(cur, ans);
    }
    cout << ans;
    return 0;
}