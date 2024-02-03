#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int main() {
    // 입력:
    cin >> str;

    // 문자 사전순 정렬
    sort(str.begin(), str.end());
    cout << str;
    return 0;
}