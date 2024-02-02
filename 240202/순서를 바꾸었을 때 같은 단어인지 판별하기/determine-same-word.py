a = input()
b = input()
a = sorted(a)
b = sorted(b)
for i in range(len(a)):
    if a[i] != b[i]:
        print("No")
        exit()

print("Yes")