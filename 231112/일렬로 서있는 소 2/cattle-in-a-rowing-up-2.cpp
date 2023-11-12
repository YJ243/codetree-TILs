#include <iostream>
#define MAX_N 100
using namespace std;
int N;
int arr[MAX_N];
int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    int result = 0;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            for(int k=j+1; k<N;k++){
                if(arr[i] <= arr[j] && arr[j] <= arr[k])
                    result++;
            }
    cout<<result;
    return 0;
}