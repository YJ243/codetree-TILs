#include <iostream>
#include <algorithm>
#define MAX_N 19
using namespace std;
int a[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x <=19 && 0 <= y && y <= 19;
}

int main() {
    for(int i=0; i<MAX_N; i++)
        for(int j=0; j<MAX_N; j++)
            cin >> a[i][j];
    // 1. 가로 확인
    for(int i=0; i<MAX_N; i++){
        for(int j=0; j<=MAX_N-5; j++){
            if(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4] == 10){
                cout << 2 << '\n';
                cout << i+1 << ' ' << j+3 << '\n';
                return 0;
            }
            if(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4] == 5){
                cout << 1 << '\n';
                cout << i+1 << ' ' << j+3 << '\n';
                return 0;
            }
        }
    }

    
    // 2. 세로 확인
    for(int j=0; j<MAX_N; j++){
        for(int i=0; i<=MAX_N-5; i++){
            if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j] == 10){
                cout << 2 << '\n';
                cout << i+1 << ' ' << j+3 << '\n';
                return 0;
            }
            if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j] == 5){
                cout << 1 << '\n';
                cout << i+1 << ' ' << j+3 << '\n';
                return 0;
            }
        }
    }

    // 3. 대각선 확인
    for(int i=0; i<MAX_N; i++){
        for(int j=0; j<MAX_N; j++){
            if(!InRange(i+4, j+4)) continue;
            if(a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4] ==10)
            {
                cout << 2 << '\n';
                cout << i+1 << ' ' << j+3 << '\n';
                return 0;
            }

            if(a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4] ==5)
            {
                cout << 1 << '\n';
                cout << i+1 << ' ' << j+3 << '\n';
                return 0;
            }
            
        }
    }
    cout << 0 << '\n';
    return 0;
}