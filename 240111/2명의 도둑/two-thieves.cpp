#include <iostream>
#include <vector>
#define MAX_N 10
#define MAX_M 5
using namespace std;
int n, m, c;
int grid[MAX_N][MAX_N];
vector<int> a;
vector<int> b;
int tmp_sumA;
int tmp_sumB;
int ans;

void ChooseB(int num, int cur_sum, int cur_square){     // num번째 숫자를 선택하는지 확인하는 함수, 현재까지 합은 cur_sum, 현재까지 제곱의 합은 cur_square
    if(num == m){
        if(cur_sum <= c){
            tmp_sumB = max(cur_square, tmp_sumB);
            ans = max(ans, tmp_sumA+tmp_sumB);
        }
        return;
    }

    ChooseB(num+1, cur_sum, cur_square);

    ChooseB(num+1, cur_sum+b[num], cur_square+b[num]*b[num]);

}
void ChooseA(int num, int cur_sum, int cur_square){     // num번째 숫자를 선택하는지 확인하는 함수, 현재까지 합은 cur_sum, 현재까지 제곱의 합은 cur_square
    if(num == m){
        if(cur_sum <= c){

            tmp_sumA = max(cur_square, tmp_sumA);
        }
        return;
    }

    ChooseA(num+1, cur_sum, cur_square);

    ChooseA(num+1, cur_sum+a[num], cur_square+a[num]*a[num]);

}

bool IsOverlapping(int sx1, int sy1, int sx2, int sy2){
    return !(sy1+m-1 < sx2 || sy2+m-1 < sx1);
}

bool IsPossible(int sx1, int sy1, int sx2, int sy2){    // 해당 좌표가 가능한지 확인하는 함수
    if(sy1+m-1 >= n || sy2+m-1 >= n){
        // 만약 범위를 벗어나면
        return false;
    }

    if(IsOverlapping(sx1, sy1, sx2, sy2)){
        // 만약 범위가 겹치면
        return false;
    }
    return true;
}
void insertNumber(int x1, int y1, int x2, int y2){

    for(int i=0; i<m; i++){
        a.push_back(grid[x1][y1+i]);
    }

    for(int i=0; i<m; i++){
        b.push_back(grid[x2][y2+i]);
    }
}
void deleteNumber(int x1, int y1, int x2, int y2){
    for(int i=0; i<m; i++){
        a.pop_back();
        b.pop_back();
    }
}
int main(){
    cin >> n >> m >> c;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    for(int sx1=0; sx1<n; sx1++){
        for(int sy1=0; sy1<n; sy1++){
            for(int sx2=0; sx2<n; sx2++){
                for(int sy2=0; sy2<n; sy2++){
                    //(sx1, sy1) ~ (sx1, sy1+m-1)
                    //(sy2, sy2) ~ (sy2, sy2+m-1)
                    if(IsPossible(sx1, sy1, sx2, sy2)){
                        // 이제 backtracking으로 해당 범위 내 숫자들을 고르면서 탐색해보기
                        insertNumber(sx1, sy1, sx2, sy2);
                        tmp_sumA=0, tmp_sumB=0;
                        ChooseA(-1,0,0); // 0번째 숫자를 선택
                        ChooseB(-1,0,0);
                        deleteNumber(sx1, sy1, sx2, sy2);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}