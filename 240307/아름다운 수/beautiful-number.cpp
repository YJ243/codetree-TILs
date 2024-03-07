#include <iostream>
#include <vector>

using namespace std;

vector<int> selected;
int n;
int ans;
void Check(){
    bool IsBeauty = true;
    
    int idx = 0, curNum = selected[idx];
    while(idx < (int)selected.size()){
        if(idx+curNum-1 >= n){
            IsBeauty = false;
            break;
        }

        for(int i=idx; i < idx+curNum; i++){
            if(curNum != selected[i])
                IsBeauty = false;
        }
        if(!IsBeauty)
            break;
        idx += curNum;
        curNum = selected[idx];
    }
    if(IsBeauty)
        ans++;

}

void Choose(int num){
    if(num == n){
        Check();
        return;
    }

    for(int i=1; i<=4; i++){
        selected.push_back(i);
        Choose(num+1);
        selected.pop_back();
    }
}

int main() {
    cin >> n;
    Choose(0);      // 0번째 숫자를 고르는 함수
    
    cout << ans;
    return 0;
}