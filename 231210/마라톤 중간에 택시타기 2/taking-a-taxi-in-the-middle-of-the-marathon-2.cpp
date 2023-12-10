#include <iostream>
#include <climits>
#define MAX_N 100

using namespace std;

int n;
int ans = INT_MAX;
pair<int, int> coor[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> coor[i].first >> coor[i].second;
    }
    
    for(int i=1; i<n-1; i++){
        // i번째 좌표는 건너뛰기

        int cur_x = coor[0].first, cur_y = coor[0].second;
        int cur_distance=0;
        for(int j=1; j<n; j++){
            if(i == j) continue;

            cur_distance += abs(cur_x-coor[j].first) + abs(cur_y-coor[j].second);
            cur_x = coor[j].first, cur_y = coor[j].second; 
        }
        ans = min(cur_distance, ans);
    }
    cout << ans;
    return 0;
}