/*
 * 2023.12.29
 * 내 풀이
 * 전체 영역에 대해 주어진 구역 범위에 숫자를 추가하고, 0이 아닌 부분의 개수를 셈
*/

#include <iostream>
#define MAX_A 100
using namespace std;
int a,b,c,d;
int arr[MAX_A];

int main() {
    cin >> a >> b;
    cin >> c >> d;
    for(int i=a; i<b; i++)
        arr[i]++;
    for(int i=c; i<d; i++)
        arr[i]++;
    int ans = 0;
    for(int i=0; i<MAX_A; i++){
        if(arr[i]) ans++;
    }
    cout << ans;
    return 0;
}

/*
 * 해설 풀이

#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;

bool Intersecting(int x1, int x2, int x3, int x4){
    // 겹치지 않는 경우에 대한 처리를 먼저 진행
    if(x2 < x3 || x4 < x1){
        // y1 < x2 || y2 < x1
        return false;
    }
    // 나머지는 전부 겹치는 경우임
    else
        return true;
}

int main(){
    // 입력:
    cin >> a >> b >> c >> d;

    // 겹치는 지를 확인하기
    if(Intersecting(a,b,c,d)){
        // 만약 겹치는 부분이 있다면,
        // 두 구역들 중 가장 큰 구역에서 가장 작은 구역을 빼면
        // 오늘 몇 구역이나 청소됐는지 알 수 있음
        cout << max(b, d) - min(a,c);
    }
    else{
        // 만약 겹치는 부분이 없다면,
        // 두 구역들을 전부 더하면
        // 오늘 몇 구역이나 청소됐는지 알 수 있음
        cout << (b-a) + (d-c);
    }
    return 0;
}
*/