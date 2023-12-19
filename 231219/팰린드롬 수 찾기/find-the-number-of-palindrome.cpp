#include <iostream>
#include <vector>
#define MAX_X 7
using namespace std;
int x, y;
int ans;
int main() {
    cin >> x >> y;
    for(int i=x; i<=y; i++){
        int number = i;
        vector<int> digit;
        while(number){
            digit.push_back(number%10);
            number /= 10;
        }
        bool isfal = true;
        int s = (int)digit.size();
        for(int j=0; j<s; j++){
            if(digit[j] != digit[s-1-j]){
                isfal = false;
                break;
            }
        }
        if(isfal)   ans++;
    }    
    cout << ans << '\n';
    return 0;
}