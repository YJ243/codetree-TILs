#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int n;
string s;
int ans = INT_MAX;
int main() {
    cin >> n;
    cin >> s;

    // i는 연속 부분 문자열의 개수임
    for(int i=1; i<=n/2+1; i++){
        // step 1. s에서 i개수만큼 앞에서부터 뽑기
        int i_max = 0;
        for(int j=0; j<n; j++){
            // s에서 j번 인덱스부터 i 길이의 부분 문자열을 가짐
            string cur = s.substr(j, i);
            int cnt = 0;
            for(int k=0; k<n-i+1; k++){
                // step 2. 그 뽑은 문자열을 처음에서부터 볼 때 2개 이상이 나오는지 확인
                string tmp = s.substr(k,i);
                if(tmp == cur)  cnt++;
            }
            i_max = max(i_max, cnt);
        }
        if(i_max == 1){
            ans = min(ans, i);
        }
    }
    cout << ans;
    return 0;
}