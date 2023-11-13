#include <iostream>
#define MAX_N 15

using namespace std;
int R, C;
char arr[MAX_N][MAX_N];
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin >>arr[i][j];

    char cur_c = arr[0][0];
    if(cur_c == arr[R-1][C-1]){
        cout<<0 << '\n';
        return 0;
    }
    int success_cnt = 0;
    for(int i=1; i<R; i++){
        for(int j=1; j<C; j++){
            cur_c = arr[0][0];
            if(arr[i][j] != cur_c && i == R-1 && j == C-1 && success_cnt == 0){
                // 현재 색과 다른데, 맨 마지막에만 있다면
                cout << 0 << '\n';
                return 0;
            }
        
            else if(arr[i][j] != cur_c){
                // 이제 여기서 탐색해야 함
                // (i,j)는 처음 점프한 지점
  
                cur_c = arr[i][j];
                for(int k=i+1; k<R; k++){
                    for(int l=j+1; l<C; l++){
                        if(cur_c != arr[k][l]){
                            //이제 여기서 한 번 점프 했을 때 마지막까지 도달 가능하다면?
                            //(k,l)은 두번째 점프한 지점
                            for(int x=k+1; x<R; x++){
                                for(int y=l+1; y<C; y++){
                                    if(x == R-1 && y == C-1 && cur_c == arr[R-1][C-1]){
                                        success_cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        
        }
    }
    cout<<success_cnt;
    return 0;
}