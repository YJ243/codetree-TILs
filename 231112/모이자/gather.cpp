#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100
using namespace std;

int n;
int people[MAX_N];
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> people[i];
    int min_sum = INT_MAX;
    for(int i=0; i<n; i++){
        int cur_sum = 0;
        for(int j=0; j<n; j++){
            cur_sum += abs(j-i) * people[j];
        }
        if(cur_sum < min_sum)
            min_sum = cur_sum;
    }

    cout << min_sum << '\n';
    return 0;
}