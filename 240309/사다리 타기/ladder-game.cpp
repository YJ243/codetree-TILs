#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_M 15
#define MAX_N 11
using namespace std;

int n, m;
int result[MAX_N];
pair<int, int> lines[MAX_M];    // 가로줄의 상태
vector<pair<int, int> > selected_lines;
int ans = MAX_N;
void FindResult(){
    // 1. Step 1. lines (a,b)를 b 순으로 오름차순 정렬하기
    sort(lines, lines+m, [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    });
    // 2. 0번부터 끝까지 lines을 보면서 결과 result에 저장하기
    for(int i=0; i<n; i++){
        result[i] = i;
    }
    for(int i=0; i<m; i++){
        int a = lines[i].first;
        int tmp = result[a];
        result[a] = result[a+1];
        result[a+1] = tmp;
    }
}

bool IsSame(){
    // Step 1. selected_lines를 두번째 원소 기준으로 오름차순 정렬하기
    sort(selected_lines.begin(), selected_lines.end(), [](const pair<int, int>& a, const pair<int, int>&b){
            return a.second < b.second;
        });

    // Step 2. 0번부터 끝까지 selected_lines을 보면서 결과 저장하기
    int curResult[n];
    for(int i=0; i<n; i++)
        curResult[i] = i;
    
    for(int i=0; i<(int)selected_lines.size(); i++){
        int a = selected_lines[i].first;
        // a와 a+1번째 바꾸기
        int tmp = curResult[a];
        curResult[a] = curResult[a+1];
        curResult[a+1] = tmp;
    }

    // Step 3. result와 curResult가 같은지 확인하기
    for(int i=0; i<n; i++){
        if(result[i] != curResult[i])
            return false;
    }
    /*
    */
    return true;

}

void FindMinLines(int cnt, int total){     // cnt개를 선택하러 가는 함수
    if((int)selected_lines.size() == total){
        // 아진짜 너무 피곤하고 졸리다................................................................................................
        if(IsSame()){
           ans = min(ans, (int)selected_lines.size());
        }
        return;
    }

    for(int i=cnt; i < m; i++){
        selected_lines.push_back(lines[i]);
        FindMinLines(i+1, total);
        selected_lines.pop_back();
    }

}

int main() {
    cin >> n >> m;      // n: 세로줄 개수, m: 가로줄 개수
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        lines[i] = make_pair(a-1,b-1);
    }

    FindResult();
    for(int i=0; i<=m; i++){
        // 1개부터 m개까지 선분 골라보면서 확인하기
        FindMinLines(0, i);
    }

    cout << ans;
    return 0;
}