#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> nums;
vector<int> ans;

bool IsPossible(){
    for(int i=1; i<=n/2; i++){      // 길이는 i만큼 보기
        for(int j=0; j<=n-2*i; j++){
            // j부터 시작
            int cnt = 0;
            for(int k=0; k<i; k++){
                if(nums[j+k] == nums[j+k+i])
                    cnt++;
            }
            if(cnt == i)
                return false;
        }
    }
    return true;
}

void Print(){
    for(int i=0; i<n; i++)
        cout << nums[i];
}

void Choose(int idx){
    if(idx == n){
        if(IsPossible()){
            Print();
            exit(0);
        }
        return;
    }

    for(int i=4; i<=6; i++){
        nums.push_back(i);
        Choose(idx+1);
        nums.pop_back();
    }
}

int main() {
    cin >> n;
    Choose(0);      // 0번째 숫자를 고르기
    return 0;
}