#include <iostream>
using namespace std;
int x, y;
int N;
int dirs[4][2]={{1,0},{0,-1},{-1,0},{0,1}}; // E, S, W, N 
int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        char c;
        int d;
        cin>>c>>d;
        if(c == 'E'){
            x += dirs[0][0]*d;
            y += dirs[0][1]*d;
        }
        else if(c == 'S'){
            x += dirs[1][0]*d;
            y += dirs[1][1]*d;
        }
        else if(c == 'W'){
            x += dirs[2][0]*d;
            y += dirs[2][1]*d;
        }
        else{
            x += dirs[3][0]*d;
            y += dirs[3][1]*d;
        }
    }
    cout<<x << " " << y;
    return 0;
}