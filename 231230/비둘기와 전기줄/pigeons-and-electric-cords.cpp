/*
 * 2023.12.30
 * 내 풀이
*/

#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 100

using namespace std;
int n;

unordered_map<int, vector<int>> count;  // count[i]: i번 비둘기의 위치들 
int ans;    // 비둘기 위치 증가 횟수

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int number, loc;
        cin >> number >> loc;
        count[number].push_back(loc);
    }

    for(int i=1; i<=10; i++){   // 1번부터 10번 비둘기까지 확인하기
        if(count[i].size() <= 1) continue;  // 만약 위치가 바꼈는지 확인할 수 없으면 넘어가기
        int cur = count[i][0];              // 첫 번째 위치를 현재 위치로 보기
        for(int j=1; j<count[i].size(); j++){
            if(cur != count[i][j]){         // 만약 위치가 달라졌다면
                ans++;                      // 비둘기가 이동했으므로 횟수 증가
                cur = count[i][j];
            }
        }
    
    }
    cout << ans;
    return 0;
}

/*
 * 해설


#include <iostream>

#define MAX_N 100
#define MAX_NUM 10

#define UNDEFINED -1

using namespace std;

int n;

// 움직인 비둘기 번호와, 움직인 방향을 기록하기
int pigeon[MAX_N+1], move_dir[MAX_N+1];

// 현재 비둘기의 위치를 기록
// UNDEFINED면 아직 미정인 상태
int main(){
    // 입력:
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> pigeon[i] >> move_dir[i];

    // 처음 비둘기 상태는 전부 미정
    for(int i=1; i<=MAX_NUM; i++)
        pos[i] = UNDEFINED;
    int move_cnt = 0;

    // 입력으로 주어진 움직임에 따라
    // 비둘기 위치를 이동시키기
    for(int i=1; i<=n; i++){
        // 해당 비둘기의 위치가 미정이라면
        if(pos[pigeon[i]] == UNDEFINED){
            // 주어진 첫 번째 위치에서 시작한다고 생각하는게
            // 비둘기의 이동 횟수를 최소로 할 수 있는 방법
            pos[pigeon[i]] = move_dir[i];
        }
        // 이미 비둘기의 위치가 정해져 있는데
        // 옮겨간 위치와 다른 위치라면?
        else if(pos[pigeon[i]] != move_dir[i]){
            // 이동시켜준 뒤,
            pos[pigeon[i]] = move_dir[i];
            // 답 갱신
            move_cnt++;
        }
    }
    cout << move_cnt;
    return 0;
}
*/