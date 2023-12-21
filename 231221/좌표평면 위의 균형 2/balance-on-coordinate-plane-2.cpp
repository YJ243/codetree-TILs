#include <iostream>
#include <algorithm>

#define MAX_N 100
using namespace std;
int n;
int x[MAX_N];
int y[MAX_N];
int ans;

int main() {
    // 입력
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if((i % 2 != 0) || (j % 2 != 0)) continue;
            // x=i, y=j의 평행한 직선들
            int dots[4] = {};
            for(int k=0; k<n; k++){
                // 1사분면
                if(x[k] > i && y[k] > j)
                    dots[0]++;
                // 2사분면
                else if(x[k] < i && y[k] > j)
                    dots[1]++;
                // 3사분면
                else if(x[k] < i && y[k]< j)
                    dots[2]++;
                // 4사분면
                else    dots[3]++;
            }
            int max_dots = 0;
            for(int k=0; k<4; k++){
                max_dots = max(max_dots, dots[k]);
            }
            if(ans == 0)
                ans = max_dots;
            else    ans = min(ans, max_dots);
        }
    }
    cout << ans;
    return 0;
}