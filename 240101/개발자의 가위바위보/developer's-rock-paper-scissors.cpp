#include <iostream>
#define MAX_N 100
using namespace std;
int n;
int arr[MAX_N][2];
int ans;
int rcp[6][3] = {
    {1,2,3},
    {1,3,2},
    {3,1,2},
    {3,2,1},
    {2,1,3},
    {2,3,1}
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
            if(arr[i][0] == rcp[t][1] && arr[i][1] == rcp[t][2]) cur++;
        }
        ans = max(cur, ans);
    }
    cout << ans;
    return 0;
}