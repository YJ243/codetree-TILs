#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 변수 선언
int n;
vector<string> arr;
int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        arr.push_back(str);
    }
    // 문자열 사전순 정렬
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}