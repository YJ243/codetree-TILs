#include <iostream>
#include <string>
using namespace std;

int x, y;
int cur_d;
int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // 북,동,남,서 방향
int main() {
    string cmd;
    cin>>cmd;
    for(auto c : cmd){
        if(c == 'L')
            cur_d = (cur_d+3)%4;
        else if(c == 'R')
            cur_d = (cur_d+1)%4;
        else
            x += dirs[cur_d][0];
            y += dirs[cur_d][1];
    }
    cout<< x << ' ' << y;
    return 0;
}