#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> arr;

void Print(){
    for(int i=0; i<(int)arr.size(); i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

void Choose(int num){   // num 번째 숫자 고르기
    if(num == n){       // 만약 n개 숫자 모두 고르고 다음으로 넘어왔다면
        Print();        // 출력
        return;
    }

    for(int i=1; i<=k; i++){
        arr.push_back(i);
        Choose(num+1);
        arr.pop_back();
    }

}

int main(){
    cin >> k >> n;      // 1 ~ k 이하의 숫자, n번 반복해서 고르기

    Choose(0);          // 0번째 숫자 고르기
    return 0;
}