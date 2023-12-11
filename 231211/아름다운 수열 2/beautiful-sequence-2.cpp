#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX_N 100

using namespace std;
int n, m;
int A[MAX_N];
int B[MAX_N];

vector<int> tmp;
unordered_set<int> arr;
int ans;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> A[i];
    
    for(int j=0; j<m; j++){
        cin >> B[j];
        arr.insert(B[j]);
    }

    
    // A에서 길이가 M인 부분 수열을 찾기
    for(int i=0; i<=n-m; i++){
        // (i, i+1, ... i+m-1)
        bool all_flag = true;
        for(int j=i; j<i+m; j++){
            if(arr.find(A[j]) == arr.end()){
                // 만약 하나라도 원소가 없다면
                all_flag  = false;
                break;
            }
        }
        if(all_flag){
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}