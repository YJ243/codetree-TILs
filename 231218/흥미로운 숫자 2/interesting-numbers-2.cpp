#include <iostream>
#include <algorithm>
using namespace std;
int x, y;
int ans;

bool IsInteresting(int number){
    int cur = number;
    int number_cnt[10] = {};
    while(cur){
        number_cnt[cur%10]++;
        cur /= 10;
    }
    // 1개만 나오는 숫자 수, 1개 초과해서 나오는 수
    int one_cnt = 0, second_cnt = 0;
    for(int j=0; j<10; j++){
        if(number_cnt[j] == 1) one_cnt++;
        if(number_cnt[j] > 1) second_cnt++;
    }

    return (one_cnt == 1 && second_cnt == 1);
}

int main() {
    cin >> x >> y;
    for(int i=x; i<=y; i++){
        if(IsInteresting(i)){   // 흥미로운 숫자면 정답 증가
            ans++;
        }
    }
    cout << ans;
    return 0;
}