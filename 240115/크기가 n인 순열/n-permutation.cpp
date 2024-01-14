#include <iostream>
#include <vector>
#define MAX_N 8
using namespace std;

// 변수 선언
int n;
vector<int> selected;
bool visited[MAX_N];

void Print(){
    for(int i=0; i<n; i++){
        cout << selected[i] << ' ';
    }
    cout << '\n';
    
}

// num번째 출력할 원소를 고르는 함수, 계속 탐색을 이어서 진행 
void Choose(int num){
    // 모든 원소를 선택했을 때, 해당 순열을 출력 
    if(num == n){
        Print();
        return;
    }
    // 앞에서부터 하나씩 원소를 선택
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