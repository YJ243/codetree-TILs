#include <iostream>
#include <string>
#define MAX_N 20

using namespace std;

int n;
string s;
int arr[MAX_N];
int tmp[MAX_N];
int ans;
int main(){
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++){
        arr[i] = s[i]-'0';
    }
    for(int i=0; i<n; i++){
        // i는 새로운 1이 들어갈 자리
        if(arr[i] == 1) continue;
        for(int j=0; j<n; j++)
            tmp[j] = arr[j];
        tmp[i] = 1;     // 새로운 자리에 1을 넣기

        // tmp를 순회하면서 가장 가까운 두 사람 간의 거리를 구하기
        int cur_max = 20;
        for(int j=0; j<n; j++){
            if(tmp[j] == 0) continue;
            for(int k=j+1; k<n; k++){
                if(tmp[k] == 0) continue;
                cur_max = min(cur_max, k-j);
            }
        }
        ans = max(ans, cur_max);
    }
    cout << ans;
    return 0;
}