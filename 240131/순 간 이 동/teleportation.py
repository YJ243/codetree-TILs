a, b, x, y = tuple(map(int, input().split()))

ans = 10000000

# 1. a->b
ans = min(ans, abs(b-a))

# 2. a->x->y->b
ans = min(ans, abs(x-a) + abs(b-y))

# 3. a->y->x->b
ans = min(ans, abs(y-a) + abs(b-x))

print(ans)