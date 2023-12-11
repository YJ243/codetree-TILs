#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100

using namespace std;
int n, m;
int A[MAX_N];
int B[MAX_N];


int ans;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> A[i];
    
    for(int j=0; j<m; j++){
        cin >> B[j];
    }
    sort(B, B+m);   // B 정렬
    
    // A에서 길이가 M인 부분 수열을 찾기
    for(int i=0; i<=n-m; i++){
        // (i, i+1, ... i+m-1)
        vector<int> tmp;
        for(int j=i; j<i+m; j++){
            tmp.push_back(A[j]);
        }
        sort(tmp.begin(), tmp.end());
        bool all_flag = true;
        for(int k=0; k<m; k++){
            if(B[k] != tmp[k]){
                all_flag = false;
            } 
        }

        if(all_flag)    ans++;
    }
    
    cout << ans;
    return 0;
}