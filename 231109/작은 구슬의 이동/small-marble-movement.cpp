#include <iostream>
#include <string>

#define ASCII_NUM 128
#define DIR_NUM 4

using namespace std;

int n, t;
int x, y, dir;
int mapper[ASCII_NUM];

int dirs[DIR_NUM][4]={{0,1},{1,0},{-1,0},{0,-1}};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Simulate(){
    while(t--){
        int nx = x+dirs[dir][0], ny = y+dirs[dir][1];

        // 범위 안에 들어온다면 그대로 진행
        if(InRange(nx,ny))
            x = nx, y = ny;
        // 벽에 부딪힌다면, 방향을 바꿈
        else
            dir = 3-dir;
    }
}

int main(){
    cin >> n >> t;
    // 각 알파벳 별 방향 번호를 설정
    // 이런 식으로 if문 안쓰고 구할 수 있음
    mapper['R'] = 0;
    mapper['D'] = 1;
    mapper['U'] = 2;
    mapper['L'] = 3;

    char c_dir;
    cin >> x >> y >> c_dir;
    x--; y--; dir = mapper[c_dir];

    Simulate();

    cout<<x+1<<' ' <<y+1;
    return 0;

}