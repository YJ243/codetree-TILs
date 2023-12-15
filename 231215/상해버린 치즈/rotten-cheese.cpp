#include <iostream>
#include <tuple>
#include <vector>
#define MAX_N 50
using namespace std;

int n, m, d, s;         // n: 사람의 수, m: 치즈의 수, d: 치즈를 먹은 기록의 수, s: 아픈 기록의 수
int ans;
vector<pair<int, int> > people[MAX_N];
int isAche[MAX_N];      // isAche[i]: i번 사람이 몇 초에 아팠는지(0: 안아픔, 1초이상: 해당 초에 아픔)

int main() {
    cin >> n >> m >> d >> s;
    for(int i=0; i<d; i++){
        // p m t: 몇번째 사람(p-1)가 몇 번째 치즈(m-1)을 언제(t초) 먹었는가?
        int p, m, t;
        cin >> p >> m >> t;
        people[p-1].push_back(make_pair(m-1,t));
        //cout << p-1 << "번 사람이 " << m-1 << "번 치즈를 " << t << "초에 먹음" << '\n';
    }

    for(int i=0; i<s; i++){
        // p t: 몇 번째 사람(p)이 언제 확실히 아팠는지(t초) => 그런데 이거 말고도 더 아픈 사람이 있을 수 있음
        int p, t;
        cin >> p >> t;
        isAche[p-1] = t;
    }

    // 모든 치즈에 대해서 완전 탐색을 진행하는데,
    // 1번부터 차례대로 썩은 치즈라고 가정했을 때, isAche와 비교해서 맞는지 확인
    for(int i=0; i<m; i++){
        //cout << i<<"번 치즈는 썩었어!!"<<'\n';
        int tmpAche[n] = {};
        //cout << tmpAche[0] << '\n';        // i번 치즈는 썩은 치즈
        // people vector를 돌면서 해당 치즈를 먹었으면 다음 1초 뒤부터 배 아프다고 표시하기
        for(int j=0; j<n; j++){
            for(auto a : people[j]){
                // j번 사람이 몇번째 치즈를 언제 먹었는지 보기
                if(a.first == i){
                    // 만약 해당 상한 치즈를 먹었다면 그 다음 초에 배아프다고 체크하기
                    tmpAche[j] = a.second+1;
                   // cout << j << "번 사람이 " << a.first << "번 치즈를 " << a.second << "초에 먹어서 배가 " << tmpAche[i] << "초에 아프게 됨"<<'\n';   
                }
            }
        }
        // 문제에서 주어진 isAche와 비교해서 맞는지 확인
        int acheCnt = 0;
        bool isCorrect = true;

        for(int j=0; j<n; j++){
            if(tmpAche[j] == 0 && isAche[j] > 0){
                isCorrect = false;
                break;
            }
            //cout << tmpAche[j] << ' ' ;
            if(tmpAche[j] > 0){
                // 만약 현재 턴에서 배가 아픈 사람인데 이전에 아팠다고 기록이 주어지지 않았다면
                acheCnt++;
            }
            
        }

        if(isCorrect)
            ans = max(ans, acheCnt);
    }

    cout << ans << '\n';
    return 0;
}