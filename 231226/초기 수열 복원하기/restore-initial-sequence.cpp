/*
 * 2023.12.26
 * 수열의 초항이 정해진다면 나머지 항들은 자동으로 알 수 있음
 * => 수열의 초항을 찾아보는 완전탐색을 진행
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_N 1000

using namespace std;
int n;
int a[MAX_N];

int main() {
    // 입력:
    cin >> n;
    for(int i=0; i<n-1; i++)
        cin >> a[i];
    
    // 모든 1 ~ n이 등장하는 수열의 개수는 n!개입니다.
    // 이를 완전탐색하기 위해서는 1000!개의 수열을 알아보아야 하며,
    // 이는 아무리 컴퓨터라 해도 너무 많은 경우의 수를 세야 합니다.
    // 따라서 보다 효율적인 방법을 찾아야 합니다.

    // 잘 생각해 보면, 수열의 첫 번째 수만 결정한다면
    // 그 뒤의 숫자들은 자동으로 값이 하나로 결정된다는 것을 알 수 있습니다.
    // 따라서 수열의 첫 번째 수를 기준으로 모든 수열을 탐색해 볼 수 있습니다.
    for(int i=1; i<=n; i++){
        // i는 초항
        int tmp[n] = {};    // 현재 확인하려는 수열
        int last_idx = 0;   // 이전까지 보았던 마지막 인덱스
        tmp[last_idx] = i;  // 초항을 i로 만들기
        for(int j=0; j<n-1; j++){
            int new_num = abs(a[j]-tmp[last_idx]);
            tmp[++last_idx] = new_num;
            // 풀이에서는 tmp[j] = a[j-1]-arr[j-1] 으로 구함
        }

        int tmp2[n] = {};       // 현재까지 만든 배열을 잠시 복사해놓기
        for(int i=0; i<n; i++)
            tmp2[i] = tmp[i];
        sort(tmp, tmp+n);

        bool passed = true;
        for(int i=0; i<n; i++){
            // 정렬했는데 만약 1부터 n이 순서대로 나오지 않는다면 false
            if(tmp[i] != i+1) 
                passed = false;    
        }
        if(passed){
            for(int i=0; i<n; i++)
                cout << tmp2[i] << ' ';
            break;
        }
    }
    return 0;
}

/*
해설 풀이

#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n;
int a[MAX_N];
int arr[MAX_N];

int main() {
    // 입력:
    cin >> n;
    
    for(int i = 0; i < n - 1; i++)
        cin >> a[i];
    
    // 모든 1 ~ n이 등장하는 수열의 개수는 n!개입니다.
    // 이를 완전탐색하기 위해서는 1000!개의 수열을 알아보아야 하며,
    // 이는 아무리 컴퓨터라 해도 너무 많은 경우의 수를 세야 합니다.
    // 따라서 보다 효율적인 방법을 찾아야 합니다.

    // 잘 생각해 보면, 수열의 첫 번째 수만 결정한다면
    // 그 뒤의 숫자들은 자동으로 값이 하나로 결정된다는 것을 알 수 있습니다.
    // 따라서 수열의 첫 번째 수를 기준으로 모든 수열을 탐색해 볼 수 있습니다.
    for(int i = 1; i <= n; i++) {
        // 수열의 첫 번째 수가 i일 때
        arr[0] = i;
        
        for(int j = 1; j < n; j++) {
            // a[j - 1]는 arr[j] + arr[j - 1]의 값이기 때문에, 이 식을 잘 이용하면
            // arr[0]에서 arr[1]을, arr[1]에서 arr[2]를 차근차근 알 수 있습니다.
            arr[j] = a[j - 1] - arr[j - 1];
        }

        // arr수열에 1부터 n까지의 값이 한 번씩 이용되는지 확인합니다.
        // satisfied : arr수열에 1부터 n까지의 값이 한 번씩 이용될때 true
        // exist : 한 번이라도 해당 숫자가 arr수열에 존재했다면 true
        // 같은 숫자가 앞에 있었다면 exist배열을 확인했을 때 true가 나오게 됩니다.
        bool satisfied = true;
        bool exist[MAX_N + 1] = {};
        for(int j = 0; j < n; j++) {
            if(arr[j] <= 0 || arr[j] > n)
                satisfied = false;
            else {
                if(exist[arr[j]])
                    satisfied = false;
                exist[arr[j]] = true;
            }
        }

        if(satisfied) {
            for(int j = 0; j < n; j++)
                cout << arr[j] << " ";
            return 0;
        }
    }

}
*/