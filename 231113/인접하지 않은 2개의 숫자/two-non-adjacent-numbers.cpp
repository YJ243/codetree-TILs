#include <iostream>
#include <algorithm>


#define MAX_N 100
using namespace std;
int N;
int arr[MAX_N];
int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    int ans = 0;
    for(int i=0; i<N-2; i++)
        for(int j=i+2; j<N; j++){
            int cur = arr[i] + arr[j];
            ans = max(ans, cur);
        }
    
    cout << ans;
    return 0;
}