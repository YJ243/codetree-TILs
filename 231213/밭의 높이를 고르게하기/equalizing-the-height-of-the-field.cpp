#include <iostream>
#include <climits>
#define MAX_N 100
using namespace std;

int n,h,t;  // n개의 밭, 연속하게 h높이, 최소 t번 이상
int arr[MAX_N];
int cost = INT_MAX;
int main() {
    cin >> n >> h >> t;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        for(int j=i+t-1; j<n; j++){
            // (i ~ j) 까지 탐색하기, 구간은 최소 t이상
            // 모든 구간의 시작점을 잡아보기
            int cur_cost = 0;
            for(int k=i; k<=j; k++){
                // 해당 구간을 고르게 할 때의 비용 구하
                if(arr[k] < h || arr[k] > h) {
                    cur_cost += abs(arr[k]-h);
                }
            }
            cost = min(cost, cur_cost);
        }
    }
    cout << cost << '\n';
    return 0;
}