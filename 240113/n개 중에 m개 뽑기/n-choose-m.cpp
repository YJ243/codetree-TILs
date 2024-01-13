#include <iostream>
#include <vector>
using namespace std;
int n, m;   // 1이상 n이하의 숫자 중 m개의 숫자 고르기
vector<int> a;

void Print(){
    for(int i=0; i<(int)a.size(); i++)
        cout << a[i] << ' ';
    cout << '\n';
}
void Choose(int num){
    if((int)a.size() == m){
        Print();
        return;
    }

    for(int i=num; i<=n; i++){
        a.push_back(i);
        Choose(i+1);
        a.pop_back();
    }
}

int main() {
    cin >> n >> m;
    Choose(1);  // 1을 고려하는지 확인하는 함수
    return 0;
}