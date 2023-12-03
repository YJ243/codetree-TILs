#include <iostream>
#include <unordered_map>
#define MAX_N 100000

using namespace std;

int n, k; // n: 정수 개수, k: 두 수를 더했을 때의 값
double arr[MAX_N];
unordered_map<double, int> sum_cnt;

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum_cnt[arr[i]+arr[j]]++;
        }
    }
    cout << sum_cnt[k];
    return 0;
}