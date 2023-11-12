#include <iostream>
#include <algorithm>
using namespace std;

int n = 5;
int arr[5][5] = {{1,0,0,0,0},
                 {0,1,0,0,0},
                 {0,1,1,0,1},
                 {0,0,0,1,0},
                 {0,0,0,0,0}};

int main(){
    int max_cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++)
            for(int k=0; k<n; k++)
                for(int l=0; l<n-1; l++)
                    max_cnt = max(max_cnt, arr[i][j] + arr[i][j+1] + arr[k][l] + arr[k][l+1]);
    cout << max_cnt;
}