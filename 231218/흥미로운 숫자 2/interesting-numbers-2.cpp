#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int x, y;
int ans;

vector<int> tmp;
void DigitOfNumber(int num, vector<int>& arr){
    if(num < 10){
        arr.push_back(num);
        return;
    }
    arr.push_back(num%10);
    DigitOfNumber(num/10, arr);

}

bool IsInteresting(int number){
    tmp.clear();
    DigitOfNumber(number, tmp);
    int cnt = 0, cur = tmp[0];
    int number_cnt[10] = {};
    for(int j=0; j<(int) tmp.size(); j++){
        // 각 숫자별 나온 자릿수 증가시키기
        number_cnt[tmp[j]]++;
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