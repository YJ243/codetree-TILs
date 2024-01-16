#include <iostream>
#define MAX_N 200
#define MAX_BELT 3
using namespace std;

int n, t;
int arr[MAX_BELT][MAX_N];

int main() {
    cin >> n >> t;
    for(int i=0; i<MAX_BELT; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    while(t--){
        int temp = arr[0][n-1];
        for(int i=n-1; i>=1; i--)
            arr[0][i] = arr[0][i-1];
        
        arr[0][0] = arr[2][n-1];

        int temp2 = arr[1][n-1];
        for(int i=n-1; i>=1; i--)
            arr[1][i] = arr[1][i-1];
        arr[1][0] = temp;


        for(int i=n-1; i>=1; i--)
            arr[2][i] = arr[2][i-1];
        arr[2][0] = temp2;
    }
    
    for(int i=0; i<MAX_BELT; i++){
        for(int j=0; j<n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}