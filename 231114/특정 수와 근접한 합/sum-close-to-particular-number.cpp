#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAX_N 100

using namespace std;

int N,S;
int arr[MAX_N];
int main() {
    cin >> N >> S;
    int total = 0;
    for(int i=0; i<N; i++){
        cin >>arr[i];
        total += arr[i];
    }
    int min_diff = 10000;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int r = arr[i]+arr[j];

            min_diff = min(min_diff, abs(S-(total-r)));
        }
    }
    cout << min_diff<<'\n';
    return 0;
}