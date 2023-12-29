#include <iostream>
#define MAX_N 100

using namespace std;
int n, l;   // n개의 숫자, 최대 l개의 서로 다른 원소 값을 1씩 올리기
int h;      // h점수를 최대로 만들어야 함(h이상인 숫자의 수가 h개 이상인 것을 만족하는 h중 최댓값)
int a[MAX_N];
int ans;
int main() {
    // 입력:
    cin >> n >> l;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // 기준을 새로 설정: h가 답이 되는지 안되는지로 판단하기
    // 모든 답을 일일이 가정해 봄
    for(int h=1; h<=n; h++){
        // 정답이 h일 때 간으한지 판단
        // h-1인 값은 최대 l개까지 h로 올릴 수 있음
        // cnt: h이상인 숫자의 개수
        // plus_cnt: h-1인 숫자의 개수
        int cnt = 0, plus_cnt = 0;
        
        int countable[n] = {};
        for(int i=0; i<n; i++){
            // h보다 크거나 같은 것이 몇 개가 있는지
            if(a[i] >= h){
                cnt++;
            }
            else if(a[i]+1 == h){
                plus_cnt++;
                //countable.push_back(i);
            }
        }
        if(cnt >= h){
            ans = h;
        }
        else{
            // 이제 L개 올려서 만들 수 있는지 보기
            if(cnt + l >= h && plus_cnt >= h-cnt)   
                ans = h;
            else 
                break;
        }
    }
    cout << ans;
    return 0;
}