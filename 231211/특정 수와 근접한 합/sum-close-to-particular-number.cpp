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
    int info[2];    // info[0]: 전체합-두개합의 최소, info[0]: 그때의 수 첫번째, info[1]: 그때의 수 두번째

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int two_sum = arr[i]+arr[j];
            if(min_diff > sum-two_sum){
                info[0] = i, info[1] = j;
                mindiff = sum-two_sum;
            }
        }
    }
    cout << abs(info[0]-info[1]);
    return 0;
}