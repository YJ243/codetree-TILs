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
    // (r,c)인 S에서 selected에 있는 점들을 거쳐가기
    int curX = x1, curY = y1, curD = 0;

    for(int i=0; i<3; i++){
        curD += abs(curX-route[selected[i]][0]) + abs(curY-route[selected[i]][1]);
        curX = route[selected[i]][0], curY = route[selected[i]][1];
    }
    curD += abs(curX-x2) + abs(curY-y2);
    ans = min(ans, curD);
}

void FindMinDist(int num){
    if(selected.size() >= 3){
        StartWalking();
        return;
    }

    for(int i=num; i<(int)coin.size(); i++){
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
                route[coin_num][0] = i, route[coin_num][1] = j;
                coin.push_back(coin_num);
            }
            else if(s[j] == 'S'){
                x1 = i, y1 = j;
            }
            else{
                x2 = i, y2 = j;
            }
        }
    }
    sort(coin.begin(), coin.end());
    
    if(coin.size() < 3){
        cout << -1;
        return 0;
    }
    // 1. 3개 동전 뽑으면서 e까지 최소 거리 구하기
    FindMinDist(0);
    cout << ans;
    return 0;
}