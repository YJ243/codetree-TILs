#include <iostream>
#include <climits>
#include <cstdlib>
#define MAX_N 100
using namespace std;

int n;
pair<int, int> coor[MAX_N];
int ans = INT_MAX;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> coor[i].first >> coor[i].second;
    }

    // 처음과 마지막을 제외한 중간 한 지점을 골라서 건너뛰기
    for(int i=1; i<n-1; i++){

        int cur_x = coor[0].first, cur_y = coor[0].second;
        int distance = 0;
        
        for(int j=1; j<n; j++){   // j는 다음 좌표 순
            if(j == i) continue;
            distance += abs(cur_x-coor[j].first)+abs(cur_y-coor[j].second);
            cur_x = coor[j].first, cur_y = coor[j].second; 

        }
        ans = min(ans, distance);
        
    }
    cout << ans;
    return 0;
}