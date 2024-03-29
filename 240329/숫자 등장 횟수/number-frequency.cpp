#include <iostream>
#include <unordered_map>

using namespace std;
int n, m;
unordered_map<int, int> num_to_cnt;

int main() {
    cin >> n >> m;    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        num_to_cnt[x]++;
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        cout << num_to_cnt[x] << ' ';
    }
    return 0;
}