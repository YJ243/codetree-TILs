n = int(input())

x_to_min_y = dict()

for _ in range(n):
    x, y = map(int, input().split())
    if x not in x_to_min_y:
        x_to_min_y[x] = y
    else:
        if y < x_to_min_y[x]:
            x_to_min_y[x] = y

ans = 0
for key, value in x_to_min_y.items():
    ans += value
    
print(ans)