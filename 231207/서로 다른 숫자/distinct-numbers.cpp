#include <iostream>
#include <unordered_set>
#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
unordered_set<int> s;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        // HashSet에 원소를 추가
        s.insert(val);
    }

    // HashSet의 크기를 출력
    cout << (int)s.size();
    return 0;
}