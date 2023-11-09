#include <iostream>
using namespace std;
int N;
int x, y;
int move_time;
int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; // 우,하,좌,상
int main() {
    cin >> N;
    int final_time=0;
    for(int i=0; i<N; i++){
        char d;
        int l,cur_d;
        cin>>d >> l;
    
        if(d=='N')  cur_d=3;
        else if(d=='E') cur_d=0;
        else if(d=='W') cur_d=2;
        else cur_d=1;

        while(l--){
            move_time++;
            x += dirs[cur_d][0];
            y += dirs[cur_d][1];
            if(x==0 && y == 0) {
                final_time=move_time;
            }
        }
        if(final_time > 0) break;
    }
    cout<<final_time;
    return 0;
}