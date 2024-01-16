#include <iostream>
#define MAX_N 100

using namespace std;
int n, m;   // n: 격자 크기, m: 연속하여 나와야하는 숫자 개수
int grid[MAX_N][MAX_N];
int tmp[MAX_N];
int ans;        // 행복한 수열의 개수


bool isHappyRow(int idx){
    int curNum = grid[idx][0], curIdx = 0, sameCnt = 1;
    bool isHappy = false;
    while(curIdx < n){
        for(int i=curIdx+1; i<curIdx+m; i++){
            if(grid[idx][i] == curNum){
                sameCnt++;
            }
        }
        if(sameCnt >= m){
            return true;
        }

        sameCnt = 1;
        curIdx++;
        curNum = grid[idx][curIdx];
    }
    return false;
}

bool isHappyCol(int idx){
    int curNum = grid[0][idx], curIdx = 0, sameCnt = 1;
    bool isHappy = false;
    while(curIdx < n){
        for(int i=curIdx+1; i<curIdx+m; i++){
            if(grid[i][idx] == curNum){
                sameCnt++;
            }
        }
            if(sameCnt >= m){
                return true;
            }
            sameCnt = 1;
            curIdx++;
            curNum = grid[curIdx][idx];
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    int happyRow = 0, happyCol;
    for(int i=0; i<n; i++){
        // 먼저 행복한 수열이 있는지 행부터 검색
        happyRow += isHappyRow(i);
        happyCol += isHappyCol(i);
        
    }
    ans = happyRow+happyCol;

    cout << ans;
    return 0;
}

/*
 * 해설 풀이

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n, m;
int grid[MAX_N][MAX_N];

int seq[MAX_N];

bool IsHappySequence(){
    // 주어진 seq가 행복한 수열인지 판단하는 하뭇
    int consecutive_count = 1, max_ccnt = 1;

    for(int i=1; i<n; i++){
        if(seq[i-1] == seq[i])
            consecutive_count++;
        else
            consecutive_count = 1;
        max_ccnt = max(max_ccnt, consecutive_count);
    }

    // 최대로 연속한 횟수가 m이상이면 true를 반환
    return max_ccnt >= m;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    int num_happy = 0;

    // 먼저 가로로 행복한 수열의 수를 세기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            seq[j] = grid[i][j];
        }
        if(IsHappySequence())
            num_happy++;
    }

    // 세로로 행복한 수열의 수를 세기
    for(int j=0; j<n; j++){
        // 세로로 숫자들을 모아 새로운 수열을 만들기
        for(int i=0; i<n; i++)
            seq[i] = grid[i][j];
        if(IsHappySequence())
            num_happy++;
    }

    cout << num_happy;

    return 0;
}
*/