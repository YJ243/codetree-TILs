#include <iostream>
#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int ans = 0;
    // 각 숫자에 대해 등차수열의 개수를 확인하
    for(int k=1; k<=MAX_N; k++){
        // 자연수 k를 적절하게 잡아보기
        int cur = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((arr[i]+arr[j]) == 2*k)    cur++;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}