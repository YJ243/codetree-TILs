#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;
int n;
int x[MAX_N];
int y[MAX_N];
int ans = INT_MIN;

int main(){
    // 입력
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                bool isX = false, isY = false;
                // 점은 i, j, k번째 점
                // x축에 평행(y가 같음)한지 확인
                if(y[i] == y[j] || y[j] == y[k] || y[k] == y[i])  isX = true;
                // y축에 평행한지(x가 같은게 있는) 확인
                if(x[i] == x[j] || x[j] == x[k] || x[k] == x[i])  isY = true;

                if(isX && isY){ // 만약 둘다 평행한 면을 가지고 있을 경우 계산하기
                    // (x1y2 + x2y3 + x3y1) - (x2y1 + x3y2 + x1y3) 
                    int cur_area = abs((x[i]*y[j] + x[j]*y[k] + x[k]*y[i]) - (x[j]*y[i] + x[k]*y[j] + x[i]*y[k]));
                    ans = max(cur_area, ans);
                }
            }

        }
    }
    if(ans == INT_MIN) ans = 0;
    cout << ans;
    return 0;
}