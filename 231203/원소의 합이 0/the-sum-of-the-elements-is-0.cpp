#include <iostream>
#include <unordered_map>
#include <vector>
#define MAX_N 5000

using namespace std;

int n;
int arr[4][MAX_N];
unordered_map<int,int> freq_first;  // A+B의 조합
unordered_map<int,int> freq_second; // C+D의 조합

int main() {
    cin >> n;
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    // 시간복잡도: O(N^2)=25*10^6
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            freq_first[arr[0][i]+arr[1][j]]++;
            //cout << arr[0][i] << ' ' << arr[1][j] << ' ' << arr[0][i]+arr[1][j] << ' ' << freq_first[arr[0][i]+arr[1][j]] << '\n';
            
            freq_second[arr[2][i]+arr[3][j]]++;
            //cout << arr[2][i] << ' ' << arr[3][j] << ' ' << arr[2][i]+arr[3][j] << ' ' << freq_second[arr[2][i]+arr[3][j]] << '\n';
        }
    }
    
    int ans = 0;
    for(unordered_map<int, int>::iterator it=freq_first.begin(); it != freq_first.end(); it++){
        int diff = -(it->first);
        //cout << diff << ' ' ;
        if(freq_second.find(diff) != freq_second.end())
            ans += freq_second[diff]*(it->second);
    }
    cout << ans << '\n';
    return 0;
}