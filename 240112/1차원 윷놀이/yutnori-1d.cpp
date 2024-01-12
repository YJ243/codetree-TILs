#include <iostream>
#include <vector>

#define MAX_N 12
#define MAX_M 100
#define MAX_K 4

using namespace std;
// 테스트케이스가 길어지니까 시간초과가 나
int n, m, k;            // n: 턴수, m: 윷놀이 판 상태, k: 말의 수
int jump[MAX_N];        // 각 턴마다 나아갈 수 있는 거리
int locations[MAX_K+1];   // 각 말의 현재 위치

vector<int> pieces;
int ans;

void Verify(){
    for(int i=1; i<=k; i++){
        locations[i] = 1;   // 처음 위치를 1로 초기화
    }
    for(int i=0; i<n; i++){
        // i번째 턴을 확인
        int cur_jump = jump[i];
        locations[pieces[i]] += jump[i];
          
    }
    
    int cur_pass = 0;
    for(int i=1; i<=k; i++){
        if(locations[i] >= m){
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

    for(int i=1; i<=k; i++){    // 1부터 k번 말까지 고르기
        pieces.push_back(i);
        Choose(num+1);
        pieces.pop_back();
    }

}

int main() {
    // 입력:
    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        cin >> jump[i];
    }

    Choose(0);
    cout << ans << '\n';

    return 0;
}