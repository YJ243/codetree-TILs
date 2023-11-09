#include <iostream>
#define DIR_NUM 4

using namespace std;

int n, x, y;
// 동,서,남,북 순으로 dx, dy 정의
int dirs[DIR_NUM][2] = {{1,0},{-1,0},{0,-1},{0,1}};

int main(){
    // 입력
    cin >> n;

    // 움직이는 것을 진행
    while(n--){
        char c_dir; int dist;
        cin >> c_dir >> dist;

        // 각 방향에 맞는 번호를 붙이기
        int dir;
        if(c_dir=='E')
            dir = 0;
        else if(c_dir=='W')
            dir = 1;
        else if(c_dir == 'S')
            dir = 2;
        else
            dir = 3;

        // 주어진 방향대로 dist 거리만큼 이동했을 경우의 위치를 구하기
        x += dirs[dir][0] * dist;
        y += dirs[dir][1] * dist;
    }
    cout<<x<<' ' <<y;
    return 0;
}