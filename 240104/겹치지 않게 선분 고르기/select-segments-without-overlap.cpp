#include <iostream>
#include <vector>
#include <tuple>
#define MAX_N 15
using namespace std;

int n;
vector<pair<int, int> > lines;
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back(make_pair(x1, x2));
    }

    for(int i=0; i<n; i++){
        int NotOverlapping = 0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            //i번 선분과 겹치지 않은 선분이 몇개가 있는지 확인
            int x1I, x2I, x1J, x2J;
            tie(x1I, x2I) = lines[i];
            tie(x1J, x2J) = lines[j];
            if((x1I <= x1J && x1J <= x2I) || x1J <= x1I && x1I <= x2J) continue;
            NotOverlapping++;
        }
        ans = max(ans, NotOverlapping);
    }
    cout << ans+1;
    return 0;
}