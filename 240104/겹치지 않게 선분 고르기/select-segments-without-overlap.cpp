#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX_N 15
using namespace std;

int n;
vector<pair<int, int> > lines;
vector<pair<int, int> > selected_lines;
int ans;

void CheckOverlapping(int total){            // 현재까지 선택된 선분들이 겹치는 게 있는지 확인
    bool isOverlapped = false;
    
    for(int i=0; i<total; i++){
        for(int j=0; j<total; j++){
            if(i == j) continue;
            if((selected_lines[i].first <= selected_lines[j].first && selected_lines[j].first <= selected_lines[i].second) || 
                selected_lines[j].first <= selected_lines[i].second && selected_lines[i].second <= selected_lines[j].first) 
                isOverlapped = true;
        }
    }    
    if(!isOverlapped){
        ans = max(ans, total);
    }
    
}

void Choose(int cnt, int start, int total){    // 현재까지 cnt개를 뽑았고, 총 total개의 선분을 고르는 함수
    if(cnt == total){
        CheckOverlapping(total);
        return;
    }
    // 중복순열이여서 시간초과가 뜸 => 시간초과가 안뜨게 중복 없애줘야 하는데...
    for(int i=start; i<n-total+cnt; i++){
        selected_lines.push_back(make_pair(lines[i].first, lines[i].second));
        Choose(cnt+1, start+1, total);
        selected_lines.pop_back();
    }
    
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back(make_pair(x1, x2));
    }
    for(int i=2; i<=n; i++){
        //총 i개를 뽑아서 확인하기
        //cout << i << '\n';
        Choose(0,0, i);
    }
    //cout << ans;
    cout << ans+1;
    return 0;
}