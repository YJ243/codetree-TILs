#include <iostream>
#include <queue>
#include <cstdlib>
#define MAX_N 100000
using namespace std;

priority_queue<int> pq;     // 가장 작은 숫자 3개를 반환하기 위한 우선순위 큐(minHeap)
int N;      // N 개의 숫자
int arr[3]; // 현재까지 가장 작은 숫자 3개
int input_arr[MAX_N];
int main() {
    // 입력:
    cin >> N;
    //N = 10000;
    for(int i=0; i<N; i++){
        int val;
        cin >> val;
        //val = rand()%10000+1;
        //cout << val << ' ';
        pq.push(-val);
        if(i < 2)       // 주어진 숫자의 수가 채 3개가 되지 않는다면 
            //continue;
            cout << -1 << '\n';

        else{           // 주어진 숫자의 수가 3개 이상이라면
            for(int j=0; j<3; j++){ // 3개의 숫자를 뽑기
                arr[j] = pq.top();  
                pq.pop();
                arr[j] *= -1;
            }
            long long ans = 1;
            for(int j=0; j<3; j++){
                ans *= arr[j];      // 3개의 숫자의 곱을 구하기
                pq.push(-arr[j]);   // 다시 큐에 집어넣기
            }
            cout << ans << '\n';    // 해당 곱 출력
        }
    }
    return 0;
}