#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, m;   // n개의 점, m번 반복
priority_queue<tuple<long long, int, int>> pq; 
int main(){
    cin >> n >> m;
    // 우선순위큐, x+y -> x -> y 작은 순
    while(n--){
        int x, y;
        cin >> x >> y;
        long long sum_coor = abs(x) + abs(y);
        pq.push(make_tuple(-(sum_coor),-x,-y));
    }
    while(m--){
        int nx, ny;
        tie(ignore, nx, ny) = pq.top();
        pq.pop();
        nx *= -1; ny *= -1;
        nx += 2; ny += 2;
        //cout << nx << ' ' << ny << '\n';
        long long sum_coor = abs(nx) + abs(ny);
        pq.push(make_tuple(-(sum_coor),-nx,-ny));
    }
    int minX, minY;
    tie(ignore, minX, minY) = pq.top();
    cout << -minX << ' ' << -minY << '\n';
    return 0;
}