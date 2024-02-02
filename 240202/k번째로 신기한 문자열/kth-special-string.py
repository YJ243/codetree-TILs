n, k, T =  input().split()
n = int(n)
k = int(k)
arr = []

for _ in range(n):
    inp = input()
    if inp.startswith(T):
        arr.append(inp)

arr = sorted(arr)
print(arr[k-1])