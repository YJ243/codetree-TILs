#include <iostream>
#include <climits>
#define MAX_N 1003
using namespace std;
int N;
int room[MAX_N]; // 들어가야 하는 사람 명수
int main() {
    cin >> N;
    int min_dist = INT_MAX;
    int total=0;
    for(int i=0; i<N; i++){
        cin >> room[i];
        total += room[i];
    }
    for(int i=1; i<N; i++){
        // 0번째 방에서 시작하는 경우
        int cur_dist = 0;
        int next_idx = (i+1)%N;
        int next = i+1;
        while(true){
            if(next_idx == i) 
                break;
            cur_dist += room[next_idx]*(next-i);
            next_idx = (next_idx+1)%N;
            next++;
        }
        
        min_dist = min(cur_dist, min_dist);
    }
    cout<<min_dist;
    return 0;
}