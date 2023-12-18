#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int x, y;
int ans;

vector<int> tmp;
void DigitOfNumber(int num){
    if(num < 10){
        tmp.push_back(num);
        return;
    }
    tmp.push_back(num%10);
    DigitOfNumber(num/10);

}

bool IsInteresting(int number){
    tmp.clear();
    DigitOfNumber(number);
    int cnt = 0, cur = tmp[0];
    for(int j=1; j<(int) tmp.size(); j++){
        if(j >=2){
            if(tmp[j] != tmp[j-1] && tmp[j] != tmp[j-2]) cnt++;
        }
        else{
            if(tmp[j] != tmp[j-1])    cnt++;
        }

    }
    // number의 각 자리수가 같은지 보기
    return cnt == 1;
}

int main() {
    cin >> x >> y;
    for(int i=x; i<=y; i++){
        if(IsInteresting(i)){
            ans++;
            //cout << i << '\n';
        }
    }
    cout << ans;
    return 0;
}