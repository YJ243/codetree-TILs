#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> a;

void Print(){
    for(int i=0; i<(int)a.size(); i++)
        cout << a[i] << ' ';
    cout << '\n';
}
void Choose(int num){   // num번째 숫자를 고르는 함수
    if(num == n){
        Print();
        return;
    }
    for(int i=1; i<=k; i++){
        if(num <= 1){
            a.push_back(i);
            Choose(num+1);
            a.pop_back();
        }
        else if(a[num-1] != i || a[num-2] != i){
            a.push_back(i);
            Choose(num+1);
            a.pop_back();
        }
        /*
        해설 풀이
        for(int i=1; i<=k; i++){
            if(num >= 2 && i == a[num-1] && i == a[num-2]) continue;
            else{
                a.push_back(i);
                Choose(num+1);
                a.pop_back();
            }
        }
        
        */
    }
}
int main() {
    cin >> k >> n;
    Choose(0);
    return 0;
}