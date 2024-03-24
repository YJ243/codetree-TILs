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

void Choose(int idx){
    if(idx == n){
        Print();
        return;
    }

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