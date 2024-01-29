n = int(input())
arr = [list(map(int, input().split())) for _ in range(4)]

freqAB = dict()
freqCD = dict()

for i in range(n):
    for j in range(n):
        if arr[0][i] + arr[1][j] not in freqAB:
            freqAB[arr[0][i]+arr[1][j]] = 1
        else:
            freqAB[arr[0][i]+arr[1][j]] += 1

        if arr[2][i]+arr[3][j] not in freqCD:
            freqCD[arr[2][i]+arr[3][j]] = 1
        else:
            freqCD[arr[2][i]+arr[3][j]] += 1
ans = 0

freqAB_arr = [[key, value] for key, value in freqAB.items()]

for i in range(len(freqAB_arr)):
    if -freqAB_arr[i][0] in freqCD:
        ans += freqCD[-freqAB_arr[i][0]] * freqAB[freqAB_arr[i][0]]

print(ans)