#include <iostream>
#include <cstdlib>  // For abs()
using namespace std;

int n;
int arr1[3];
int arr2[3];
int ans;

int main() {
    cin >> n;
    for(int i=0; i<3; i++)
        cin >> arr1[i];
    for(int i=0; i<3; i++)
        cin >> arr2[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                // 모든 자리가 주어진 첫 조합과의  거리가 2 이내인지 확인
                if((abs(arr1[0]-i) <= 2 || abs(arr1[0]-i) >= n-2) && (abs(arr1[1]-j) <= 2 || abs(arr1[1]-j) >= n-2) &&
                 (abs(arr1[2]-k) <= 2 || abs(arr1[2]-k) >= n-2)) ans++;

                // 모든 자리가 주어진 첫 조합과의 거리가 2 이내인지 확인
                else if((abs(arr2[0]-i) <= 2 || abs(arr2[0]-i) >= n-2) && (abs(arr2[1]-j) <= 2 || abs(arr2[1]-j) >= n-2) &&
                 (abs(arr2[2]-k) <= 2 || abs(arr2[2]-k) >= n-2)) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}