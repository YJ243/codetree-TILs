#include <iostream>
#include <vector>

using namespace std;
int k, n;
vector<int> selected;

void Print(){
    for(int i=0; i<n; i++){
        cout << selected[i] << ' ';
    }
    cout << '\n';
}

void Choose(int idx){   // idx번째 숫자를 고르는 함수
    if(idx == n){
        Print();
        return;
    }
    for(int i=1; i<=k; i++){
        selected.push_back(i);
        Choose(idx+1);
        selected.pop_back();
    }
}

int main() {
    cin >> k >> n;
    Choose(0);    
    return 0;
}