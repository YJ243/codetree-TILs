#include <iostream>
#include <unordered_set>
#include <vector>
#define MAX_N 100000
#define MAX_G 250000

using namespace std;

int n, g;
bool received[MAX_N+1];   // selected[i]: i번 번호를 가진 사람이 초대장을 받았는지 여부
int person_in_group[MAX_G];  // person_in_group[i]: 그 중 초대장 받은 수
vector<int> num_in_group[MAX_G];  // num_in_group[i]: i번 그룹에 있는 번호표들 
unordered_set<int> ans;                  // 초대장 받은 번호들
int max_person;

int main() {
    cin >> n >> g;  // 1~n번까지 번호표, g개 그룹
    for(int i=0; i<g; i++){
        int cnt;
        cin >> cnt;
        max_person = max(max_person, cnt);
        for(int j=0; j<cnt; j++){
            int number_person;
            cin >> number_person;
            num_in_group[i].push_back(number_person);
        }
    }

    // 1번 사람에게 초대장 주기
    ans.insert(1);
    received[1] = true;
    for(int i=0; i<g; i++){
        for(auto person: num_in_group[i]){
            if(person == 1){
            // 만약 1이 그룹에 있다면
                person_in_group[i]++;
            }
        }
    }
/*
    for(int pp=0; pp<g; pp++)
        cout << num_in_group[pp].size() << ' ' << person_in_group[pp]<<'\n';
*/
    for(int cnt=0; cnt<=max_person; cnt++){  // 가장 많은 인원수를 가진 그룹의 인원수*10만큼 반
        for(int i=0; i<g; i++){         // 모든 그룹을 탐색,
            if(num_in_group[i].size() == person_in_group[i]) continue;      // 그 그룹이 초대장을 다 받았다면 무시
            
            else if(num_in_group[i].size()-1 == person_in_group[i]){        // 그룹 인원수가 k인 그룹에서 k-1명 사람들이 초대장을 받았다면
                // 나머지 한명은 무조건 받음
                for(auto person: num_in_group[i]){
                    if(!received[person]){
                        received[person] = true;
                        ans.insert(person);
                        person_in_group[i]++;
                    }
                }
            }
            else{   // k-1보다 적은 사람들이 초대장을 받았다면
                // 초대장 받은 사람 업데이트
                for(int p=1; p<=n; p++){
                    // 만약 초대장을 받은 사람이 해당 그룹에 있다면
                    if(received[p]){
                        for(auto person:num_in_group[i]){
                            if(p == person){
                                person_in_group[i]++;   // 해당 그룹에서 초대장 받은 인원수 추가
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans.size();
    return 0;
}