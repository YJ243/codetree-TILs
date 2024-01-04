/*
 * 2024.1.4
 * 1. 잦은 실수가 많아서 푸는데 오래 걸림
 * 2. 조합을 백트래킹으로 처음 풀어봐서 풀이를 만들지 못함
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
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
            tie(x1,x2) = lines[selected_idx[i]];
            tie(x3,x4) = lines[selected_idx[j]];
            if((x1 <= x3 && x3 <= x2) || (x3 <= x1 && x1 <= x4)){
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

/*
 * 해설 풀이


#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_N 15

using namespace std;

int n;
pair<int, int> segments[MAX_N];

int ans;
vector<pair<int, int> > selected_segs;

bool Overlapped(pair<int, int> seg1, pair<int, int> seg2){
    int ax1, ax2;
    tie(ax1, ax2) = seg1;

    int bx1, bx2;
    tie(bx1, bx2) = segs2;

    // 두 선분이 겹치는지 여부는 한 점이 다른 선분에 포함되는 경우로 판단 가능
    return (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) ||
           (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
}

bool Possible(){
    // 단 한쌍이라도 선분끼리 겹치면 안됨
    for(int i=0; i<(int)selected_segs.size(); i++)
        for(int j=i+1; j<(int)selected_segs.size(); j++)
            if(Overlapped(selected_segs[i], selected_segs[i]))
                return false;
    
    return true;
}

void FindMaxSegments(int cnt){
    if(cnt == n){
        if(Possible())
            ans = max(ans, (int) selected_segs.size());
        return;
    }

    selected_segs.push_back(segments[cnt]);
    FindMaxSegments(cnt + 1);
    selected_segs.pop_back();

    FindMaxSegments(cnt+1);
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        segments[i] = make_pair(x1, x2);
    }
    FindMaxSegments(0);

    cout << ans;
    return 0;
}
*/