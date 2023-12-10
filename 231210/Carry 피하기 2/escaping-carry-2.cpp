#include <iostream>

#define MAX_N 20
using namespace std;

int n;
int arr[MAX_N];

bool is_carry(int x, int y, int z){
    int cnt = 4;
    int a=x, b=y, c=z;
    int remain_a, remain_b, remain_c;
    while(cnt--){
        // 10으로 나눈 나머지
        remain_a = a % 10;  remain_b = b % 10; remain_c = c % 10;

        if(remain_a + remain_b + remain_c >= 10)    return true;
        a = (a-remain_a)/10; b = (b-remain_b)/10; c = (c-remain_c)/10;
    }

    // 반복문을 빠져나왔다면 carry가 발생하지 않았음
    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int val = -1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(!is_carry(arr[i],arr[j],arr[k])){
                    // carry가 발생하지 않는다면
                    val = max(val, arr[i]+arr[j]+arr[k]);
                }
            }
        }
    }
    cout << val;
    return 0;
}