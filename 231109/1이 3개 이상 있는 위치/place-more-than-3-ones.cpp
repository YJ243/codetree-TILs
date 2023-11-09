#include <iostream>
#define MAX_N 100
using namespace std;
int n;
int maze[MAX_N][MAX_N];
int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool InRange(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>maze[i][j];
        }
    }
    int result=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = 0;
            for(int d=0; d<4; d++){
                int next_x = i+dirs[d][0], next_y = j+dirs[d][1];
                if(InRange(next_x, next_y) && maze[next_x][next_y]) cnt++;
            }
            if(cnt>=3){
                result++;
            }
        }
    }
    cout<<result;
    return 0;
}