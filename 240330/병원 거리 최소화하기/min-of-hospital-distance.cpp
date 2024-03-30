#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#define MAX_N 50
using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
vector<pair<int, int> > hospitals;
vector<pair<int, int> > selected;
vector<pair<int, int> > people;

int ans = INT_MAX;

void Input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];      // 0: 빈칸, 1: 사람, 2: 병원
            if(grid[i][j] == 1)
                people.push_back(make_pair(i,j));
            else if(grid[i][j] == 2)
                hospitals.push_back(make_pair(i,j));
        }
    }
}

int Calc(){
    int total_dist = 0;
    // selected에 있는 병원에서 사람까지의 거리 더하기
    for(int i=0; i<(int)people.size(); i++){
        int px = people[i].first, py = people[i].second;
        int min_dist = INT_MAX;
        for(int j=0; j<m; j++){
            int hx = selected[j].first, hy = selected[j].second;
            min_dist = min(min_dist, abs(px-hx) + abs(py-hy));
        }
        total_dist += min_dist;
    }
    return total_dist;
}

void Choose(int idx){
    if((int)selected.size() == m){
        ans = min(ans, Calc());
        return;
    }

    for(int i=idx; i<(int)hospitals.size(); i++){
        selected.push_back(hospitals[i]);
        Choose(i+1);
        selected.pop_back();
    }
}

int main() {
    // 입력받기
    Input();    

    Choose(0);  // 0번째 병원 고르기
    cout << ans;
    return 0;
}