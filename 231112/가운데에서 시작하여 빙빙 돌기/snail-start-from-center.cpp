#include <iostream>
#define MAX_N 100

using namespace std;

int n, x, y; // 격자 크기, (x,y): 초기 좌표
int c_cnt=1; // c_cnt: 오/왼 방향으로 채울 개수, r_cnt: 위/아래 방향으로 채울 개수
int r_cnt=1;
int dirs[4][2] = {{0,1},{-1,0},{0,-1},{1,0}}; // 오,위,왼,아래 방향
int cur_d;
int arr[MAX_N][MAX_N];
int val = 1; // 격자를 채울 값

void write_num(int cnt){
    for(int i=0; i<cnt; i++){
        x = x+dirs[cur_d][0], y = y+dirs[cur_d][1];
        if(val+1 > n*n) return;
        arr[x][y] = ++val;
    }
}
int main() {
    cin >> n;
    x = n/2, y = n/2;
    arr[x][y] = val;

    while(true){
        if(val == n*n) break;
        if(cur_d % 2 == 0){     // 만약 오/왼 방향이라면
            write_num(c_cnt);
            c_cnt++;
        }
        else{                   // 만약 위/아래 방향이라면
            write_num(r_cnt);
            r_cnt++;
        }
        cur_d = (cur_d+1) % 4;

    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}