#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

#define MAX_N 11
#define MAX_M 15
using namespace std;

int n, m;
vector<pair<int, int> > lines;
vector<pair<int, int> > selected_lines;

int ans = INT_MAX;

bool IsSame(){
    int originArr[n] = {};
    int finalArr[n] = {};
    
    for(int i=0; i<n; i++)
        originArr[i] = finalArr[i] = i;
    
    // 이제 주어진 가로줄을 차례대로 보면서 확인하기
    for(int i=0; i<(int)lines.size(); i++){
        int cur = lines[i].second;
        swap(originArr[cur], originArr[cur+1]);
    }
    for(int i=0; i<(int)selected_lines.size(); i++){
        int cur = selected_lines[i].second;
        swap(finalArr[cur], finalArr[cur+1]);
    }
    for(int i=0; i<n; i++){
        if(originArr[i] != finalArr[i])
            return false;
    }
    return true;
}

void ChooseLine(int cnt){ // cnt번째 가로줄 선택하는 함수
    if(cnt == (int)lines.size()){
        if(IsSame()){
            ans = min(ans, (int)selected_lines.size());
        }
        return;
    }

    selected_lines.push_back(lines[cnt]);
    ChooseLine(cnt+1);
    selected_lines.pop_back();

    ChooseLine(cnt+1);
}

int main(){
    // 입력:
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back(make_pair(x2, x1-1));
    }
    sort(lines.begin(), lines.end());

    // 선택할 수 있는 가로줄 고르기
    ChooseLine(0);

    // 출력
    cout << ans;
    return 0;
}