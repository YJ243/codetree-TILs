#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 100

using namespace std;
int n;
//vector<vector<int
unordered_map<int, vector<int>> count;
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int number, loc;
        cin >> number >> loc;
        count[number].push_back(loc);
    }

    for(int i=1; i<=n; i++){
        if(count[i].size() <= 1) continue;
        int cur = count[i][0];
        for(int j=1; j<count[i].size(); j++){
            if(cur != count[i][j]){
                ans++;
                cur = count[i][j];
            }
        }
        //cout << cur << '\n';
    }
    cout << ans;

    
    return 0;
}