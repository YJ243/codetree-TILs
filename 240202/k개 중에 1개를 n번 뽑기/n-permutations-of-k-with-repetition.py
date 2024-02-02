k, n = map(int, input().split())    # 1이상 k이하, n번 반복

arr = []

def Print():
    for i in range(n):
        print(arr[i], end=' ')
    print()

def Choose(idx):    # idx번째 숫자를 선택하는 함수
    if idx == n:
        Print()
        return

    for i in range(1,k+1):
        arr.append(i)
        Choose(idx+1)
        arr.pop()

Choose(0)