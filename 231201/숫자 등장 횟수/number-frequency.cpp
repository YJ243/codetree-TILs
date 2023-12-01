#include <iostream>
#include <unordered_map>
#define MAX_N 100000

using namespace std;

int n, m;
int arr[MAX_N];
unordered_map<int, int> num_to_cnt;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        num_to_cnt[arr[i]]++;
    }
    while(m--){
        int k;
        cin >> k;
        cout << num_to_cnt[k] << ' ';
    }
    return 0;
}