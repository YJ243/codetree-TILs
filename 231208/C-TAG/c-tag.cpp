#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
#define MAX_N 500
#define MAX_M 50

int n, m;
int ans;
unordered_set<string> s;
string a[MAX_N];
string b[MAX_N];

bool is_divide(int i, int j, int k){

    s.clear();
    
    for(int idx=0; idx<n; idx++){
        s.insert(a[idx].substr(i,1) + a[idx].substr(j,1) + a[idx].substr(k,1));
    }
    

    for(int idx=0; idx<n; idx++){
        if(s.find(b[idx].substr(i,1) + b[idx].substr(j,1) + b[idx].substr(k,1)) != s.end()){
            // 만약 b 문자열이 a에 존재한다면
            return false;
        }
    }
    
    return true;
    
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
        cin >> b[i];
    

    // 세자리 고르기
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                if(is_divide(i,j,k)) ans++;
            }
        }
    }
    cout << ans;
    
    return 0;
}