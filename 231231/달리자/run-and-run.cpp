/*
 * 2023.12.31
 * 이동 전과 이동 후의 사람 수를 비교해서, 
 * 특정 집에서 이동 전의 사람 수가 이동 후보다 많다면 그 차 만큼 사람을 바로 다음 집으로 이동시킴
 * 사람들의 이동 거리를 최소화시키려면, 이동할 사람의 수만큼 현재 집에서 다음 집으로 이동시키면서 수를 세기
 * 즉 현재 번호의 집에 대해 이동 전과 이동 후의 사람 수를 비교했을 때, 이동 전의 사람 수가 더 많다면?
 * 그 차이만큼을 현재 집의 사람수에서 뺀뒤, 바로 다음 ㅣㅂ의 사람수에 더해주면서 총 이동한 사람의 수 저장하
*/
#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int a[MAX_N];
int b[MAX_N];
int ans;
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];

    for(int i=0; i<n; i++){
        if(a[i] > b[i]){
            int cur = a[i]-b[i];
            a[i] -= cur;
            a[i+1] += cur;
            ans += cur;
        }
    }
    cout << ans;
    return 0;
}