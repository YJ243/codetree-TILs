#include <iostream>
using namespace std;

int x;
int make_sum(int fin){  // fin부터 1까지 더한 값
    int ret = 0;
    for(int i=1; i<=fin; i++)
        ret += i;
    return ret;
}
int main() {
    cin >> x;
    int time_sec = 1;
    int cur_speed = 1;
    int final_loc = x;
    x--;
    //cout << x-cur_speed << '\n';
    // 현재 속도에서 -1, 0, 1을 했을 때 x까지 도달할 수 있는지, 그리고 그 시점에서 속력이 1m/s가 되는가?
    while(x > 0){   // x가 0이 되면 반복문 빠져나오기
        time_sec++; // 현재 시간 1초 증가

        // 매 초마다 속도를 낮출지, 유지할지 높일지 선택하기
        if((x-cur_speed >= final_loc/2 -1 )|| x-make_sum(cur_speed)>0){
            // 속도 높이기
            cur_speed++;
            x -= cur_speed;
           // cout << x << ' ';
        }
        else if(x >= make_sum(cur_speed)){
            // 속도 그대로 유지
            x -= cur_speed;
        }
        else{
            // 속도 낮추기
            cur_speed--;
            x -= cur_speed;
        }
        //cout << cur_speed << ' ';
    }
    cout << time_sec;
    return 0;
}