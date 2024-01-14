/*
 * 내 풀이
*/
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#define MAX_N 20
using namespace std;

int n;
int ans = INT_MAX;
int route[10][2];       // (route[i][0], route[i][1]): i번 동전의 위치
vector<int> coin;       // 현재 나와있는 동전들
vector<int> selected;
int x1, y1;             // 시작 위치
int x2, y2;             // 마지막 위치

void StartWalking(){
    // (x1,y1)인 S에서 selected에 있는 점들을 거쳐가기
    int curX = x1, curY = y1, curD = 0;

    for(int i=0; i<3; i++){ // 고른 동전을 차례대로 보면서 거리 계산
        curD += abs(curX-route[selected[i]][0]) + abs(curY-route[selected[i]][1]);
        curX = route[selected[i]][0], curY = route[selected[i]][1];     // 보고 있는 동전의 위치로 현재 위치 변경
    }
    curD += abs(curX-x2) + abs(curY-y2);    // 마지막 동전에서 end까지 거리 계산
    ans = min(ans, curD);                   // 최종 움직인 거리 업데이트
}

void FindMinDist(int num){
    if(selected.size() >= 3){   // 3개를 골랐으면
        StartWalking();         // 걸어서 나오는 거리 계산하기
        return;
    }

    for(int i=num; i<(int)coin.size(); i++){    // 앞에서부터 숫자가 증가하는 순서대로 동전 고르기
        selected.push_back(coin[i]);
        FindMinDist(i+1);
        selected.pop_back();
    }
}
int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == '.'){
                continue;
            }
            else if('1' <= s[j] && s[j] <= '9'){
                int coin_num = (int)(s[j]-'0');
                route[coin_num][0] = i, route[coin_num][1] = j;     // coin_num번 동전의 위치 저장
                coin.push_back(coin_num);                           // coin_num번 동전 넣기(몇 번 동전이 나왔는지 나중에 확인하기 위해)
            }
            else if(s[j] == 'S'){
                x1 = i, y1 = j;
            }
            else{
                x2 = i, y2 = j;
            }
        }
    }
    sort(coin.begin(), coin.end()); // 동전 순서대로 정렬
    
    // 1. 3개 동전 뽑으면서 e까지 최소 거리 구하기
    FindMinDist(0);
    
    if(coin.size() < 3){
        ans = -1;
    }
    cout << ans;

    return 0;
}

/*

// 해설
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

#define MAX_N 20
#define COIN_NUM 9

using namespace std;

int n;
int m = 3;

char grid[MAX_N][MAX_N];

vector<pair<int, int> > coin_pos;
vector<pair<int, int> > selected_pos;

pair<int, int> start_pos;
pair<int, int> end_pos;

int ans = INT_MAX;

int Dist(pair<int, int> a, pair<int, int> b){
    int ax, ay;
    tie(ax, ay) = a;

    int bx, by;
    tie(bx, by) = b;

    return abs(ax-bx) + abs(ay-by);
}

int Calc(){
    int num_moves = Dist(start_pos, selected_pos[0]);
    for(int i=0; i<m-1; i++)
        num_moves += Dist(selected_pos[i], selected_pos[i+1]);
    num_moves += Dist(selected_pos[m-1], end_pos);
    return num_moves;
}

void FindMinMoves(int curr_idx, int cnt){
    if(cnt == m){
        // 선택된 모든 조합에 대해 이동 횟수를 계산함
        ans = min(ans, Calc());
        return;
    }
    if(curr_idx == (int) coin_pos.size())
        return;
    
    // curr_idx index에 있는 동전을 선택하지 않은 경우
    FindMinMoves(curr_idx+1, cnt);

    // curr_idx index에 있는 동전을 선택한 경우
    selected_pos.push_back(coin_pos[curr_idx]);
    FindMinMoves(curr_idx+1, cnt+1);
    selected_pos.pop_back();
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
                start_pos = make_pair(i,j);
            if(grid[i][j] == 'E')
                end_pos = make_pair(i,j);
        }

    // 동전을 오름차순으로 각 위치를 집어넣기
    // 이후에 증가하는 순서대로 방문하기 위함
    for(int num=1; num <= COIN_NUM; num++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == num + '0')
                    coin_pos.push_back(make_pair(i,j));
    FindMinMoves(0,0);

    if(ans == INT_MAX)
        ans = -1;
    cout << ans;
    return 0;
}
*/