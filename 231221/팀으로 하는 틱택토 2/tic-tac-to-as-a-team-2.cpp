#include <iostream>
using namespace std;

int numbers[3][3];
int ans;
int main() {
    for(int i=0; i<3; i++){ 
        int number;
        cin >> number;
        numbers[i][0] = number/100;
        numbers[i][2] = number%10;
        numbers[i][1] = (number/10)%10;
        
    }
    
    for(int i=1; i<=9; i++){
        for(int j=i+1; j<=9; j++){
            // 가로
            int cnt = 0; 
            for(int k=0; k<3; k++){
                cnt = 0;
                for(int l=0; l<3; l++){
                    if(numbers[k][l] == i || numbers[k][l] == j){
                        // i나 j랑 같다면?
                        cnt++;
                    }
                }
                if(cnt == 3){
                    break;
                }
            }
            if(cnt == 3)    {
                ans++;
                break;
            }

            // 세로
            for(int k=0; k<3; k++){
                cnt = 0;
                for(int l=0; l<3; l++){
                    if(numbers[l][k] == i || numbers[l][k] == j){
                        // i나 j랑 같다면?
                        cnt++;
                    }
                }
                if(cnt == 3){
                    break;
                }
            }
            if(cnt == 3)    {
                ans++;
                break;
            }

            // 쪽 아래
            //(0,2),(1,1),(2,0)
            if((numbers[0][2] ==i || numbers[0][2] == j) &&(numbers[1][1] ==i || numbers[1][1] == j)&&(numbers[2][0] ==i || numbers[2][0] == j)){
                ans++;
                break;
            }
            // 오른쪽 아래
            // (0,0),(1,1),(2,2)
            if((numbers[0][0] ==i || numbers[0][0] == j) &&(numbers[1][1] ==i || numbers[1][1] == j)&&(numbers[2][2] ==i || numbers[2][2] == j)){
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}