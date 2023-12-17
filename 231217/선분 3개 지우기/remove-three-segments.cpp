#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 10

using namespace std;
int n;
int arr[MAX_N][2];
int ans;
int main() {
    cin >> n;
    int minX = INT_MAX, maxX = INT_MIN;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
        minX = min(minX, arr[i][0]);
        maxX = max(maxX, arr[i][1]);
    }
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int counting[maxX+1] = {};
                for(int l=0; l<n; l++){
                    if(l == i || l == j || l == k) continue;
                    for(int x=arr[l][0]; x <= arr[l][1]; x++)
                        counting[x]++;
                }
                bool overlapped = false;
                for(int l=0; l<=maxX; l++){
                    if(counting[l] > 1){
                        overlapped = true;
                        break;
                    }
                }
                if(!overlapped) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}