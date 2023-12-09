#include <iostream>
#define MAX_N 100

using namespace std;
int n;
int keys[MAX_N];
int ans;
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> keys[i];
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(keys[i] <= keys[j] && keys[j] <= keys[k]) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}