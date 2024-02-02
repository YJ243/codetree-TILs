n = int(input())    # n자리 수

selected = []
ans = 0
def Verify():       # 아름다운 수인지 판별
    curIdx, curNum = 0, selected[0]     # 첫번째 수부터 확인
    while True:
        if curIdx >= n:     # 만약 현재 보고 있는 인덱스가 범위를 벗어나면 break
            break

        curNum = selected[curIdx]   # 현재 확인하려는 수

        for i in range(curIdx+1, curIdx+curNum):    # 해당 숫자만큼 연달아 같은 숫자가 나오는지 확인
            if i >= n or curNum != selected[i]:     # 확인 도중 범위를 벗어나거나, 다른 숫자가 나온다면
                return False                        # 아름다운 수가 아님
        curIdx += curNum        # 다음 인덱스 이동시키기
        
    return True


def Choose(idx):    # idx번째 수를 선택하는 함수
    global ans
    if idx == n:
        if Verify():
            ans += 1
        return

    for i in range(1, 5):
        selected.append(i)
        Choose(idx+1)
        selected.pop()

Choose(0)
print(ans)


''' 해설 풀이 '''
'''
# 변수 선언 및 입력:
n = int(input())
ans = 0
seq = list()

def is_beautiful():
    # 연달아 같은 숫자가 나오는 시작 위치를 잡기
    i = 0:
    while i < n:
        # 만약 연속하여 해당 숫자만큼 나올 수 없다면
        # 아름다운 수가 아님
        if i + seq[i] - 1 >= n:
            return False
        
        # 연속하여 해당 숫자만큼 같은 숫자가 있는지 확인
        # 하나라도 다른 숫자가 있다면 아름다운 수가 아님
        for j in range(i, i+seq[i]):
            if seq[j] != seq[i]:
                return False
        
        i += seq[i]

    return True

def count_beautiful_seq(cnt):
    global ans

    if cnt == n:
        if is_beautiful():
            ans += 1
        return
    
    for i in range(1,5):
        seq.append(i)
        count_beautiful_seq(cnt+1)
        seq.pop()
count_beautiful_seq(0)
print(ans)
'''