n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr1.sort()
arr2.sort()
for i in range(n):
    if arr1[i] != arr2[i]:
        print("No")
        exit(0)
print("Yes")

''' 해설 '''
'''
# 변수 선언 및 입력
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

def equal():
    # n개의 원소를 순선대로 봤을 때
    # 전부 동일한 경우에만 일치함
    # 단 하나라도 다르다면, false
    for elem1, elem2 in zip(a,b):
        if elem1 != elem2:
            return False
    return True

# 정렬
a.sort()
b.sort()

# 수열이 일치하는지 확인합니다.
if equal():
    print("Yes")
else:
    print("No")
'''