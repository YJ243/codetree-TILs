#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <climits>
#include <cstdlib>

#define MAX_N 20

using namespace std;

int n;
string s[MAX_N];
vector<int> nums;
vector<int> selected;
pair<int, int> loc[10];
pair<int, int> start_loc;
pair<int, int> end_loc;
int ans = INT_MAX;

void Choose(int idx, int curr_dist, int r, int c){   // idx번째 숫자를 골리야 하고, 현재 curr_dist만큼 이동함, 현재 위치는 (r,c)
    if((int)selected.size() == 3){                   // 3개를 골랐다면
        ans = min(ans, curr_dist + abs(r-end_loc.first) + abs(c-end_loc.second));   // 정답 업데이트
        return;
    }
    for(int i=idx; i < (int)nums.size(); i++){      // idx번째부터 고르기
        selected.push_back(nums[i]);
        Choose(i+1, curr_dist + abs(r-loc[nums[i]].first) + abs(c-loc[nums[i]].second),
        loc[nums[i]].first, loc[nums[i]].second);
        selected.pop_back();
    }
}

int main() {
    // 입력 받기:
    cin >> n;                                   // 격자 크기
    for(int i=0; i<n; i++){                     
        cin >> s[i];                            // 한 줄 입력받기
        for(int j=0; j<n; j++){
            if(s[i][j] == 'S')                  // 시작 위치 넣기
                start_loc = make_pair(i,j);
            else if(s[i][j] == 'E')             // 끝 위치 넣기
                end_loc = make_pair(i,j);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if('1' <= s[i][j] && s[i][j] <= '9'){ // 만약 숫자라면
                int num = (int)s[i][j] - '0';     // 현재 숫자
                nums.push_back(num);              // 현재 격자 칸에 있는 숫자 넣기 
                loc[num] = make_pair(i,j);        // 해당 숫자의 위치 저장하기
            }
        }
    }
    sort(nums.begin(), nums.end());                     // 오름차순 정렬
    Choose(0,0, start_loc.first, start_loc.second);     // 0번째 숫자 골라야 하고, 현재 0만큼 이동했으며, 현재 위치는 start_loc
    if(ans == INT_MAX)                                  // 도착지에 이동할 수 없다면 -1
        ans = -1;
    cout << ans;
    return 0;
}