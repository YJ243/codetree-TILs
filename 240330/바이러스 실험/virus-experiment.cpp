#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10
#define DIR_NUM 8

using namespace std;

int n, m, k;

vector<int> virus[MAX_N][MAX_N];
vector<int> next_virus[MAX_N][MAX_N];

int food[MAX_N][MAX_N];
int next_food[MAX_N][MAX_N];

int delta[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// (x, y)를 기준으로 8방향으로 번식을 진행합니다.
void Breed(int x, int y) {
    int dx[DIR_NUM] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[DIR_NUM] = {-1,  0,  1, -1, 1, -1, 0, 1};
    for(int i = 0; i < DIR_NUM; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        // 격자 안이라면 나이가 1인 바이러스를 추가합니다.
        if(InRange(nx, ny))
            next_virus[nx][ny].push_back(1);
    }
}

void Simulate() {
    // 그 다음 바이러스, 양분 값을 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            next_virus[i][j].clear();
            next_food[i][j] = 0;
        }
        
    // Step1. 바이러스가 양분을 섭취합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            // Step1-1. 바이러스를 나이순으로 정렬합니다.
            sort(virus[i][j].begin(), virus[i][j].end());
            
            // Step1-2. 어린 바이러스부터 순서대로 양분을 섭취합니다.
            for(int k = 0; k < (int) virus[i][j].size(); k++) {
                int age = virus[i][j][k];
                // Case1.
                // 양분이 충분하다면
                // 바이러스는 나이가 1 증가합니다.
                if(food[i][j] >= age) {
                    food[i][j] -= age;
                    next_virus[i][j].push_back(age + 1);
                }
                
                // Case2.
                // 양분이 불충분하다면
                // 바이러스는 죽고
                // 그 다음 양분으로 쓰입니다.
                else
                    next_food[i][j] += age / 2;
            }
            
            // Step1-3. 남은 양분 만큼을 그 다음 양분으로 넣어줍니다.
            next_food[i][j] += food[i][j];
        }
    
    // Step2. 바이러스가 번식을 진행합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < (int) next_virus[i][j].size(); k++) {
                int age = next_virus[i][j][k];
                if(age % 5 == 0)
                    Breed(i, j);
            }
    
    // Step3. 각 칸에 입력으로 주어진 만큼 양분이 추가됩니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            next_food[i][j] += delta[i][j];
    
    // 바이러스, 양분 값을 갱신해줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            virus[i][j] = next_virus[i][j];
            food[i][j] = next_food[i][j];
        }
}

int main() {
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> delta[i][j];
    
    for(int i = 0; i < m; i++) {
        int r, c, age;
        cin >> r >> c >> age;
        virus[r - 1][c - 1].push_back(age);
    }
    
    // 초기 양분 값을 적어줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            food[i][j] = 5;
    
    // 총 k번 시뮬레이션을 진행합니다.
    while(k--)
        Simulate();
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans += (int) virus[i][j].size();
    
    cout << ans;
    return 0;
}