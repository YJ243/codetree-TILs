#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 15

using namespace std;
int n, ans;
pair<int, int> lines[MAX_N];
vector<pair<int, int> > selected_lines;

bool IsOverlapped(pair<int, int> a, pair<int, int> b){
    int x1 = a.first, x2 = a.second;
    int x3 = b.first, x4 = b.second;
    return (x1 <= x3 && x3 <= x2) || ( x3 <= x1 && x1 <= x4); 
}

int Calc(){
    for(int i=0; i<(int)selected_lines.size(); i++){
        for(int j=i+1; j < (int)selected_lines.size(); j++){
            if(IsOverlapped(selected_lines[i], selected_lines[j]))
                return -1;
        }
    }
    return (int)selected_lines.size();
}

void ChooseLine(int idx){   // idx번째 선분을 고르는 함수
    for(int i=0; i<(int)selected_lines.size(); i++){
        ans = max(ans, Calc());
    }

    if(idx >= n){
        return;
    }

    for(int i=idx; i<n; i++){
        selected_lines.push_back(lines[i]);
        ChooseLine(i+1);
        selected_lines.pop_back();

    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        lines[i] = make_pair(x1, x2);
    }

    ChooseLine(0);
    cout << ans;
    return 0;
}