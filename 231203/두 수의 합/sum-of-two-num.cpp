#include <iostream>
#include <unordered_map>
#define MAX_N 100000
using namespace std;

int n;      // n: 정수 개수
double k;   // 두 수의 합
double arr[MAX_N];
unordered_map<double, int> m;

int main(){
    cin >> n >> k;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        double tmp = k-arr[i];
        if(m.find(tmp) != m.end()){
            // 만약 현재 수와 배열에 있는 수를 더해서 k를 만들 수 있다면
            ans++;
        }
        m[arr[i]]++;
    }
    cout << ans << '\n';
    return 0;
}