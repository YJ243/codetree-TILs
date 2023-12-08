/*
 * 2023.12.08
 * 모든 조합에 대해 진행하여 답을 구하기: O(M^3) x O(N) = O(N*N^3)
 * 1. 조합 정하기 2. 그룹 A의 문자열 모두 HashSet에 넣기 3. 그룹 B에 대해 문자열 만든 후 A의 HashSet에 있는지 확인
 * HashSet: 추가/탐색 시간: O(1)
*/
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
#define MAX_N 500

// 변수 선언
int n, m;
int ans;
unordered_set<string> s;
string a[MAX_N];
string b[MAX_N];

bool is_divide(int i, int j, int k){
    // i, j, k번째 자리수를 선택했을 때 a와 b그룹이 완벽하게 구분되면 true, 그렇지 않으면 false
    s.clear();
    
    // a의 원소를 전부 hashset에 넣어줌
    for(int idx=0; idx<n; idx++){
        s.insert(a[idx].substr(i,1) + a[idx].substr(j,1) + a[idx].substr(k,1));
    }
    
    // b의 원소 중 하나라도 a와 같은 경우가 있다면 a와 b를 구분할 수 없음
    for(int idx=0; idx<n; idx++){
        if(s.find(b[idx].substr(i,1) + b[idx].substr(j,1) + b[idx].substr(k,1)) != s.end()){
            // 만약 b 문자열이 a에 존재한다면
            return false;
        }
    }
    // 모든 b의 원소가 a와 다르다면 a와 b를 구분해낼 수 있음
    return true;
    
}

int main(){
    // 입력:
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
        cin >> b[i];
    

    // 세자리 고르기, 서로 다른 세 자리의 조합을 모두 순회
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                // i, j, k번째 자리를 선택했을 때 두 그룹을 완벽하게 구분할 수 있는지 확인
                if(is_divide(i,j,k)) ans++;
            }
        }
    }

    // 두 그룹을 구분해낼 수 있는 조합 수 출력
    cout << ans;
    
    return 0;
}