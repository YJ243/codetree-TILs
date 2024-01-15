#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 1000000


using namespace std;

int n;
bool visited[MAX_N+1];
queue<pair<int, int> > q;
int ans = INT_MAX;


void bfs(){
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first == 1){
            ans = 0;
            break;
        }
        // step 1. -1
        int next = 0;
        for(int i=0; i<4; i++){
            if(i==0)
                next = cur.first-1;
            else if(i==1)
                next = cur.first+1;
            else if(i==2){
                if(cur.first % 2 != 0) continue;
                next = cur.first/2;
            }
            else{
                if(cur.first % 3 != 0) continue;
                next = cur.first/3;
            }

            if(!visited[next]){
                visited[next] = true;
                q.push(make_pair(next, cur.second+1));
                if(next == 1) {
                    ans = min(ans, cur.second+1);
                    break;
                }
            }
        }
        if(ans != INT_MAX) break;
    }
}


int main() {
    cin >> n;
    q.push(make_pair(n,0));
    visited[n] = true;
    bfs();
    cout << ans;
    return 0;
}