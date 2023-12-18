#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;
int n, b;       // n명의 학생에게 b만큼의 예산으로 선물을 줌

pair<int, int> students[MAX_N]; // <학생이 원하는 선물의 가격, 배송비>
int ans;

int main() {
    // 입력
    cin >> n >> b;
    for(int i=0; i<n; i++){
        cin >> students[i].first >> students[i].second;
    }

    for(int i=0; i<n; i++){
        // Step 1. 먼저 pair를 복사하기
        pair<int, int> tmp[n];
        for(int i=0; i<n; i++){
            tmp[i].first = students[i].first;
            tmp[i].second = students[i].second;
        }

        // Step2. i번 학생의 선물을 반값으로 할인하기
        tmp[i].first /= 2;
        
        // Step3. 가격을 기준으로 오름차순 정렬, 그 안에서 배송비를 기준으로 오름차순 정하기
        sort(tmp, tmp+n, [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.first + a.second == b.first + b.second)
                return a.first < b.first;
            return a.first + a.second < b.first + b.second;
        });

        // Step4. 예산범위 내에서 최대 명수 구하기
        int cost = 0, idx = 0;
        while(cost <= b && idx < n){
            cost += tmp[idx].first + tmp[idx].second;
            idx++;
        }
        idx--;
        ans = max(ans, idx);
    }
    cout << ans;
    return 0;
}