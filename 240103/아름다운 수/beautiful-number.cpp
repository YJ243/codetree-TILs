/*
 * 2023.1.3
 * 각 자리에 대해 1~4 사이의 숫자 중 하나를 선택
 * 총 N번 선택하는 재귀를 작성해 가능한 모든 숫자를 만들어내기
 * 그 중 정확히 해당 숫자만큼 연달아 같은 숫자가 나오는 숫자의 수를 세면 
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;    // 만든 수 배열
int n;              // n자리 아름다운 수
int ans;            // 아름다운 수 개수

void CheckBeautiful(){  // 만든 n자리 수가 아름다운 수인지 확인하는 함수
    bool isBeautiful = true;

    int idx = 0, cur_num = arr[0];  // 맨 처음 수로 인덱스와 현재 수를 잡기
    while(idx != n){                // n자리 수를 모두 볼껀데
        for(int i=idx; i <= idx+cur_num-1; i++){ // 현재 인덱스부터 연속된 수가 나오는지 현재 수의 자리 개수만큼 확인
            if(arr[i] != cur_num) isBeautiful = false;  // 만약 연속된 수가 나오지 않으면 false
        }
        if(!isBeautiful) break;     // 아름다운 수가 아니면 반복문 나가기
        idx += cur_num;             // 그 다음 인덱스는 현재 인덱스에서 현재 보고 있던 수를 더한 만큼 증가한 인덱스
        cur_num = arr[idx];         // 그때의 수
    }

    if(isBeautiful)
        ans++;      // 아름다운 수라면 정답 갱신

    /* 해설은 아래와 같이 풀었음
    
    // 연달아 같은 숫자가 나오는 시작 위치를 잡기
    for(int i=0; i<n; i += seq[i]){
        // 만약 연속하여 해당 숫자만큼 나올 수 없다면 아름다운 수가 아님
        if(i + seq[i]-1 >= n)
            return false;
        // 연속하여 해당 숫자만큼 같은 숫자가 있는지 확인
        // 하나라도 다른 숫자가 있다면 아름다운 수가 아님
        for(int j=i; j<i+seq[i]; j++)
            if(seq[j] != seq[i])
                return false;
    }
    return true;
    */

}

void Choose(int cnt){   // cnt개 숫자를 골랐고, 그 다음 숫자를 고르는 함수
    if(cnt == n){
        CheckBeautiful();
        return;
    }

    for(int i=1; i<=4; i++){
        arr.push_back(i);
        Choose(cnt+1);
        arr.pop_back();
    }
}
int main() {
    cin >> n;

    Choose(0);
    cout << ans;
    return 0;
}