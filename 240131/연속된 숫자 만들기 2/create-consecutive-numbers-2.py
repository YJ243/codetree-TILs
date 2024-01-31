a, b, c = tuple(map(int, input().split()))

ans = 0
if abs(a-b) == 1 and abs(b-c) == 1:
    ans = 0
elif abs(a-b) == 1 or abs(b-c) == 1:
    ans = 1
elif abs(a-b) == 2 or abs(b-c ) == 2:
    ans = 1
else:
    ans = 2

print(ans)