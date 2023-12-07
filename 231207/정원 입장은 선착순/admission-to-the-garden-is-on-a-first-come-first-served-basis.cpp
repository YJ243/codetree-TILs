#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
#define MAX_N 100000

using namespace std;

int N;
tuple<int, int, int> people[MAX_N+1];
priority_queue<tuple<int, int, int> > pq;

int ans = 0;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int arrive_time, staying_time;
        cin >> arrive_time >> staying_time;
        people[i] = make_tuple(arrive_time, i+1, staying_time); // 도착시간, 번호표(1부터 시작), 머무르는 시간

    }

    // 구현 편의상 마지막 사람 추가
    people[N] = make_tuple(INT_MAX, N+1, 0);

    sort(people, people+N+1);
    int exit_time = 0;
    for(int i=0; i<N; i++){
        // 일단 도착 시간이 빠른 순으로 사람을 보기 시작하는데
        int arrive, num, stay;
        tie(arrive,num,stay) = people[i];
        //cout << arrive << ' ' << num << ' ' << stay << '\n';

        // 앞서 정원에서 빠져나온 시간보다 더 나중에 도착했다면
        while(arrive >= exit_time && !pq.empty()){
            // 대기하고 있는 사람들 뽑아서 입장시켜주기
            int cur_num, cur_arrive, cur_stay;
            tie(cur_num, cur_arrive, cur_stay) = pq.top();
            cur_num *= -1;
            pq.pop();
            
            // 대기 시간의 최댓값 찾기
            ans = max(ans, exit_time-cur_arrive);
            exit_time += cur_stay;
            
        }

        if(arrive >= exit_time){
            // 대기 없이 바로 들어갈 수 있는 경우
            exit_time = arrive + stay;
        }
        // 기다려야 한다면
        else
            pq.push(make_tuple(-num, arrive, stay));
    }
    cout << ans;
    return 0;
}