#include <iostream>
#include <vector>
#define MAX_N 50
using namespace std;
int n, m, d, s; // n명의 사람이 m개의 치즈를 먹음, 언제 누가 치즈를 먹었는지 d번, 특정 사람이 언제 아팠는지 s번
vector<pair<int, int> > people[MAX_N+1];     // people[i]: i번 번호의 사람이 <m, t> m번 치즈를 t초에 먹음
int sick_time[MAX_N+1];
int ans;
int main() {
    cin >> n >> m >> d >> s;
    for(int i=0; i<d; i++){
        // (p,c,t): p번째 사람이 c번째 치즈를 t초에 먹음
        int p, c, t;
        cin >> p >> c >> t;
        people[p].push_back(make_pair(c,t));
    }

    for(int i=0; i<s; i++){
        // (p,t): p번째 사람이 t초에 확실히 아팠음
        int p, t;
        cin >> p >> t;
        sick_time[p] = t;
    }

    // 모든 치즈를 하나씩 상했다고 가정하기
    for(int i=1; i<=m; i++){
        // 해당 번호의 사람이 언제 아팠는지 배열 선언하기
        int tmp_sick[n+1] = {};
        for(int j=1; j<=n; j++){
            // j번 사람이 i번 치즈를 먹었다면 해당 초 이후부터 아프기 시작했다 표시하기
            for(int k=0; k<(int) people[j].size(); k++){
                if(people[j][k].first == i)
                    tmp_sick[j] = people[j][k].second+1;    // +1초 부터 아프기 시작함
                    //cout << j << "번 사람이 " << tmp_sick[j] << "초 부터 아프기 시작함" << '\n';
            }
        }
        
        int sick_cnt = 0;
        bool passed = true; // 아프기 전에 치즈를 먹었는지, sick_time에 들어가 있는 사람이 먹었는지
        // 그렇다면 이제 sick_time을 보면서 확인하기
        
        for(int j=1; j<=n; j++){
            // 만약 sick_time이 0보다 크다면 아프기 시작한 시점, 그 시점 이전에 치즈를 먹었는지
            if(tmp_sick[j] > 0){
                // 아파지기 전에 먹었거나 아프다고 표시를 안했을 경우 
                if(sick_time[j] > tmp_sick[j]-1 || sick_time[j] == 0)
                    sick_cnt++; // 약 먹어야 하는 사람 수 증가
                else if(sick_time[j] <= tmp_sick[j]-1){ // 아픈 이후에 해댱 상한 치즈를 먹은 경우
                    passed = false;
                    break;
                }
            
            }
            else if(tmp_sick[j] == 0 && sick_time[j] > 0){
                // 배가 아프다고 입력이 들어왔는데 현재 상한 치즈를 먹지 않은 경우
                passed = false; // 해당 경우가 발생할 수 없으니
                break;
            }
        }
        if(!passed) continue;
        ans = max(ans, sick_cnt);

    }
    cout << ans << '\n';

    return 0;
}