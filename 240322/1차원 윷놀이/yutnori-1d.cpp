#include <iostream>
#include <algorithm>

#define MAX_N 12
#define MAX_K 4

using namespace std;

int n, m, k;
int nums[MAX_N], pieces[MAX_K];

int ans;

// 점수를 계산합니다.
int Calc() {
	int score = 0;
	for(int i = 0; i < k; i++)
		score += (pieces[i] >= m);
    
	return score;
}

void FindMax(int cnt) {
    // 말을 직접 n번 움직이지 않아도
    // 최대가 될 수 있으므로 항상 답을 갱신합니다.
    ans = max(ans, Calc());
    
    // 더 이상 움직일 수 없으면 종료합니다.
	if(cnt == n) 
		return;
	
	for(int i = 0; i < k; i++) {
        // 움직여서 더 이득이 되지 않는
        // 말은 더 이상 움직이지 않습니다.
        if(pieces[i] >= m)
            continue;
        
		pieces[i] += nums[cnt];
		FindMax(cnt + 1);
		pieces[i] -= nums[cnt];
	}
}

int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	for(int i = 0; i < k; i++)
		pieces[i] = 1;
	
	FindMax(0);
	
	cout << ans;
	return 0;
}