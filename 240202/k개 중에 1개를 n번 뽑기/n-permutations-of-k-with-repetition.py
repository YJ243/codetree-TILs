# 변수 선언 및 입력
k, n = map(int, input().split())    # 1이상 k이하, n번 반복
arr = []

# 선택된 원소들을 출력해줌
def Print():
    for i in range(n):
        print(arr[i], end=' ')
    print()

def Choose(idx):    # idx번째 숫자를 선택하는 함수
    # n개를 모두 뽑은 경우 답을 출력
    if idx == n:
        Print()
        return
    # 1부터 k까지의 각 숫자가 뽑혔을 때의 경우를 탐색
    for i in range(1,k+1):
        arr.append(i)
        Choose(idx+1)
        arr.pop()

Choose(0)