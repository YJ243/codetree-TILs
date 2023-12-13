#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int arr[10];
pair<int, int> count[10];
int ans;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i] >> count[i].first >> count[i].second;
    }

    // 각 자리마다 1부터 9까지 늘려나가면서 
    for(int i=1; i <= 9; i++){
        for(int j=1; j<=9; j++){
            for(int k=1; k<=9; k++){
                // 현재 확인하는 숫자는 (ijk)
                //i = 1, j = 3; k = 2;
                if(i == j || j == k || k == i) continue;
                bool countable = true;
                for(int idx=0; idx < n; idx++){
                    // 각 n개의 숫자마다 사용할 자료구조
                    pair<int, int> cur_cnt = {0,0}; // first_cnt, second_cnt
                    
                    unordered_set<int> numbers;
                    numbers.insert(i);
                    numbers.insert(j);
                    numbers.insert(k);

                    // 이 idx는?
                    int a = arr[idx]/100, c = arr[idx]%10;
                    int b = ((arr[idx]-c)/10)%10;
                    if(a == i) cur_cnt.first++;
                    if(b == j) cur_cnt.first++;
                    if(c == k) cur_cnt.first++;
                    //cout << a << ' ' << b << ' ' << c << '\n';
                    // a,b,c가 그 자리에 있는지
                    // 하나, 두개 다 비교해보기
                    if(numbers.find(a) != numbers.end() && a != i) cur_cnt.second++;
                    if(numbers.find(b) != numbers.end() && b != j) cur_cnt.second++;
                    if(numbers.find(c) != numbers.end() && c != k) cur_cnt.second++;

                    if((cur_cnt.first != count[idx].first) || (cur_cnt.second != count[idx].second)){
                        // 둘 중 하나라도 다르다면
                        countable = false;
                        //cout<< i << ' ' << j << ' ' << k << '\n';


                    }
                }
                if(countable ) {
                    ans++;
                }
            //return 0;
            }
        }
    }
    cout << ans;
    return 0;
}