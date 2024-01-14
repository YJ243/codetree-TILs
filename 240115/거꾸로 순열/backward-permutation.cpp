#include <iostream>
#include <vector>
#define MAX_N 8
using namespace std;

int n;
vector<int> picked;
bool visited[MAX_N];
void Print(){
    for(int i=0; i<n; i++)
        cout << picked[i] << ' ';
    cout << '\n';
}

void Choose(int num){
    if((int)picked.size() == n){
        Print();
        return;
    }

    for(int i=n; i>=1; i--){
        if(visited[i]) continue;

        picked.push_back(i);
        visited[i] = true;

        Choose(num-1);

        visited[i] = false;
        picked.pop_back();
    }
}
int main() {
    cin >> n;
    Choose(0);
    return 0;
}