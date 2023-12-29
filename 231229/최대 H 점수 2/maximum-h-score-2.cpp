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
    ans = n;
    // 기준을 새로 설정: h가 답이 되는지 안되는지로 판단하기
    for(int h=1; h<=n; h++){
        int cnt = 0, plus_cnt = 0;
        //vector<int> countable;
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
            //cout << "h: " << h << ' ' << "cnt: " << cnt << ' ' << "plus: " << plus_cnt << '\n';
            continue;
        }
        else{
            // 이제 L개 올려서 만들 수 있는지 보기
            if(cnt + l >= h && plus_cnt >= l){
                //cout << "h: " << h << ' ' << "cnt: " << cnt << ' ' << "plus: " << plus_cnt << '\n';
                continue;
            }
            else{
                ans = h-1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}