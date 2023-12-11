#include <iostream>
#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N];
int ans;
int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];

            }
            double avg = (double)sum / (j-i+1);

            for(int k=i; k<=j; k++){
                if(arr[k] == avg) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}