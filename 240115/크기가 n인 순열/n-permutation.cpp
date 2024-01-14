#include <iostream>
#include <vector>
#define MAX_N 8
using namespace std;
int n;
vector<int> selected;
bool visited[MAX_N];

void Print(){
    for(int i=0; i<n; i++){
        cout << selected[i] << ' ';
    }
    cout << '\n';
    
}
void Choose(int num){
    if(num == n){
        Print();
        return;
    }
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        selected.push_back(i);
        Choose(num+1);
        selected.pop_back();
        visited[i] = false;
    }
}
int main() {
    cin >> n;
    Choose(0);  // 0번째 자리에 1~n사이의 수를 선택하는 함수

    return 0;
}