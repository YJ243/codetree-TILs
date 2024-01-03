/*
 * 2023.1.3
 * Backtracking을 활용해 가능한 모든 중복 순열 탐색
 * 특정 시점에 뽑힌 숫자의 개수를 인자로 설정, n개의 숫자를 모두 뽑았을 때마다 출력
 * 사전 순으로 앞선 것부터 순서쌍이 만들어지기 하기 위해 사용 가능한 숫자 중 가장 작은 숫자부터 순회
*/

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

void Choose(int num){   // 지금까지 num개의 숫자를 뽑았을 때 그 다음 어떤 숫자를 뽑을지 선
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