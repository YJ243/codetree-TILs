#include <iostream>
#include <climits>

#define MAX_N 100
using namespace std;

int s, n;
int arr[MAX_N];
int main() {
    cin >> n >> s; // n개의 수, 합이 s와 최대한 가까워져야함
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int min_diff = INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int two_sum = arr[i]+arr[j];    // 제외할 두 수의 합
            if(min_diff > abs(s-(sum-two_sum))){
                min_diff = abs(s-(sum-two_sum));
            }
        }
    }
    cout << min_diff;
    return 0;
}