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

/*
 *해설 풀이

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int ans;
vector<int> seq;

bool IsBeautiful(){
    // 연달아 같은 숫자가 나오는 시작 위치를 잡는다
    for(int i=0; i<n; i += seq[i]){
        // 만약 연속하여 해당 숫자만큼 나올 수 없다면 아름다운 수가 아니다
        if(i + seq[i] - 1 >= n)
            return false;

        // 연속하여 해당 숫자만큼 같은 숫자가 있는지 확인한다.
        // 하나라도 다른 숫자가 있다면 아름다운 수가 아니다
        for(int j=i; j < i + seq[i]; j++)
            if(seq[j] != seq[i])
                return false;
    }
    return true;
}

void CountBeautifulSeq(int cnt){
    if(cnt == n){
        if(IsBeautiful())
            ans++;
        return;
    }

    for(int i=1; i<=4; i++){
        seq.push_back(i);
        CountBeautifulSeq(cnt+1);
        seq.pop_back();
    }
}

int main(){
    cin >> n;

    CountBeautifulSeq(0);

    cout << ans;
    return 0;
}
*/