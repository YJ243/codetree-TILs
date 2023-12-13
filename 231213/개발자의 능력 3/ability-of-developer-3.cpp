#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;
int arr[6];

int ans = INT_MAX;
int sum = 0;
int make_diff(int a, int b, int c){
    // a,b,c가 한 그룹에 있음
    int sum1, sum2;
    sum1 = a+b+c;
    sum2 = sum-sum1;
    return abs(sum1-sum2);
}
int main(){
    for(int i=0; i<6; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i=0; i<6; i++)
        for(int j=i+1; j<6; j++)
            for(int k=j+1; k<6; k++)
                ans = min(ans, make_diff(i,j,k));
    cout << ans;
    return 0;
}