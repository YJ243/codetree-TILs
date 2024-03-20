#include <iostream>
#include <vector>
using namespace std;

int k, n;

vector<int> number;

void Print(){
    for(int i=0; i<(int)number.size(); i++)
        cout << number[i] << ' ';
    cout << '\n';
}

void Choose(int idx){
    if(idx == n){
        Print();
        return;
    }

    for(int i=1; i<=k; i++){
        number.push_back(i);
        Choose(idx+1);
        number.pop_back();
    }
}

int main() {
    cin >> k >> n;
    Choose(0);      // 0번째 숫자를 고르러 가기
    return 0;
}