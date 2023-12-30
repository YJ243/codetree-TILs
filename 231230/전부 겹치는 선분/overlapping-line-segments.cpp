/*
 * 2023.12.30
 * 내 풀이
*/

#include <iostream>
#define MAX_N 100
using namespace std;
int n;
int arr[MAX_N][2];
int count[MAX_N];
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i=0; i<n; i++){
        for(int x=arr[i][0]; x <= arr[i][1]; x++){
            count[x]++;
        }
    }
    bool allOverlapping = false;
    for(int i=0; i<MAX_N; i++){
        if(count[i] == n){
            allOverlapping = true;
        }
    }
    if(allOverlapping) cout << "Yes";
    else    cout << "No";
    return 0;
}

/*
 * 해설
 * 어느 한 선분이라도 시작점이 다른 선분의 끝점보다 뒤에 온다면
 * 선분이 전부 겹칠 수 없음
 * 시작점 중 가장 뒤에 있는 좌표와, 끝점 중 가장 앞에 있는 점의 좌표를 확인
 * 어느 한 선분이라도 시작점이 다른 선분의 끝점보다 뒤에 온다면 선분이 겹치는 지점이 생길 수 없음


#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int x1, x2;
int max_x1;
int min_x2 = INT_MAX;

int main(){
    // 입력:
    cin >> n;
    // 시작점 중 가장 뒤에 있는 좌표와 끝점 중 가장 앞에 있는 점의 좌표를 확인
    for(int i=0; i<n; i++){
        cin >> x1 >> x2;
        max_x1 = max(max_x1, x1);
        min_x2 = min(min_X2, x2);
    }

    // 만약 어느 한 선분이라도 시작점이 다른 선분의 끝점보다 뒤에 온다면
    // 선분이 전부 겹칠 수 없음
    if(min_x2 >= max_x1)
        cout << "Yes";
    else    cout << "No";
    return 0;
}
*/