#include <iostream>
#define MAX_N 100

using namespace std;
int n, m, k;                // n: 격자 크기, m: 블록 크기, k: 블록이 떨어질 위
int grid[MAX_N][MAX_N];     // 0은 빈 칸, 1은 블럭이 채워져 있음

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    k--;
    int blockRow = -1;
    for(int i=1; i<n; i++){
        // i행부터 차례대로 보기
        bool IsPossible = true;
        for(int j=k; j<=k+m-1; j++){
            if(grid[i][j]){
                // 만약 블럭이 채워져 있는 것이 있다면
                IsPossible = false;
            }
        }
        if(!IsPossible) 
        {   blockRow = i-1;
            break;
        }
    }
    if(blockRow == -1)
        blockRow = n-1;
    for(int j=k; j<=k+m-1; j++)
        grid[blockRow][j] = 1;
    
    // 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}