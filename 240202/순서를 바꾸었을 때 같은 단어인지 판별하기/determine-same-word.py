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