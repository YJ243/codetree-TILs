#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define MAX_N 12
#define DIR_NUM 4
#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;

int n, k;
int board[MAX_N][MAX_N];
vector<pair<int, int> > pieces_grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

tuple<int, int, int> FindPiece(int target_num) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < (int) pieces_grid[i][j].size(); k++) {
                int piece_num, move_dir;
                tie(piece_num, move_dir) = pieces_grid[i][j][k];
                if(piece_num == target_num)
                    return make_tuple(i, j, move_dir);
            }
}

// (x, y) 위치에 num말 포함 위에 있는 모든 말들을 빼옵니다.
vector<pair<int, int> > PopPieces(int x, int y, int num) {
    vector<pair<int, int> > pieces;
    for(int i = 0; i < (int) pieces_grid[x][y].size(); i++) {
        int piece_num, move_dir;
        tie(piece_num, move_dir) = pieces_grid[x][y][i];
        if(piece_num == num) {
            pieces.assign(pieces_grid[x][y].begin() + i, 
                          pieces_grid[x][y].end());
            pieces_grid[x][y].erase(pieces_grid[x][y].begin() + i, 
                                    pieces_grid[x][y].end());
            break;
        }
    }
    return pieces;
}

// 말들을 (x, y) 위치로 이동합니다.
void Move(int x, int y, vector<pair<int, int> > pieces, bool need_reverse) {
    if(need_reverse) 
        reverse(pieces.begin(), pieces.end());
    
    pieces_grid[x][y].insert(pieces_grid[x][y].end(), 
                             pieces.begin(), pieces.end());
}

// 1턴 진행합니다.
bool Simulate() {
    // 문제에서 주어진 순서인
    // 오른쪽, 왼쪽, 위, 아래 순으로 적어줍니다.
    int dx[DIR_NUM] = {0, 0, -1, 1};
    int dy[DIR_NUM] = {1, -1, 0, 0};
    
    // 번호 순서대로 한 번씩 움직입니다.
    for(int num = 0; num < k; num++) {
        int piece_x, piece_y, move_dir;
        tie(piece_x, piece_y, move_dir) = FindPiece(num);
        
        int next_x = piece_x + dx[move_dir];
        int next_y = piece_y + dy[move_dir];
        
        bool need_reverse = false;
        
        // 그 다음 위치가 격자를 벗어나거나 파란색 지점인 경우
        // 현재 위치에서 방향을 전환한 뒤 이동합니다.
        if(!InRange(next_x, next_y) || board[next_x][next_y] == BLUE) {
            move_dir = (move_dir % 2 == 0) ? (move_dir + 1) : (move_dir - 1);
            next_x = piece_x + dx[move_dir];
            next_y = piece_y + dy[move_dir];
            // 방향 전환 후 그 다음 위치로 이동이 불가하거나 파란색 지점인 경우, 그대로 멈춰있습니다.
            if(board[next_x][next_y] == BLUE)
                next_x = piece_x, next_y = piece_y;
            // 만약 이동이 가능하다면, 빨간색 지점일 경우 
            // 뒤집어서 이동해야 합니다.
            else if(board[next_x][next_y] == RED)
                need_reverse = true;
        }
        // 만약 가려는 곳이 빨간색 지점인 경우라면
        // 순서를 뒤집어서 이동해야합니다.
        else if(board[next_x][next_y] == RED)
            need_reverse = true;
        
        // 현재 piece 포함 위에 있는 모든 말들을 빼옵니다.
        vector<pair<int, int> > pieces = PopPieces(piece_x, piece_y, num);
        
        // num번 말의 그 다음 방향을 반영해줍니다.
        pieces[0] = make_pair(num, move_dir);
        
        // 말들을 그 다음 위치로 전부 옮겨줍니다.
        Move(next_x, next_y, pieces, need_reverse);
        
        // 만약 말이 4개 이상 겹치게 된다면, 시뮬레이션을 종료합니다.
        if((int) pieces_grid[next_x][next_y].size() >= 4)
            return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
 
    for(int num = 0; num < k; num++) {
        int x, y, d;
        cin >> x >> y >> d;
        pieces_grid[x - 1][y - 1].push_back(make_pair(num, d - 1));
    }
    
    int ans = -1;
    
    // 최대 1000번 턴을 진행해봅니다.
    for(int t = 1; t <= 1000; t++) {
        bool is_done = Simulate();
        // 4개 이상이 겹쳐진 경우가 생긴다면
        // 턴을 종료합니다.
        if(is_done) {
            ans = t;
            break;
        }
    }

    cout << ans;
    return 0;
}