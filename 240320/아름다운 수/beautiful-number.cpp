#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> numbers;
int ans;

bool Isbeautiful(){
    // 연달아 같은 숫자가 나오는 시작 위치를 잡는다.
    for(int i=0; i<(int)numbers.size(); i += numbers[i]){
        // 만약 연속하여 해당 숫자만큼 나올 수 없다면
        if(numbers[i] + i-1 >= n)   // 만약 아름다운 수를 만들 길이가 모자른다면 false
            return false;
        int val = numbers[i];
        for(int j=i; j<i+val; j++){
            if(val != numbers[j])   // 만약 해당 숫자만큼 연달아 같은 숫자가 나오지 않는다면
                return false;       // 하나라도 다른 숫자가 있다면 아름다운 수가 아니다
        }        
    }
    return true;
}

void Choose(int idx){
    if(idx == n){
        if(Isbeautiful()){
            ans++;
        }
        return;
    }

    for(int i=1; i<=4; i++){
        numbers.push_back(i);
        Choose(idx+1);
        numbers.pop_back();
    }
}

int main() {
    cin >> n;
    Choose(0);      // n자리 숫자 중 0번째 숫자를 고르는 함수
    cout << ans << '\n';
    return 0;
}