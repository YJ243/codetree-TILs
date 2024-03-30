#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 10

using namespace std;

int n, m, k;        // n: 배지 크기, m: 바이러스 개수, k: 총 사이클 수
vector<int> virus[MAX_N][MAX_N];        // virus[i][j]: (i, j) 칸에 있는 바이러스의 나이
int nutrient[MAX_N][MAX_N];             // 현재 영양분
int plus_nutrient[MAX_N][MAX_N];        // 추가되는 영양분
void Input(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> plus_nutrient[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int r, c, a;
        cin >> r >> c >> a;
        virus[r-1][c-1].push_back(a);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            nutrient[i][j] = 5;
        }
    }

}

void DoIntake(int x, int y){        // (x, y)에 있는 영양분 섭취하기
    for(int i=0; i<(int)virus[x][y].size(); i++){
        int age = virus[x][y][i];
        //cout << age << ' ' << nutrient[x][y] << '\n';
        if(age <= nutrient[x][y]){
            virus[x][y][i]++;
            nutrient[x][y] -= age;
        }
        else{
            nutrient[x][y] += (age)/2;
            virus[x][y][i] = 0;
        }
        //cout << virus[x][y][i] << ' ';
    }
    vector<int> tmp;
    for(int i=0; i<(int)virus[x][y].size(); i++){
        if(virus[x][y][i] != 0){
            //cout << virus[x][y][i] << ' ';
            tmp.push_back(virus[x][y][i]);
        }
    }
    virus[x][y] = tmp;
}

bool ExistVirus(int x, int y){
    return (int)virus[x][y].size() >= 1 && virus[x][y][0] != 0;
}

void IntakeNutrient(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ExistVirus(i, j)){
                sort(virus[i][j].begin(), virus[i][j].end());
                DoIntake(i, j);
                //cout << virus[i][j][0] << ' ';
            }
        }
    }

}

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void ReproduceVirus(){
    // 1. temp에 현재 바이러스 복사해놓기
    vector<int> temp[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = virus[i][j];
        }
    }

    // 2. 모든 칸을 보면서 5의 배수의 나이를 가진 바이러스가 있는지 확인하고 바이러스 번식하기
    int dirs[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ExistVirus(i, j)){
                for(int k=0; k < (int)virus[i][j].size(); k++){
                    if(virus[i][j][k] % 5 == 0){
                        for(int d=0; d<8; d++){
                            int nx = i + dirs[d][0], ny = j + dirs[d][1];
                            if(InRange(nx, ny)){
                                temp[nx][ny].push_back(1);
                            }
                        }
                    }
                }
            }
        }
    }

    // 3. 원래대로 돌려놓기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            virus[i][j] = temp[i][j];
        }
    }
}

void PlusNutrient(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            nutrient[i][j] += plus_nutrient[i][j];
        }
    }
}

void Simulate(){
    // Step 1. 양분 섭취하고 죽은 바이러스 양분으로 변하기
    IntakeNutrient();

    // Step 2. 바이러스가 번식 진행
    ReproduceVirus();
    // Step 3. 칸에 양분 추가
    PlusNutrient();
}

void Output(){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 해당 칸에 바이러스가 1개 이상이면서 그게 0이 아닌 경우
            if(ExistVirus(i, j))
                ans += virus[i][j].size();
        }
    }
    cout << ans;
}

int main() {
    // 입력 받기:
    Input();

    // k번의 사이클 수에 대해 시뮬레이션 진행
    while(k--){
        Simulate();
    }

    // 출력하기:
    Output();
    return 0;
}