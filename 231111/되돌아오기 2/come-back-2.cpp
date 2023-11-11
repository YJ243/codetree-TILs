#include <iostream>
#include <string>
using namespace std;

int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 위,오,아,왼 방향
int x, y, cur_d;
int t;
int main() {
    string cmd;
    cin >> cmd;
    for(auto c : cmd){
        if(c=='F'){
            x += dirs[cur_d][0];
            y += dirs[cur_d][1];
            if(x==0 && y == 0){
                t++;
                break;
            }
        }
        else if(c=='R'){
            cur_d = (cur_d+1)%4;
        }
        else{
            cur_d = (cur_d-1)%4;
        }
        t++;
    }

    if(t==0){
        cout<<-1;
    }
    else    cout<<t;
    return 0;
}