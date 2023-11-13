#include <iostream>
#include <string>
using namespace std;

string a;
int main() {
    cin >> a;
    int ans = 0;
    for(int i=0; i<=a.size()-4; i++){
        for(int j=i+2; j<=a.size()-2; j++){
            if(a[i] == '(' && a[i+1] == '(' && a[j] == ')' && a[j+1] ==')')
                ans++;
        }
    }
    cout<<ans;
    return 0;
}