#include <iostream>
#include <algorithm>
#define MAX_N 20
using namespace std;

int N;
int arr[MAX_N][MAX_N];
int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>arr[i][j];
    int max_sum = 0;
    for(int x=0; x<N; x++){
        for(int y=0; y<N-2; y++){
            max_sum = max(max_sum, arr[x][y]+arr[x][y+1]+arr[x][y+2]);
        }
    }
    cout << max_sum;
    return 0;
}