#include <iostream>
#define MAX_N 50
using namespace std;
int maze[MAX_N][MAX_N];
int n, t;
int r, c;
char d;
int cur_d;
int dirs[4][2] = {{0,1},{-1,0},{1,0},{0,-1}}; // R,U,D,L

bool InRange(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;
    r--;c--;

    if(d=='U'){
        cur_d=1;
    }
    else if(d == 'R')
        cur_d=0;
    else if(d == 'D')
        cur_d=2;
    else
        cur_d=3;

    while(t--){
        int nr=r+dirs[cur_d][0], nc=c+dirs[cur_d][1];
        if(InRange(nr,nc)){
            r = nr;
            c = nc;
        }
        else cur_d = 3-cur_d;

    }
    cout<<r+1 << ' ' <<c+1;
    return 0;
}