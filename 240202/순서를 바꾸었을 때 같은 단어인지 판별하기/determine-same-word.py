a = input()
b = input()
a = sorted(a)
b = sorted(b)

if len(a) != len(b):
    print("No")
    exit(0)

for i in range(len(a)):
    if a[i] != b[i]:
        print("No")
        exit(0)

print("Yes")

''' 해설 '''
'''
str1 = input()
str2 = input()

# 각 문자열을 정렬했을 때 두 문자열이 일치하는지 비교
print("Yes" if sorted(str1) == sorted(st2) else "No")
'''