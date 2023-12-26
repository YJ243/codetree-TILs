#include <iostream>
#include <cstdlib>
#define MAX_N 10
#define MAX_AB 10000
using namespace std;

int n;
int range[MAX_N][2];

int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> range[i][0] >> range[i][1];

    // 가능한 모든 범위에 대해 탐색
    // 1 ~ MAX_AB 사이가 아니라면 애초에 처음부터 불가
    for(int x=1; x<MAX_AB; x++){
        // 처음의 양의 정수 x
        int cur_num = x;
        bool passed = true;
        for(int i=0; i<n; i++){
            // 계속 2배씩 해주면서 x가 범위 사이에 있는지 확인
            // 아니라면 passed를 false로 바꾸고 break
            cur_num *= 2;
            if(cur_num < range[i][0] || cur_num > range[i][1]){
                passed = false;
                break;
            }
        }
        // 만족하는 x가 있다면 해당 x가 최소이므로 출력
        if(passed){
            cout << x;
            return 0;
        }
    }
    return 0;
}