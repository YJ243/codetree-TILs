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
    
    // 모든 구간을 잡기
    for(int i=0; i<n; i++){ // 구간의 시작점 잡기
        for(int j=i; j<n; j++){ // 구간의 끝점 잡기
            // 구간 [i,j] 내 원소의 합을 구하기
            int sum = 0;
            
            for(int k=i; k<=j; k++){
                sum += arr[k];

            }
            // 평균 구하기
            double avg = (double)sum / (j-i+1);

            // 구간 내에 원소 평균값과 동일한 원소가 있으면 답 증가
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