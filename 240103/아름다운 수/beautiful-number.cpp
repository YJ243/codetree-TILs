#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;    // 만든 수 배열
int n;              // n자리 아름다운 수
int ans;            // 아름다운 수 개수

void CheckBeautiful(){  // 만든 n자리 수가 아름다운 수인지 확인하는 함수
    bool isBeautiful = true;

    int idx = 0, cur_num = arr[0];
    while(idx != n){
        for(int i=idx; i <= idx+cur_num-1; i++){
            if(arr[i] != cur_num) isBeautiful = false;
        }
        if(!isBeautiful) break;
        idx += cur_num;
        cur_num = arr[idx];
    }
    if(isBeautiful)
        ans++;

}

void Choose(int cnt){   // cnt개 숫자를 골랐고, 그 다음 숫자를 고르는 함수
    if(cnt == n){
        CheckBeautiful();
        return;
    }

    for(int i=1; i<=4; i++){
        arr.push_back(i);
        Choose(cnt+1);
        arr.pop_back();
    }
}
int main() {
    cin >> n;

    Choose(0);
    cout << ans;
    return 0;
}