/* 내 풀이 */
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
    Choose(1);  // 1을 선택하는 함수
    return 0;
}

/*
// 해설 풀이 1. 각각의 위치에 있는 숫자를 선택할 것인지 말 것인지에 대한 모든 가짓수를 탐색
// 그 중 정확히 m개가 선택된 경우만 출력: 인자는 1. 어떤 숫자를 뽑을지 말지를 고민중, 2. 지금까지 선택한 숫자가 몇개?
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> combination;

// 방문한 원소들을 출력
void PrintCombination(){
    for(int i=0; i<combination.size(); i++)
        cout << combination[i] << ' ';
    cout << '\n';
}

void FindCombination(int curr_num, int cnt){
    // n개의 숫자를 모두 탐색했으면 더 이상 탐색하지 않음
    if(curr_num == n+1){
        // 탐색하는 과정에서 m개의 숫자를 뽑은 경우 답을 출력
        if(cnt == m)
            PrintCombination();
        return;
    }
    // curr_num에 해당하는 숫자를 사용하였을 때의 경우를 탐색
    combination.push_back(curr_num);
    FindCombination(curr_num+1, cnt+1);
    combination.pop_back();

    // curr_num에 해당하는 숫자를 사용하지 않았을 때의 경우를 탐색
    FindCombination(curr_num+1, cnt);   // vector에 넣지 않고 다음 숫자 탐색(cnt는 그대로)
}

int main() {
    cin >> n >> m;

    FindCombination(1, 0);
    return 0;
}

// 해설 풀이 2. 오름차순으로 순서쌍이 만들어지게 하기 위해 마지막으로 선택한 숫자를 
// 재귀함수의 last_num이라는 인자로 설정하여 해결(증가수열)

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> combination;

// 방문한 원소들을 출력해줍니다.
void PrintCombination() {
    for(int i = 0; i < combination.size(); i++)
        cout << combination[i] << " ";
    cout << endl;
}

// 지금까지 뽑은 개수와 마지막으로 뽑힌 숫자를 추적하여
// 그 다음에 뽑힐 수 있는 원소의 후보를 정하기
void FindCombination(int cnt, int last_num){    // 지금까지 cnt개의 숫자를 뽑았고, 마지막으로 뽑은 숫자가 last_num일 때, 남은 숫자 중에서 어떤 숫자를 뽑을지 선택
    // m개를 모두 뽑은 경우 답을 출력
    if(cnt == m){
        PrintCombination();
        return;
    }

    // 뽑을 수 있는 원소의 후보들을 탐색
    for(int i=last_num+1; i<=n; i++){
        combination.push_back(i);
        FindCombination(cnt+1, i);
        combination.pop_back();
    }
}

int main(){
    cin >> n >> m;

    // 가능한 범위를 순회하며 해당 숫자가 조합의 첫번째 숫자일 때를 탐색
    for(int i=1; i<=n; i++){
        combination.push_back(i);
        FindCombination(1,i);
        combination.pop_back();
    }
    return 0;
}
*/