#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n;
vector<pair<int, int>> a;

bool compare1(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

bool compare2(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), compare1);

    bool isOverlapping = false;
    int maxX[2] = {a[1].first, a[1].second};

    sort(a.begin(), a.end(), compare2);
    int minX[2] = {};
    if(a[0].first != maxX[0] || a[0].second != maxX[1]){
        minX[0] = a[0].first, minX[1] = a[0].second;
    }
    else{
        minX[0] = a[1].first, minX[1] = a[1].second;
    }
    if(maxX[0] <= minX[1])  isOverlapping = true;

    minX[0] = a[1].first, minX[1] = a[1].second;
    sort(a.begin(), a.end(), compare1);
    if(a[0].first != minX[0] || a[0].second != maxX[1]){
        maxX[0] = a[0].first, maxX[1] = a[0].second;
    }

    else{
        maxX[0] = a[1].first , maxX[1] = a[1].second;
    }
    if(maxX[0] <= minX[1]) isOverlapping = true;
    if(isOverlapping) cout << "Yes";
    else cout << "No";
    /*
    // 정렬된 배열 출력 (옵션)
    for (const auto& pair : a) {
        cout << pair.first << " " << pair.second << endl;
    }*/

    return 0;
}