a, b, c, d = tuple(map(int, input().split()))
ans = (c*60+d) - (a*60+b)
print(ans)