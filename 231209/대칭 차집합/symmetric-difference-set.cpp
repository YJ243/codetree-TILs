#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<long long> a;
unordered_set<long long> b;
int cnt_a, cnt_b;
int main() {
    cin >> cnt_a >> cnt_b;
    for(int i=0; i<cnt_a; i++){
        int val;
        cin >> val;
        a.insert(val);
    
    }

    for(int i=0; i<cnt_b; i++){
        int val;
        cin >> val;
        if(a.find(val) != a.end()){
            a.erase(val);
        }
        else{
            // a에 원소가 없다면
            b.insert(val);
        }
    }
    cout << (int) a.size() + b.size();
    return 0;
}