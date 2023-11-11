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
        t++;
        if(c=='F'){ // F가 주어지면
            // 바라보고 있는 방향으로 한칸 이동
            x += dirs[cur_d][0];
            y += dirs[cur_d][1];
            if(x==0 && y == 0){     // (0,0)으로 돌아온다면
                break;
            }
        }
        else if(c=='R'){
            cur_d = (cur_d+1)%4;
        }
        else{
            cur_d = (cur_d+3)%4;
        }
    }

    if(t != 0 && (x ==0 && y == 0)){
        cout<<t;
    }
    else cout << -1;
    return 0;
}