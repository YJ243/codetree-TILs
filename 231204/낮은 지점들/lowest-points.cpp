#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int, int> m;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;

        if(m.find(x) != m.end()){
            // 만약 해당 x에 대한 좌표가 존재한다면
            if(m[x] > y){
                // 현재 입력으로 들어온 y가 더 작을 때만 업데이트
                m[x] = y;
            }
        }
        else{
            // 만약 해당 x에 대한 좌표가 존재하지 않는다면
            m[x] = y; // 바로 y좌표 넣기
        }
    }

    long long ans = 0;
    for(unordered_map<int,int>::iterator it=m.begin(); it != m.end(); it++){
        //cout << it->first << ' ' << it->second << '\n';
        ans += it->second;
    }
    cout << ans;
    return 0;
}