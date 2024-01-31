import sys
INT_MAX = sys.maxsize

# 변수 선언 및 입력
a, b, x, y = tuple(map(int, input().split()))

ans = INT_MAX

# 1. a->b
ans = min(ans, abs(b-a))

# 2. a->x->y->b
ans = min(ans, abs(x-a) + abs(b-y))

# 3. a->y->x->b
ans = min(ans, abs(y-a) + abs(b-x))

print(ans)