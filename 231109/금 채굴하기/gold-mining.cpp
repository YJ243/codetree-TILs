#include <iostream>
#include <cstdlib>

#define INT_N 20
using namespace std;
int n, m;
int maze[INT_N][INT_N];

// (start_x, start_y)를 중심으로 하고 length만큼 가서 나오는 마름모에서 그 안에 있는 금의 개수를 반환
int GetGold(int start_x, int start_y, int length){
    if(length==0 && maze[start_x][start_y]) return 1;
    int num_gold = 0;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            int distance = abs(x-start_x)+abs(y-start_y);
            if(distance<=length && maze[x][y] == 1){// 거리 안에 있고 금이 있다면}
                num_gold++;
            }
        }
    }
    return num_gold;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0; j<n; j++)
            cin>>maze[i][j];
    int max_gold = 0;
    // Step1. 각 격자별로 탐색하는데
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // Step2. k를 0부터 늘려나가면서 2n-2보다 작거나 같을 때까지 확인
            int cur_gold = 0;
            for(int k=0; k<=2*n-2; k++){
                //cout<<k<<'\n';
                // Step3. 각 격자 칸에서 거리가 k인 부분 안에 있는 금 채굴
                cur_gold = GetGold(i,j,k);
                //cout<<cur_gold<<'\n';
                // Step4. 손해를 보지 않는 경우에만 결과 업데이트
                if(cur_gold*m >= (k*k+(k+1)*(k+1)) && max_gold < cur_gold)
                    max_gold = cur_gold;
            }
        }
    }
    cout << max_gold;
    return 0;
}