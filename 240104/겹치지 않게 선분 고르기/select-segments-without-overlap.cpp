#include <iostream>
#include <vector>
#include <tuple>
#define MAX_N 15
using namespace std;

int n;
pair<int, int> lines[MAX_N]; 
vector<int> selected_idx;
int ans;

bool isOverlapped(){
    for(int i=0; i<(int)selected_idx.size(); i++){
        for(int j=0; j<(int)selected_idx.size(); j++){
            if(i==j) continue;
            int x1, x2, x3, x4;
            tie(x1,x2) = lines[i];
            tie(x3,x4) = lines[j];
            if((x1 <= x3 && x3 <= x2) || (x3 <= x1 && x1 <= x4)){
                cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << '\n';
                return true;
            }
        }
    }
    return false;
}

void SelectLine(int num){   // num번째 선분 선택을 결정하는 함수
    if(num == n){
        if(!isOverlapped()){
            // 만약 선분 조합이 겹치지 않으면
            int cur = (int)selected_idx.size();
            ans = max(ans, cur);
        }
        return;
    }

    selected_idx.push_back(num);
    SelectLine(num+1);
    selected_idx.pop_back();

    SelectLine(num+1);
}

int main(){
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> lines[i].first >> lines[i].second;
    }

    SelectLine(0);  // 0번째 선분을 확인하러 호출
    cout << ans;
    return 0;
}