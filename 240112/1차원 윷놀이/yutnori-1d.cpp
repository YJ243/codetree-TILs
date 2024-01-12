#include <iostream>
#include <vector>

#define MAX_N 12
#define MAX_M 100
#define MAX_K 4
using namespace std;
int n, m, k;    // n: 턴수, m: 윷놀이 판 상태, k: 말의 수
int jump[MAX_K];
int locations[MAX_K];

vector<int> pieces;
int ans;

void Verify(){
    for(int i=0; i<k; i++){
        locations[i] = 1;
    }
    for(int i=0; i<n; i++){
        // i번째 턴을 확인
        locations[pieces[i]] += jump[i];
    }
    int cur_pass = 0;
    for(int i=0; i<k; i++){
        if(locations[i] >= m-1){
            cur_pass++;
        }
    }

    ans = max(ans, cur_pass);
}

void Choose(int num){  // num번째 턴에 움직일 말을 선택하는 함수
    if(num == n){
        Verify();
        return;
    }

    for(int i=1; i<=k; i++){
        pieces.push_back(i);
        Choose(num+1);
        pieces.pop_back();
    }

}
int main() {
    // 입력:
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> jump[i];
    
    Choose(0);
    cout << ans << '\n';
    return 0;
}