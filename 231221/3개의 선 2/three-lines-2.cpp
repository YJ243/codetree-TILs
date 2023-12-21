#include <iostream>
#define MAX_N 20
#define MAX_XY 10

using namespace std;
int n;
int x[MAX_N];
int y[MAX_N];
int ans;
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    for(int i=0; i<=MAX_XY; i++){
        for(int j=0; j<=MAX_XY; j++){
            for(int k=0; k<=MAX_XY; k++){
                // i,j,k가 각각 x축 혹은 y축에 평행한 직선의 좌표가 됨
                // (x,y) == (0,3)
                bool isPassed = true;
                for(int a=0; a<n; a++){
                    if(y[a] == i || y[a] == j || y[a] == k)
                        continue;
                    isPassed = false;
                }
                if(isPassed)
                    ans = 1;

                // (x,y) == (3,0)
                isPassed = true;
                for(int a=0; a<n; a++){
                    if(x[a] == i || x[a] == j || x[a] == k)
                        continue;
                    isPassed = false;
                }
                if(isPassed)
                    ans = 1;


                // (x,y) == (1,2)
                isPassed = true;
                for(int a=0; a<n; a++){
                    if(x[a] == i || y[a] == j || y[a] == k)
                        continue;
                    isPassed = false;
                }
                if(isPassed)
                    ans = 1;
                
                
                // (x,y) == (2,1)
                isPassed = true;
                for(int a=0; a<n; a++){
                    if(x[a] == i || x[a] == j || y[a] == k)
                        continue;
                    isPassed = false;
                }
                if(isPassed)
                    ans = 1;
            }
        }
    }
    cout << ans;
    return 0;
}