#include <iostream>
using namespace std;
int age[2];
char sex[2];
int main() {
    for(int i=0; i<2; i++)
        cin >> age[i] >> sex[i];
    
    for(int i=0; i<2; i++){
        if(age[i] >= 19 && sex[i] == 'M')
            cout << 1;
            return 0;
    }
    cout << 0 << '\n';
    return 0;
}