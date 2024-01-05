/*
 * 2024.1.5
 * 현재 입력으로 주어진 가로줄 m개 중에서 조합을 만들어 보면 되는데
 * 아예 처음부터 m개 외에도 나올 수 있는 모든 경우의 수를 생각해서 틀림: (n-1)*m
 * 또한 사다리게임에서 진행이 위에서부터 아래로 내려오면서 가로선이 있을 때 
 * 해당 위치에 있는 두 값을 바꾸는 것으로 시뮬레이션이 가능하다는 것을 몰랐음
*/
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

// 처음 상황과, 선택한 가로줄만 사용했을 때의 상황을 시뮬레이션
// 둘의 결과가 같은지 확인
bool IsSame(){
    // Step1. 시작 숫자를 세팅
    int originArr[n] = {};
    int finalArr[n] = {};
    
    for(int i=0; i<n; i++)
        originArr[i] = finalArr[i] = i;
    
    // Step2. 위에서부터 순서대로 적혀있는 가로줄에 대해 양쪽 번호에 해당하는 숫자를 바꿔줌
    // 주어진 가로줄을 차례대로 보면서 확인하기
    for(int i=0; i<(int)lines.size(); i++){
        int cur = lines[i].second;
        swap(originArr[cur], originArr[cur+1]);
    }
    for(int i=0; i<(int)selected_lines.size(); i++){
        int cur = selected_lines[i].second;
        swap(finalArr[cur], finalArr[cur+1]);
    }
    // Step3. 두 상황의 결과가 동일한지 확
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