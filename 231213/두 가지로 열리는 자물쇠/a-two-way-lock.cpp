#include <iostream>
#include <cstdlib>  // For abs()
using namespace std;

int n;
int arr1[3];
int arr2[3];
int ans;

int correctDiff(int a, int b) {
    int diff = abs(a - b);
    return min(diff, n - diff);
}

int main() {
    cin >> n;
    for(int i=0; i<3; i++)
        cin >> arr1[i];
    for(int i=0; i<3; i++)
        cin >> arr2[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                int a1 = correctDiff(i, arr1[0]);
                int a2 = correctDiff(j, arr1[1]);
                int a3 = correctDiff(k, arr1[2]);
                
                int b1 = correctDiff(i, arr2[0]);
                int b2 = correctDiff(j, arr2[1]);
                int b3 = correctDiff(k, arr2[2]);

                if((a1 <= 2 && a2 <= 2 && a3 <= 2) || (b1 <= 2 && b2 <= 2 && b3 <= 2))
                    ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}