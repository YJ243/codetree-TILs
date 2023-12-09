#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
#define MAX_N 100000
#define MAX_G 250000

int n, g;
vector<int> person_in_groups[MAX_G];  // person_in_groups[i]: i번 사람이 몇 번 그룹들에 속해있는가?
bool invited[MAX_N];        // n번째 사람이 초대받았는지
unordered_set<int> not_invited[MAX_G];  // groups[i]: i번째 그룹에서 초대받지 못한 사람들의 번호들
int ans;

queue<int> q;       // bfs를 위한 큐

int main(){
    cin >> n >> g;

    for(int i=0; i<g; i++){
        int cnt;
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            int num;
            cin >> num; num--;
            not_invited[i].insert(num);         // i번 그룹에 num번 학생을 넣기
            person_in_groups[num].push_back(i); // num번 학생은 i번 그룹에 있다.
        }
    }

    // 0번 학생 넣기
    
    invited[0] = true;
    q.push(0);

    while(!q.empty()){
        int person_num;
        person_num = q.front();
        q.pop();
        ans++;

        for(int i=0; i<person_in_groups[person_num].size(); i++){
            int group_num = person_in_groups[person_num][i];
            // 해당 사람이 들어있는 그룹에서 해당 사람 제거하기
            not_invited[group_num].erase(person_num);
            if(not_invited[group_num].size() == 1){
                // 제거하고 남은 사람이 해당 그룹에서 1명이라면
                int inviting_num = *not_invited[group_num].begin();
                if(!invited[inviting_num]){
                    // 만약 초대장을 받지 못했다면
                    invited[inviting_num] = true;
                    q.push(inviting_num);
                }
            }
        }
    }
    cout << ans;
    return 0;
}