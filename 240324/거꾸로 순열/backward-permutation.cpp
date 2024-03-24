#include <iostream>
#include <vector>
#define MAX_N 8

using namespace std;
int n;

vector<int> selected;
bool visited[MAX_N];

void Print(){
    for(int i=0; i<(int)selected.size(); i++)
        cout << selected[i] << ' ';
    cout << '\n';
}

// idx번째 숫자를 선택하고, 계속 탐색을 이어서 진행하는 함수
void Choose(int idx){
    // 모든 원소를 선택했을 때, 해당 순열을 출력한다.
    if(idx == n){
        Print();
        return;
    }

    // 뒤에서부터 하나씩 원소를 선택한다.
    for(int i=n; i >= 1; i--){
        if(visited[i])
            continue;

        visited[i] = true;
        selected.push_back(i);
        Choose(idx+1);
        selected.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    Choose(0);      // 0번째 숫자를 선택하는 함수
    return 0;
}