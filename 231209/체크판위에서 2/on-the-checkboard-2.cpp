#include <iostream>
#define MAX_D 15

using namespace std;
int r, c;
char arr[MAX_D][MAX_D];
int ans;

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    char cur = arr[0][0];
    if(cur == arr[r-1][c-1]){
        cout << 0 ;
        return 0;
    }
    for(int i=1; i<r-1; i++){
        for(int j=1; j<c-1; j++){
            if(cur != arr[i][j]){
                // 처음으로 바뀌는 위치라면
                for(int x=i+1; x<r-1; x++){
                    for(int y=j+1; y<c-1; y++){
                        if(cur == arr[x][y]){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}