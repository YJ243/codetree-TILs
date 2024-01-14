#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 20
using namespace std;

int n, m;
int a[MAX_N][2];
vector<pair<int, int> > selected_pos;
int ans = INT_MAX;
void FindMinDist(){
    int curr=0;
    for(int i=0; i<(int)selected_pos.size(); i++){
        for(int j=i+1; j<(int)selected_pos.size(); j++){
            curr = (selected_pos[i].first-selected_pos[j].first)*(selected_pos[i].first-selected_pos[j].first) 
            + (selected_pos[i].second-selected_pos[j].second)*(selected_pos[i].second-selected_pos[j].second);
            ans = min(ans, curr);
        }
    }
}

void Choose(int idx){
    if((int)selected_pos.size() == m){
        FindMinDist();
        return;
    }
    for(int i=idx; i<n; i++){
        selected_pos.push_back(make_pair(a[i][0],a[i][1] ));
        Choose(i+1);
        selected_pos.pop_back();
    }

}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    // m개를 선택하고, 그 중에서 두개를 선택
    Choose(0);  // 0번째를 선택하는 함수
    cout << ans;
    return 0;
}