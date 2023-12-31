/*
 * 2023.12.31
 * 조금 이해가 안되는 문제, 일주일 뒤에 다시 풀어보기
 * n명의 사람에 대해 각 사람이 메시지를 읽었을지 읽지 않았을 지 판단하기
 * 1. p번째 메시지 기준 그 이후에 채팅을 친 사람은 확실하게 p번째 메시지 읽음
 * 2. p번째 메시지를 읽은 사람 수와, 그 이후에 나온 한 메시지를 읽은 사람의 수가 같다면, 
 *    p번째 메시지 보낸 사람 <-> 그 이후에 메시지를 보낸 사람이 서로가 서로 메시지를 읽은 것
 *    그 이후에 메시지를 보낸 사람이 확실하게 p번째 메시지를 익
*/
#include <iostream>

#define MAX_M 100
using namespace std;

int n, m, p;    // n: 사람 수, m: 메세지 개수, p: 확인 할 번호
//pair<char, int> message[MAX_N];
char c[MAX_M];
int u[MAX_M];


int main() {
    cin >> n >> m >> p;
    for(int i=0; i<m; i++){
        cin >>c[i] >> u[i];
    }
    // 모두 읽은 채팅이라면 읽지 않은 사람은 없음
    if(u[p-1] == 0) return 0;

    // 각 사람에 대해 채팅을 읽었을 지 안 읽었을지 판단하기
    for(int person = 0; person < n; person++){
        // read: 확실하게 채팅을 읽었으면 true
        char num = 'A' + person;
        bool read = false;

        // 만약 p번 메시지를 읽은 사람 수와 같은 채팅을 기준으로
        // 한 번이라도 채팅을 쳤다면 확실하게 채팅을 읽음
        for(int j=0; j<m; j++){
            if(c[j] == num && u[j] >= u[p-1]){
                read = true;
            }
        }
        if(read == false)   cout << num << " ";
    }
    return 0;
}