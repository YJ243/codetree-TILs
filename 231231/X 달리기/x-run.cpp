// 2023.12.31
#include <iostream>
using namespace std;

int x;

int main() {
    cin >> x;
    int time_sec = 1;
    int cur_speed = 1;
    int final_loc = x;
    x--;
    // 현재 속도에서 -1, 0, 1을 했을 때 x까지 도달할 수 있는지, 그리고 그 시점에서 속력이 1m/s가 되는가?
    
    while(x > 0){   // x가 0이 되면 반복문 빠져나오기
        time_sec++; // 현재 시간 1초 증가
        // 매 초마다 속도를 낮출지, 유지할지 높일지 선택하기
        // 현재 남은 거리에서 속력이 v일 때, 1 + 2 + ... + v까지의 합을 뺀 값이 현재 속력+1보다 크거나 같으면 더 증가해도 됨
        if((x-(cur_speed)*(cur_speed+1)/2)>=cur_speed+1){
            // 속도 높이기
            cur_speed++;
            x -= cur_speed;
        }
        // 
        else if(x >= (cur_speed)*(cur_speed+1)/2){
            // 속도 그대로 유지
            x -= cur_speed;
        }
        else{
            // 속도 낮추기
            cur_speed--;
            x -= cur_speed;
        }

    }
    cout << time_sec;
    return 0;
}

/*
 * 해설 풀이


#include <iostream>

using namespace std;

int main(){
    // 변수 선언 및 입력
    int x;
    cin >> x;

    int t = 0;
    int left_dist = x;
    int v = 1;
    while(true){
        left_dist -= v;
        t++;
        if(left_dist == 0)
            break;

        // 속도를 더 높여도 괜찮은지 결정
        // 속도를 1 더 높이면, (v+1) + v + (v-1) + ... + 2 + 1만큼 이동
        // 즉 남은 거리가 (v+1)*(v+2)/2보다 크거나 같아야 함
        if(left_dist >= (v+1)*(v+2)/2)
            v++;
        // 속도를 유지해도 괜찮은지 결정
        // 속도를 유지하면, v + (v-1) + ... + 2 + 1 만큼 이동
        // 즉 남은 거리가 v*(v+1)/2 보다 크거나 같아야 함
        else if(left_dist >= v*(v+1) / 2)
            // 아무것도 하지 않음
        
        // 위 둘을 만족하지 못하면 반드시 속도를 줄여야 함
        else    v--;
    }
    cout << t;
    return 0;
}
*/