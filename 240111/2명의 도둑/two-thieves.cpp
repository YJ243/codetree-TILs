#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10
using namespace std;
int n, m, c;
int grid[MAX_N][MAX_N];
vector<pair<int, int> > firstA;
vector<pair<int, int> > firstB;
int ans;
void getValue(){
    vector<int> a;
    vector<int> b;
    for(int i=0; i<m; i++){
        a.push_back(grid[firstA[0].first][firstA[0].second+i]);
        b.push_back(grid[firstB[0].first][firstB[0].second+i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int result_a=0, result_b=0;
    int sum_a=0, sum_b=0;
    
    for(int i=m-1; i>=0; i--){
        int cur = a[i];
        if(cur+sum_a <=c){
            sum_a += cur;
            result_a += cur*cur;
        }
    }
    for(int i=m-1; i>=0; i--){
        int cur = b[i];
        if(cur+sum_b <=c){
            sum_b += cur;
            result_b += cur*cur;
        }

    }
    
    ans = max(ans, result_a+result_b);
}

bool IsOverlapping(){
    int aX=firstA[0].first, aY = firstA[0].second;
    int bX=firstB[0].first, bY = firstB[0].second;
    if(aX != bX)    // 만약 줄이 다르면
        return false;   // 겹치지 않는다.
    else{
        if(aY+m-1 < bY || bY+m-1 < aY)
            return false;
    }
    return true;
}

void chooseB(int num){
    if(num==1){
        if(!IsOverlapping()){
            getValue();
        }
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-m; j++){
            firstB.push_back(make_pair(i,j));
            chooseB(num+1);
            firstB.pop_back();
        }
    }
}

void chooseA(int num){  // num개의 칸을 선택했고 그 다음 A의 칸을 선택하는 함수 
    if(num==1){
        chooseB(0);
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-m; j++){
            firstA.push_back(make_pair(i,j));
            chooseA(num+1);
            firstA.pop_back();
        }
    }
}

int main(){
    // 입력:
    cin >> n >> m >> c;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    chooseA(0);

    cout << ans;
    return 0;
}