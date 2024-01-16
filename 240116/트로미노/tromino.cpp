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
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(i+3-1 >= n) continue;    // 범위 넘어가면 무시
            for(int k=i; k<i+BLOCK_CNT; k++){
                tmp[k-i] = grid[k][j];
            }
            ans = max(ans, getSum()); 
        }
    }
    cout << ans;
    return 0;
}

/*
 * 해설 풀이
 * 배열을 활용하여 가능한 모든 모양을 적어준 뒤, 이를 활용해 격자를 순회하며 최대 합을 구하
 * 가능한 6개의 모든 배열을 표현할 수 있는 공통된 크기의 이차원 배열을 사용해야 깔끔함
 * 3x3 크기의 배열을 활용해 각 모양을 정의해주기
 * 이 때 각 모양이 3x3 격자를 벗어나지 않으면서 최대한 왼쪽 상단으로 밀착되게 만들어야 함
 9 9 5
 9 9 5
 5 5 5 를 생각하면 됨

#include <iostream>
#include <algorithm>

#define MAX_NUM 200

using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];

// 가능한 모든 모양을 전부 적어줍니다.
int shapes[6][3][3] = {
    {{1, 1, 0},
    {1, 0, 0},
    {0, 0, 0}},

    {{1, 1, 0},
    {0, 1, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}},
};

// 주어진 위치에 대하여 가능한 모든 모양을 탐색하며 최대 합을 반환하기
int GetMaxSum(int x, int y){
    int max_sum = 0;
    for(int i=0; i<6; i++){
        bool is_possible = true;
        int sum = 0;
        for(int dx = 0; dx < 3; dx++)
            for(int dy = 0; dy < 3; dy++){
                if(shapes[i][dx][dy] == 0) continue;
                if(x+dx >= n || y+dy >= m) is_possible = false;
                else sum += grid[x+dx][y+dy];
            }
        if(is_possible)
            max_sum = max(max_sum, sum);
    }
    return max_sum;
}
int main() {
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	
	int ans = 0;
	
    // 격자의 각 위치에 대하여 탐색하여줍니다.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans = max(ans, GetMaxSum(i, j));
	
	cout << ans;
	
	return 0;
}
*/