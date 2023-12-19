#include <iostream>
#include <algorithm>
#define MAX_N 100

using namespace std;
int n;
int cups[MAX_N][MAX_N];
int max_score;
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> cups[i][j];
        }
    }

    for(int i=1; i<=3; i++){
        // i번 종이컵에 조약돌을 넣었을 경우
        int cur = i;
        int score = 0;
        for(int j=0; j<n; j++){
            if(cups[j][0] == cur){
                // 만약 바꿔야 되는 컵에 조약돌이 들어있다면
                cur = cups[j][1];
            }

            else if(cups[j][1] == cur){
                cur = cups[j][0];
            }

            if(cups[j][2] == cur) score++;
            //if(i == 2) cout << cur << ' ' << score << '\n';
        }
        if(max_score < score){
            max_score = score;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}