#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MAX_N 100000

using namespace std;

int n, k;
int arr[MAX_N];
int ans[MAX_N];
unordered_map<int, int> freq;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) // 가장많이 등장한 카운트 값이 같다면?
    {
        return a.first > b.first; // first 값이 더 큰게 앞으로 가게 해라!
    }
    return a.second > b.second; // second 값이 같지 않다면 더 큰 값이 앞으로 가게 해라!
}

int main() {
    cin >> n >> k;   // n개의 숫자가 주어졌을 때 자주 등장한 순으로 k개의 숫자를 출력
    for(int i=0; i<n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<pair<int, int>> vec(freq.begin(), freq.end()); // map을 vector로 변경

    sort(vec.begin(), vec.end(), compare);

    for(int i=0; i<k; i++){
        cout << vec[i].first << ' ';
    }

    return 0;
}