#include <iostream>
#define MAX_N 100

using namespace std;
pair<int, int> lines[MAX_N];
int n;
int ans;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> lines[i].first >> lines[i].second;
    }
    for(int i=0; i<n; i++){
        // i번째 선분 검사 시작
        int x1 = lines[i].first, x2 = lines[i].second;
        bool overlapped = false;
        for(int j=0; j<n; j++){
            if(i == j) continue;    // i번 선분 외 다른 선분들 보면서 겹치는지 확인하기
            int x3 = lines[j].first, x4 = lines[j].second;
            if((x3 <= x1 && x2 <= x4) || (x1 <= x3 && x4 <= x2)){
                overlapped = true;
                break;
            }
        }
        // 겹치지 않았다면 정답 개수에 하나를 추가하
        if(!overlapped) ans++;
    }
    cout << ans << '\n';
    return 0;
}