#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main() {
    cin >> n;
    cin >> s;

    int curMax = 0, maxI = 0, maxJ = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0') continue;
        for(int j=i+1; j<n; j++){
            if(s[j] == '0') continue;
            if(curMax < j-i){
                curMax = j-i;
                maxI = i;
                maxJ = j;
            }
            break;
        }
    }
    s[(maxI+maxJ)/2] = '1';
    int curMin = 1000;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i] == '1' && s[j] == '1'){
                if(curMin > j-i){
                    curMin = j-i;
                }
            }
        }
    }
    //cout << "MAX: "<<curMax<<'\n';
    //cout << "Min: "<<curMin<<'\n';
    s[(maxI+maxJ)/2] = '0'; // 다시 원래대로 돌려놓고
    if(curMax==0) curMin= 0;
    //cout << "Min: "<<curMin<<'\n';

    // 만약 맨 처음이나 맨 마지막이 0일 경우를 처리
    if(s[0] == '0'){
        s[0] = '1';
        int tmpMin = 1000;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == '1' && s[j] == '1'){
                    if(tmpMin > j-i){
                        tmpMin = j-i;
                    }
                }
            }
        }
        //cout << "tmpMin: " << tmpMin << '\n';
        if(curMin<tmpMin)   curMin = tmpMin;
        s[0] = '0';
    }
    if(s[n-1] == '0'){
        s[n-1] = '1';
        //cout << s << '\n';
        int tmpMin = 1000;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == '1' && s[j] == '1'){
                    if(tmpMin > j-i){
                        tmpMin = j-i;
                    }
                }
            }
        }
        //cout << "tmpMin: " << tmpMin << '\n';
        if(curMin<tmpMin)   curMin = tmpMin;
        s[n-1] = '0';
    }


    cout << curMin;


    return 0;
}