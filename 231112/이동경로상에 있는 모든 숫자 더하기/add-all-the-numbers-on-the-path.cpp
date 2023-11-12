#include <iostream>
#include <string>

#define MAX_N 99
using namespace std;

int N, T;
int x, y;
int arr[MAX_N][MAX_N];
int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // 우/하/좌/상 순서
int cur_d;
string s_cmd;

bool InRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    cin >> N >> T;
    cin >> s_cmd;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }

    int sum_result = 0;
    x = N/2, y = N/2;
    cur_d = 3;
    sum_result += arr[x][y];
    for(auto s : s_cmd){
        if(s == 'L'){
            cur_d = (cur_d+3) % 4;
        }
        else if(s=='R'){
            cur_d = (cur_d+1) % 4;
        }
        else{
            int nx = x+dirs[cur_d][0], ny = y+dirs[cur_d][1];
            if(InRange(nx,ny)){
                x = nx, y = ny;
                sum_result += arr[x][y];
            }
        }
    }
    cout << sum_result;
    return 0;
}