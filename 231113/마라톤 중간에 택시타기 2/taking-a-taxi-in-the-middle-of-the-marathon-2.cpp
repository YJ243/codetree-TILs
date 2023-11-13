#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;
int N;
vector<pair<int, int> > a;
int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    int min_dist = INT_MAX;
    for(int i=1; i<N-1; i++){
        int next = 0;
        int dist = 0;
        int cur_x = a[0].first, cur_y = a[0].second;
        while(true){
            next++;
            if(next== i)
            {
                next++;
            }
            if(next == N)   break;
            dist += abs(cur_x-a[next].first) + abs(cur_y-a[next].second);
            cur_x = a[next].first, cur_y = a[next].second;
        }
        min_dist = min(dist, min_dist);
        
    }

    cout<<min_dist;
    return 0;
}