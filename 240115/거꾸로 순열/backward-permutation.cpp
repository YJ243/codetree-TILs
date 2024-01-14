#include <iostream>
#include <vector>
#define MAX_N 8
using namespace std;
// 변수 선언
int n;
vector<int> picked;
bool visited[MAX_N];
void Print(){
    for(int i=0; i<n; i++)
        cout << picked[i] << ' ';
    cout << '\n';
}

// num번째 숫자를 선택하는 함수, 계속 탐색을 이어서 진행 
void Choose(int num){
    // 모든 원소를 선택했을 때, 해당 순열을 출력 
    if(num == n){
        Print();
        return;
    }
    // 뒤에서부터 하나씩 원소를 선택 
    for(int i=n; i>=1; i--){
        if(visited[i]) continue;

        picked.push_back(i);
        visited[i] = true;

        Choose(num+1);

        visited[i] = false;
        picked.pop_back();
    }
}
int main() {
    // 입력:
    cin >> n;
    Choose(0);
    return 0;
}