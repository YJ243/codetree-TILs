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
            //cout << i << ' ' << j << '\n';
            int cur_cost = 0;
            for(int k=i; k<=j; k++){
                if(arr[k] < h) cur_cost++;
                else if(arr[k] > h) cur_cost++;
            }
            cost = min(cost, cur_cost);
        }
    }
    cout << cost << '\n';
    return 0;
}