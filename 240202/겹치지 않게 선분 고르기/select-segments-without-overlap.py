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
            if (x1 <= x2 and x2 <= y1) or (x2 <= x1 and x1 <= y2):
                return True
    return False

def Choose(idx, total):     # 총 total개 선분을 고르는 함수, idx번째 고려
    if len(selected) == total:
        if not IsOverlapped():
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

''' 해설 '''
'''
# 변수 선언 및 입력:

n = int(input())
segments = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

ans = 0
selected_segs = list()

def overlapped(seg1, seg2):
    (ax1, ax2), (bx1, bx2) = seg1, seg2

    # 두 선분이 겹치는지 여부는
    # 한 점이 다른 선분에 포함되는 경우로 판단 가능
    return (ax1 <= bx1 and bx1 <= ax2) or (ax1 <= bx2 and bx2 <= ax2) or \
           (bx1 <= ax1 and ax1 <= bx2) or (bx1 <= ax2 and ax2 <= bx2)

def possible():
    # 단 한쌍이라도 선분끼리 겹치면 안됨
    for i, seg1 in enumerate(selected_segs):
        for j, seg2 in enumerate(selected_segs):
            if i < j and overlapped(seg1, seg2):
                return False
    return True

def find_max_segments(cnt):
    global ans

    if cnt == n:
        if possible():
            ans = max(ans, len(selected_segs))
        return
    
    selected_segs.append(segments[cnt])
    find_max_segments(cnt+1)
    selected_segs.pop()

    find_max_segments(cnt+1)

find_max_segments(0)
print(ans)
'''