#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;
int a, b, x, y;
int ans = INT_MAX;

int main() {
    cin >> a >> b >> x >> y;
    // case 1. a->b로 바로 가기
    ans = min(ans, abs(b-a));

    // case 2. a-> x -> y -> b
    ans = min(ans, abs(a-x) + abs(y-b));

    // case 3. a -> y -> x -> b
    ans = min(ans, abs(a-y) + abs(x-b));
    cout << ans;
    return 0;
}