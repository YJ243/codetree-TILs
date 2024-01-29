n, m = map(int, input().split())

A = [input() for _ in range(n)]
B = [input() for _ in range(n)]

ans = 0

for i in range(m):
    for j in range(i+1, m):
        for k in range(j+1, m):
            setA = set()
            for l in range(n):
                setA.add(A[l][i]+A[l][j]+A[l][k])
            Same_Exist = False
            for l in range(n):
                tmp = B[l][i]+B[l][j]+B[l][k]
                if tmp in setA:
                    Same_Exist = True
            if not Same_Exist:
                ans += 1

print(ans)