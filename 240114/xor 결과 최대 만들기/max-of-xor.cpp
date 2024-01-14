/*
 * 내 풀
*/
#include <iostream>
#include <vector>
#define MAX_N 20

using namespace std;

int n, m;
int arr[MAX_N];
vector<int> tmp;
int ans;

void Print(){
    int cur = tmp[0];
    for(int i=1; i<(int)tmp.size(); i++){
        cur = cur ^ tmp[i];
    }
    ans = max(ans, cur);

}

void Choose(int num){
    if((int)tmp.size() == m){
        Print();
        return;
    }

    for(int i=num; i<n; i++){
        tmp.push_back(arr[i]);
        Choose(i+1);
        tmp.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    Choose(0);  // 0번째 숫자를 뽑는 함수
    cout << ans;
    return 0;
}

/*
 * 풀이 1
 * 입력으로 n개의 숫자가 주어졌을 때 backtracking으로 m개를 뽑은 모든 조합 구하기
 * xor 연산의 경우 항등원이 0이기 때문에, 선택한 숫자들의 xor 연산을 하기 전 초기값을 0으로 설정
 * 시간복잡도: O(C(N,M)*M)

#include <iostream>
#include <algorithm>

#define MAX_NUM 20

using namespace std;

// 전역 변수 선언:
int n, m;
int A[MAX_NUM];
bool visited[MAX_NUM];

int ans;

int Calc(){
    // xor 연산의 항등원인 0을 초기값으로 설정
    int val = 0;
    for(int i=0; i<n; i++)
        if(visited[i])
            val ^= A[i];
    return val;
}

void FindMaxXor(int curr_idx, int cnt){
    if(cnt == m){
        // 선택된 모든 조합에 대해 xor 연산 적용
        ans = max(ans, Calc());
        return;
    }
    if(curr_idx == n)
        return;

    // curr_idx index에 있는 숫자를 선택하지 않은 경우
    FindMaxXor(curr_idx+1, cnt);

    // curr_idx index에 있는 숫자를 선택한 경우
    visited[curr_idx] = true;
    FindMaxXor(curr_idx+1, cnt+1);
    visited[curr_idx] = false;
}

int main(){
    // 입력:
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> A[i];

    FindMaxXor(0,0);

    // 출력:
    cout << ans;
    return 0; 
}

*/

/*
 * 풀이 2
 * n개 중 m개를 뽑는 가능한 모든 조합을 만들어 내는 도중 지금까지 선택된 숫자들의 xor 계산 결과값을 지칭하는
 * curr_val를 재귀함수의 인자로 같이 가지고 다니면서 계산하
 * 간단한 계산은 backtracking 과정 속에서 동시에 이루어질 수 있음
 * m개의 숫자를 전부 고르게 되었을 때 다시 선택된 m개의 숫자를 보며 xor할 필요가 없어짐
 * 시간복잡도: O(C(N,M))

#include <iostream>
#include <algorithm>

#define MAX_NUM 20

using namespace std;

// 전역 변수 선언:
int n, m;
int A[MAX_NUM];

int ans;

void FindMaxXor(int curr_idx, int cnt, int curr_val){
    if(cnt == m){
        ans = max(ans, curr_val);
        return;
    }
    if(curr_idx == n)
        return;

    // curr_idx index에 있는 숫자를 선택하지 않은 경우
    FindMaxXor(curr_idx+1, cnt, curr_val);
    // curr_idx index에 있는 숫자를 선택한 경우
    FindMaxXor(curr_idx+1, cnt+1, curr_val^A[curr_idx]);
}

int main() {
    // 입력:
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> A[i];

    FindMaxXor(0, 0, 0);
    
    // 출력:
    cout << ans;

    return 0;
}
*/