/*
 * 2023.12.29
 * 내 풀이
*/

#include <iostream>
using namespace std;

int x1, x2, x3, x4;
int main() {
    cin >> x1 >> x2 >> x3 >> x4;
    if((x1 <= x3 && x3 <= x2) || (x3 <= x1 && x1 <= x4)){
        cout << "intersecting";
    }
    else
        cout << "nonintersecting";
    return 0;
}

/*
 * 해설 풀이

#include <iostream>

using namespace std;

int x1, x2, x3, x4;

bool Intersecting(int x1, int x2, int x3, int x4){
    // 겹치지 않는 경우에 대한 처리를 먼저 진행하기
    if(x2 < x3 || x4 < x1)
        return false;
    // 나머지는 전부 겹치는 경우라고 볼 수 있음
    else
        return true;
}

int main(){
    // 입력:
    cin >> x1 >> x2 >> x3 >> x4;

    // 겹치는지를 확인하기
    if(Intersecting(x1, x2, x3, x4))
        cout << "intersecting";
    else
        cout << "nonintersecting";
    return 0;
}
*/