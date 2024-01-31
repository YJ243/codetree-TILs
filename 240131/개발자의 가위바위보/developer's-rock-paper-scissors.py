n = int(input())
win_combination = [
    [[2,1],[3,2],[1,3]],
    [[3,1],[2,3],[1,2]],
    [[1,2],[3,1],[2,3]],
]

results = [list(map(int, input().split())) for _ in range(n)]

ans = 0
for win in win_combination: # 한 줄씩 보기
    # 이제 이 줄은 [2,1], [3,1], [1,3]임
    cur = 0
    for r in results:
        # 이제 [1,2],[2,2],[1,3],[1,1],[3,2] 볼꺼임
        a, b = r[0], r[1]
        for i in range(len(win)):
            if a == win[i][0] and b == win[i][1]:
                cur += 1
    
    ans = max(ans, cur)

print(ans)