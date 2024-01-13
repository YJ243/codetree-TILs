#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_N 10
using namespace std;
int n;
int arr[MAX_N];
int ans = INT_MAX;
vector<int> tmp;

void FindMinDist(int num){ // num번째 위치에서 다음 위치를 찾아가는 함수
    if(num >= n-1){
        if(find(tmp.begin(), tmp.end(), n-1) != tmp.end()){
            ans = min(ans, (int)tmp.size());
        }
        
        return;
    }

    for(int i=1; i<=arr[num]; i++){
        int next_num = num+i;
        tmp.push_back(next_num);
        FindMinDist(next_num);
        tmp.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    FindMinDist(0); // 0번째 위치에서 맨 마지막으로 가기 위해 다음 위치를 찾기
    if(ans == INT_MAX){
        ans = -1;
    }
    cout << ans;
    return 0;
}
/*
해설 코드

#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 10

using namespace std;

int n;
int num[MAX_N];

int ans = INT_MAX;

void FindMin(int idx, int cnt){
    // 마지막 위치를 넘었을 때 그 중 최소 이동 횟수를 갱신
    if(idx >= n-1){
        ans = min(ans, cnt);
        return;
    }
    for(int dist = 1; dist <= num[idx]; dist++)
        FindMin(idx+dist, cnt+1);
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> num[i];

    FindMin(0,0);

    if(ans == INT_MAX)
        ans = -1;
    cout << ans;
    return 0;
}

*/