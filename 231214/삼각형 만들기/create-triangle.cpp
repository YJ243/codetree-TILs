#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;
int n;
int c[MAX_N][2];
int ans = INT_MIN;
int main(){
    // 입력
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> c[i][0] >> c[i][1];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bool isX = false, isY = false;
            for(int k=j+1; k<n; k++){
                // 점은 i, j, k번째 점
                // x축에 평행(y가 같음)한지 확인
                if(c[i][1] == c[j][1] || c[j][1] == c[k][1] || c[k][1] == c[i][1])  isX = true;
                // y축에 평행한지(x가 같은게 있는) 확인
                if(c[i][0] == c[j][0] || c[j][0] == c[k][0] || c[k][0] == c[i][0])  isY = true;

                if(isX && isY){
                    int cur_area = abs((c[i][0]*c[j][1] + c[j][0]*c[k][1] + c[k][0]*c[j][1]) - (c[j][0]*c[i][1] + c[k][0]*c[j][1] + c[i][0]*c[k][1]));
                    ans = max(cur_area, ans);
                }
            }

        }
    }
    if(ans == INT_MIN) ans = 0;
    cout << ans;
    return 0;
}