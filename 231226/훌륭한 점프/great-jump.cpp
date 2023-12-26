#include <iostream>
#include <algorithm>

#define MAX_N 100
using namespace std;
int n, k;       // n: 돌 개수, k: 거리가 k이내로 점프
int a[MAX_N];

bool IsPossible(int maxNum){
    int tmp[n] = {};
    int cnt = 0;
    
    // 거쳐간 지점중에서 maxNum이 최대가 되도록, maxNum보다 작거나 같은 돌의 인덱스만 집어넣기
    for(int i=0; i<n; i++){
        if(a[i] <= maxNum)
            tmp[cnt++] = i;
    }

    for(int i=1; i<cnt; i++){
        if(tmp[i]-tmp[i-1] > k)
            return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    int max_num = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        max_num = max(max_num, a[i]);
    }
    
    // 최댓값이 i라고 가정
    int miniMax=100;
    for(int i=max_num; i >= max(a[0], a[n-1]); i--){
        if(IsPossible(i)){
            // 만약 i가 거쳐간 지점에 적혀있던 숫자중 최댓값으로 볼 수 있다면
            miniMax = min(miniMax, i);
        }
    }
    cout << miniMax;
    return 0;
}