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
    // 모든 직선에 대해 전부 시도해보
    for(int i=0; i<=100; i += 2){
        for(int j=0; j<=100; j += 2){
            //if((i % 2 != 0) || (j % 2 != 0)) continue;
            // x=i, y=j의 평행한 직선들
            // dots: x=i, y=j를 기준으로 1~4분면의 점의 개수
            int dots[4] = {};
            // k번째 점이 몇사분면인지 확인하고 해당 위치의 segment를 1 증가시
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
            // x=i, y=j로 나눴을 때의 m을 구하기
            int max_dots = 0;
            // 1,2,3,4,를 두개씩 나눠서 max함수를 이용해도 됨
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