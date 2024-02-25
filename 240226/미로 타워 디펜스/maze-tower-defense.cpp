#include <iostream>
#include <vector>
#define MAX_N 25

using namespace std;

int n, m;                   // n: 격자 크기, m: 라운드 수
int d, p;                   // 공격하는 방향과 칸 수 
int grid[MAX_N][MAX_N];     // 몬스터가 있는 격자
vector<int> block;          // 격자를 펼치면 나오는 일자 배열
int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int total_score = 0;

void Input(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
}

void AttackMonster(){
    block.clear();
    // 1. 먼저 공격하면서 해당 자리 0으로 만들기
    int r = n/2, c = n/2;
    
    for(int i=1; i<=p; i++){
        int nr = r + dirs[d][0]*i, nc = c + dirs[d][1]*i;
        if(grid[nr][nc] != 0){
            block.push_back(grid[nr][nc]);
            grid[nr][nc] = 0;   // 공격당한 몬스터 0으로 만들기
        }
    }
    if((int)block.size() == 0) return;       // 공격당한 몬스터가 없으면 리턴

    // 2. 점수 업데이트 해주기
    int cur_num = block[0], cur_cnt = 1;
    for(int i=1; i<(int)block.size(); i++){
        if(cur_num != block[i]){     // 새로운 숫자가 나왔다면
            total_score += cur_num * cur_cnt;   // 점수 업데이트
            cur_num = block[i];                  // 현재 숫자를 바꾸기
            cur_cnt = 1;                        // 카운트를 다시 1으로
        }
        else{                       // 같은 숫자라면
            cur_cnt++;              // 개수만 증가
        }
    }
    // 마지막에 한 번 더 점수 업데이트 해주기
    total_score += cur_num * cur_cnt;

}

bool InRange(int x, int y){
    return 0 <= x && y < n && 0 <= y && y < n;
}

void CopyGridtoBlock(){
    int r = n/2, c = n/2;
    int cur_dir = 2, cur_len = 1;
    int blk_idx = 0;
    while(true){
        if(!InRange(r, c)) break;
        // 1. cur_dir방향으로 cur_len만큼 움직이기
        for(int i=1; i<=cur_len; i++){
            r += dirs[cur_dir][0];
            c += dirs[cur_dir][1];
            if(!InRange(r, c))
                break;
            if(grid[r][c] == 0) continue;
            block.push_back(grid[r][c]);
        }
        cur_dir = (cur_dir - 1+4) % 4;

        // 2. 만약 cur_dir이 2로 나누었을 때 나머지가 0이면 개수 바꾸기
        if(cur_dir % 2 == 0)
            cur_len++;
    }

}

void MoveBlocktoGrid(){
    // 1. 먼저 grid 배열 0으로 초기화하기
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = 0;
    
    // 2. block을 grid에 넣기
    int r = n/2, c = n/2;
    int cur_dir = 2, cur_len = 1;
    int blk_idx = 0;
    while(true){
        if(!InRange(r, c) || blk_idx >= block.size()) break;
        // 1. cur_dir방향으로 cur_len만큼 움직이기
        for(int i=1; i<=cur_len; i++){
            r += dirs[cur_dir][0];
            c += dirs[cur_dir][1];
            if(!InRange(r, c))
                break;
            grid[r][c] = block[blk_idx++];
            if(blk_idx >= block.size())
                break;
        }
        cur_dir = (cur_dir - 1+4) % 4;

        // 2. 만약 cur_dir이 2로 나누었을 때 나머지가 0이면 개수 바꾸기
        if(cur_dir % 2 == 0)
            cur_len++;
    }

}

void DeleteEmpty(){
    // 1. 먼저 block 초기화 하기
    block.clear();

    // 2. 격자를 나선형으로 탐색하면서 펼친 일자 배열에다가 옮겨놓기 
    CopyGridtoBlock();

    // 3. block에서 중간에 0이 있는 부분이 사라지도록 땡기기 
    MoveBlocktoGrid();
}



bool DeleteMonsters(){
    /*
    for(int i=0; i<(int)block.size(); i++)
        cout << block[i] << ' ';
    cout << '\n';
    */
    bool isAppear = false;

    int cur_num = block[0], cur_cnt = 1;
    for(int i=1; i<(int)block.size(); i++){
        if(cur_num != block[i]){     // 새로운 숫자가 나왔다면
            if(cur_cnt >= 4){        // 그런데 이제까지 개수가 4개보다 적다면
                // 새로운 숫자가 나왔는데 이제까지 개수가 4개 이상이라면
                total_score += cur_num * cur_cnt;   // 점수 업데이트
                isAppear = true;
                // 현재까지 개수만큼의 숫자를 0으로 만들기
                for(int j=i-1; j > i-1-cur_cnt; j--){
                    block[j] = 0;
                }
            }
            cur_num = block[i];                  // 현재 숫자를 바꾸기
            cur_cnt = 1;                        // 카운트를 다시 1으로
        }
        else{                       // 같은 숫자라면
            cur_cnt++;              // 개수만 증가
        }
    }
    // 마지막에 한 번 더 확인하기
    if(cur_cnt >= 4){
        total_score += cur_num * cur_cnt;   // 점수 업데이트
        isAppear = true;
        for(int j=block.size()-1; j > block.size()-1-cur_cnt; j--){
            block[j] = 0;
        }
    }
    
    vector<int> temp;
    for(int i=0; i<(int)block.size(); i++){
        if(block[i] != 0)
            temp.push_back(block[i]);
    }
    // 그다음 block에다가 옮기기
    block = temp;
    return isAppear;


}

void MakeMate(){
    block.clear();
    CopyGridtoBlock();      // 먼저 grid를 블록으로

    // 차례대로 보면서 짝을 만들어주기
    int cur_num = block[0], cur_cnt = 1;
    vector<int> temp;
    for(int i=1; i<(int)block.size(); i++){
        if(cur_num != block[i]){     // 새로운 숫자가 나왔다면
            temp.push_back(cur_cnt);
            temp.push_back(cur_num);

            cur_num = block[i];                  // 현재 숫자를 바꾸기
            cur_cnt = 1;                        // 카운트를 다시 1으로
        }
        else{                       // 같은 숫자라면
            cur_cnt++;              // 개수만 증가
        }
    }

    // 마지막 한 번 더 넣기
    temp.push_back(cur_cnt);
    temp.push_back(cur_num);
    block = temp;           // 블록에다가 복사


}

void Simulate(){
    // Step 1. 주어진 공격 칸 수만큼 몬스터 공격하여 없애기
    AttackMonster();

    // Step 2. 앞으로 이동하여 빈 공간 채우기
    DeleteEmpty();
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    // Step 3. 몬스터 종류가 4번 이상 나오면 해당 몬스터 삭제하기
    while(true){
        // 4번 이상 나오는 몬스터가 없을 때까지
        block.clear();      // 블록 초기화
        CopyGridtoBlock();  // grid를 블록으로
        bool isAppear = DeleteMonsters();   // 4개 이상 반복해서 나오는 몬스터 없애기
        if(!isAppear) break;
        
        // Step 4. 삭제한 이후 몬스터 앞으로 당기기
        MoveBlocktoGrid();
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    // Step 5. 삭제가 끝난 후 몬스터 차례대로 나열했을 때 같은 숫자끼리 짝을 지어주고,
    // 다시 미로 속에 넣기
    MakeMate();  // 짝지어주기

    MoveBlocktoGrid();  // 다시 grid에 넣기

}

int main() {
    // 입력 받기
    Input();

    // 총 m개의 라운드에 대해 시뮬레이션 진행
    while(m--){
        cin >> d >> p;
        Simulate();     // d방향으로 p칸 공격하기
    }

    // 출력하기
    cout << total_score << '\n';
    return 0;
}