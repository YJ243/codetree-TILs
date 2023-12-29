#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

#define MAX_N 100

int n, m;
int arr[MAX_N];

bool IsPossible(int maxSum) {
    int sum = 0, count = 1;
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > maxSum) {
            sum = arr[i];
            count++;
            if (count > m) return false;
        } else {
            sum += arr[i];
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = *max_element(arr, arr + n); // 배열의 최댓값
    int right = accumulate(arr, arr + n, 0); // 배열의 전체 합
    int ans = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (IsPossible(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}