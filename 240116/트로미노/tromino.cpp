#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200
#define MAX_M 200
#define BLOCK_CNT 3
using namespace std;
int n, m;
int grid[MAX_N][MAX_M];
int tmp[BLOCK_CNT];
int ans;    // 블록이 놓인 칸 안에 적힌 숫자의 합의 최대


int getSum(){
    int curr=0;
    for(int i=0; i<3; i++){
        curr += tmp[i];
    }
    return curr;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }    
    // 먼저 첫번째 블럭을 보기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j+2-1 >= m || i+2-1 >= n) continue;      // 범위 넘어가면 무시
            int a[4];
            int idx =0;
            for(int k=i; k<i+2; k++){
                for(int l=j; l<j+2; l++){
                    a[idx]=grid[k][l];
                    idx++;
                }
            }
            idx = 0;
            vector<int> select;
            while(idx < 4){
                for(int k=0; k<4; k++){
                    if(idx == k) continue;
                    select.push_back(a[k]);
                }
                for(int k=0; k<3; k++){
                    tmp[k] = select[k];
                }
                ans = max(ans, getSum());
                idx++;
                select.clear();
            }
        }
    }

    // 그다음 두 번째 블럭을 보기(회전 전)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j+3-1 >= m) continue;    // 범위 넘어가면 무시
            
            for(int k=j; k<j+BLOCK_CNT; k++){
                tmp[k-j] = grid[i][k];
            }
            ans = max(ans, getSum());
        }
    }
    // 두 번째 블록 회전 후
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            if(i+3-1 >= m) continue;    // 범위 넘어가면 무시
            for(int k=i; k<i+BLOCK_CNT; k++){
                tmp[k-i] = grid[k][j];
            }
            ans = max(ans, getSum()); 
        }
    }
    cout << ans;
    return 0;
}