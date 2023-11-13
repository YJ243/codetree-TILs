#include <iostream>
#include <string>
#define MAX_N 100

using namespace std;
int N;
string s;
int main() {
    cin >> N >> s;
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(s[i] == 'C' && s[j] == 'O' && s[k] == 'W')
                    ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}