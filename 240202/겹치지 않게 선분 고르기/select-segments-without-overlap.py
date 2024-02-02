n = int(input())        # n개의 선분
lines = [list(map(int, input().split())) for _ in range(n)]

selected = []

# n개부터 2개까지 선택하면서 확인해보기
# 만약 중간에 겹치지 않게 골랐다면 break

def IsOverlapped():
    for i in range(len(selected)):
        for j in range(i+1, len(selected)):
            x1, y1 = selected[i]
            x2, y2 = selected[j]
            if (x1 <= x2 and x2 <= y1) or (x1 <= y2 and y2 <= y1):
                return False
    return True

def Choose(idx, total):     # 총 total개 선분을 고르는 함수, idx번째 고려
    if len(selected) == total:
        if IsOverlapped():
            print(total)
            exit(0)
        return

    for i in range(idx, n):
        selected.append(lines[i])
        Choose(i+1, total)
        selected.pop()

for i in range(n, 1, -1):
    # i개 고르기
    Choose(0, i)
print(1)