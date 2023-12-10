#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int ans;
int main() {
    cin >> n;    
    cin >> s;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++)
                if(s[i] == 'C' && s[j] == 'O' && s[k] == 'W'){
                    ans++;
                }
        }
    }
    cout << ans;
    return 0;
}