#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

#define MAX_N 10
using namespace std;
int n;
int m;
int arr[MAX_N];
int total;

vector<int> selected;
int ans = INT_MAX;

void GetMinSum(){
    int sum = 0;
    for(int i=0; i<(int)selected.size(); i++){
        sum += selected[i];
    }
    ans = min(ans, abs(total-sum-sum));
}

void ChooseHalf(int idx){
    if((int)selected.size() >= n){
        GetMinSum();
        return;
    }

    for(int i=idx; i<m; i++){
        selected.push_back(arr[i]);
        ChooseHalf(i+1);
        selected.pop_back();
    }
}
int main() {
    cin >> n;
    m = 2*n;
    for(int i=0; i<m; i++){
        cin >> arr[i];
        total += arr[i];
    }

    ChooseHalf(0);  // 2n개 중 총 n개 원소를 고르는 함수(0번째 원소를 선택하러 감)
    cout << ans;
    
    return 0;
}