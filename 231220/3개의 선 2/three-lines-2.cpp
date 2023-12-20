#include <iostream>
#include <unordered_set>
#define MAX_N 20
using namespace std;
int n;
int x[MAX_N];
int y[MAX_N];
int ans;


int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    
    for(int i=0; i<=3; i++){
        // Step1. x축 혹은 y축에 평행한 직선 개수 정하기
        // i는 x=k, 즉 y축에 평행한 직선 개수
        int j=3-i;      // j는 y=k, 즉 x축에 평행한 직선의 개수

        // Step2. 평행한 직선의 좌표 정하기
        for(int x=0; x<=i; x++){
            for(int y=0; y<=j; y++){

            }
        }
        // Step3. 모든 좌표를 지날수 있는지 확인하기

    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                // i번,j번,k번째에서 x축 혹은 y축에 평행한 직선 만들기
                int x1=x[i], x2=x[j], x3=x[k];
                int y1=y[i], y2=y[j], y3=y[k];
                // (x,y) = (0,3), (1,2), (2,1), (3,0)
                bool y_flag = true, x_flag = true;
                // 1. (0,3)
                for(int y_idx=0; y_idx<n; y_idx++)
                    if(y[y_idx] == y1 || y[y_idx] == y2 || y[y_idx] == y3){
                        // 셋 중에 하나라도 있다면
                        y_flag = true;
                    }
                    else    y_flag = false;
                if(y_flag){
                    cout << 1;
                    return 0;
                }

                // 2. (3,0)
                for(int x_idx=0; x_idx<n; x_idx++)
                    if(x[x_idx] == x1 || x[x_idx] == x2 || x[x_idx] == x3){
                        // 셋 중에 하나라도 있다면
                        x_flag = true;
                    }
                    else    x_flag = false;
                if(x_flag){
                    cout << 1;
                    return 0;
                }

                // 3. (1,2)
                int x_dots[3]={x[i],x[j],x[k]};
                int y_dots[3]={y[i],y[j],y[k]};
                for(int x_idx=0; x_idx<3; x_idx++){
                    x1 = x_dots[x_idx];
                    for(int y_idx=0; y_idx<3; y_idx++){
                        for(int yy_idx = y_idx+1; yy_idx<3; yy_idx++){
                            y2 = y_dots[y_idx], y3 = y_dots[yy_idx];
                            int total_cnt = 0;
                            for(int a=0; a<n; a++){
                                if(x[a] == x1)  total_cnt++;
                            }
                            for(int a=0; a<n; a++){
                                if(y[a] == y2 || y[a] == y3)    total_cnt++;
                            }
                            if(total_cnt >=n)  {
                                cout << 1;
                                return 0;
                            }
                        }
                    }
                }


                // 4. (2,1)
                for(int y_idx=0; y_idx<3; y_idx++){
                    y1 = y_dots[y_idx];
                    for(int x_idx=0; x_idx<3; x_idx++){
                        for(int xx_idx = x_idx+1; xx_idx<3; xx_idx++){
                            x2 = x_dots[x_idx], x3 = x_dots[xx_idx];
                            int total_cnt = 0;
                            for(int a=0; a<n; a++){
                                if(y[a] == y1)  total_cnt++;
                            }
                            for(int a=0; a<n; a++){
                                if(x[a] == x2 || x[a] == x3)    total_cnt++;
                            }
                            if(total_cnt >=n)  {
                                cout << 1;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}