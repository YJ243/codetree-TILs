/*
 * Backtracking을 사용하여 1로 시작하는 가능한 모든 순열을 탐색
 * 모든 순열에 대해 비용 합을 계산하여 그 중 최솟값을 찾아
 * 이 때 비용을 더하는 도중 비용이 0인 경우가 있다면 불가능한 경우여서 답으로 갱신하면 안됨
 * 그런데 이 조건을 빼뜨려서 틀림
 * 항상 손으로 설계를 할 때 각각 케이스마다 예외케이스가 무엇이 있을까 생각하기
 * 시간복잡도: 가능한 모든 순열: N!개, 순열을 만든 이후 각각에 대해 n개의 지점을 보며 비용의 합을 구해줘야 함
 * 따라서 O(N! * N)
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 10

using namespace std;

vector<int> selected;
// 변수 선언
int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
int ans = INT_MAX;

// 지금까지 고른 번호를 토대로 최소 이동 거리 계산
void FindMinCost(){
    int currCost = 0, curNum = 0;
    bool Movable = true;
    for(int i=0; i<(int)selected.size(); i++){
        if(grid[curNum][selected[i]] == 0){ // 만약 중간에 이동불가한 곳이 있다면 false
            Movable = false;
        }
        currCost += grid[curNum][selected[i]];
        curNum = selected[i];
    }
    currCost += grid[curNum][0];
    if(grid[curNum][0] == 0) Movable = false; // 마지막도 이동 불가한지 확인
    if(Movable) // 가능한 경우에만 업데이트 해주기
        ans = min(ans, currCost);
}

// 1다음으로 이동할 num번째 번호를 고르는 함수
void Choose(int num){
    if(num == n){
        FindMinCost();
        return;
    }

    for(int i=1; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        selected.push_back(i);

        Choose(num+1);

        visited[i] = false;
        selected.pop_back();
    }
}

int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    Choose(1);      // 1다음 첫 번째로 이동할 번호를 고르는 함수 (가운데 부분만 고르기)    
    cout << ans;
    return 0;
}

// 해설 풀이
/*

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 10

using namespace std;

// 변수 선언
int n;
int cost[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> picked;

int ans = INT_MAX;

// 지금까지 방문한 지점의 수를 cnt라 했을 때
// 계속 탐색을 이어서 진행하기
void FindMin(int cnt){
    // 모든 지점을 방문했을 때
    // 가능한 지금까지의 비용 합 중 최솟값 갱신
    if(cnt == n){
        int total_cost= 0;
        for(int i=0; i<(int)picked.size()-1; i++){
            int curr_cost = cost[picked[i]][picked[i+1]];
            // 만약 비용이 0이라면 불가능한 경우이므로 바로 함수를 빠져나오기
            if(curr_cost == 0) return;

            total_cost += curr_cost;
        }
        // 최종적으로 1번 지점으로 다시 돌아오는 것까지 고려해서 계산해주기
        int additional_cost = cost[picked.back()][0];
        if(additional_cost == 0) return;

        // 답을 갱신해주기
        ans = min(ans, total_cost + additional_cost);
        return;
    }

    // 방문할 지점을 선택
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visite[i] = true;
        picked.push_back(i);
        FindMin(cnt+1);

        visited[i] = false;
        picked.pop_back();
    }
}

int main(){
    // 입력:
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> cost[i][j];

    // 1번 지점을 시작으로 탐색을 진행
    visited[0] = true;
    picked.push_back(0);
    FindMin(1);

    cout << ans;
    return 0;
}
*/