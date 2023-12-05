#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_M 100000
using namespace std;

int t, m;       // t: 테스트 케이스 개수, m: 수열의 크기 
int arr[MAX_M];
int main(){
    cin >> t;
    while(t--){
        cin >> m;
        for(int i=0; i<m; i++)
            cin >> arr[i];
        int mid = 0;
        int val = 0;        
        priority_queue<int> lessPQ;    // 중앙값보다 더 작은 숫자들이 들어갈 큐(최대힙, 가장 큰 수를 반환하도록)
        priority_queue<int> greaterPQ; // 중앙값보다 더 큰 숫자들이 들어갈 큐(최소힙, 가장 작은 수를 반환하도록)
        mid = arr[0];
        cout << mid << ' ';
        for(int i=1; i<m; i++){
            if(i%2==1){ // 짝수 번째 수를 읽는다면
                if(arr[i] < mid){
                    lessPQ.push(arr[i]);
                }
                else{
                    greaterPQ.push(-arr[i]);
                }
            }
            else{       // 홀수 번째 수를 읽는다면
                // 두 개의 우선순위 큐 중에서 더 많은 곳에서 하나 빼기
                if(lessPQ.size() > greaterPQ.size()){
                    val = lessPQ.top();
                    lessPQ.pop();
                }
                else{
                    val = -greaterPQ.top();
                    greaterPQ.pop();
                }
                // min, val, arr[i]를 정렬하기
                int cur_arr[3] = {mid, val, arr[i]};
                sort(cur_arr, cur_arr+3);
                mid = cur_arr[1];
                lessPQ.push(cur_arr[0]);
                greaterPQ.push(-cur_arr[2]);
                cout << mid << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}