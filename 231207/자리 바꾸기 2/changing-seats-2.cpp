#include <iostream>
#include <unordered_set>
#include <tuple>
#define MAX_N 100000

using namespace std;
int arr[MAX_N+1];

unordered_set<int> seats[MAX_N];
int n,k;
tuple<int,int> change[MAX_N];
int main() {
    cin >> n >> k;

    // 처음 자리 삽입
    for(int i=1; i<=n; i++){
        seats[i].insert(i);     // seats[i]: i가 앉게되는 자리
        arr[i] = i;             // arr[i]: i번 자리에 앉아있는 사람
    }
    for(int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        change[i] = make_tuple(a,b);
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<k; j++){

            int a,b;
            tie(a,b) = change[j];
            int seat_a, seat_b;
            seat_a = arr[a];    // a자리에 앉아 있는 사람의 번호=seat_a
            seat_b = arr[b];    // b자리에 앉아 있는 사람의 번호=seat_b

            seats[seat_a].insert(b); // a자리에 앉은 사람이 옮긴 자리는 b번 인덱스
            seats[seat_b].insert(a); // b자리에 앉은 사람이 옮긴 자리는 a번 인덱스 
            arr[a] = seat_b;
            arr[b] = seat_a;
        }
    }

    for(int i=1; i<=n; i++){
        cout << seats[i].size() << '\n';
    }
    return 0;
}