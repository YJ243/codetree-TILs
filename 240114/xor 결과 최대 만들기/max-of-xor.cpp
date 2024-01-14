#include <iostream>
#include <vector>
#define MAX_N 20

using namespace std;

int n, m;
int arr[MAX_N];
vector<int> tmp;
int ans;

void Print(){
    int cur = tmp[0];
    for(int i=1; i<(int)tmp.size(); i++){
        cur = cur ^ tmp[i];
    }
    ans = max(ans, cur);

}

void Choose(int num){
    if(num == m){
        Print();
        return;
    }

    for(int i=0; i<n; i++){
        int last_num;
        if(tmp.size()>=1)   last_num = tmp.back();
        tmp.push_back(arr[i]);
        if(tmp.size() >= 1 && last_num != tmp.back())
            Choose(num+1);
        tmp.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    Choose(0);  // 0번째 숫자를 뽑는 함수
    cout << ans;
    return 0;
}