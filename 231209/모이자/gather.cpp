#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100
using namespace std;

int people[MAX_N];
int n;
int min_distance = INT_MAX;
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> people[i];
    
    for(int i=0; i<n; i++){
        int distance_sum = 0;
        for(int j=0; j<n; j++){
            distance_sum += abs(i-j)*people[j];
        }
        min_distance = min(min_distance, distance_sum);
    }
    cout << min_distance;
}