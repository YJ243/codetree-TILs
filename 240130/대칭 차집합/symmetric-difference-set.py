cntA, cntB = tuple(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

setA = set()
for cur in A:
    setA.add(cur)

Overlapped = 0
for cur in B:
    if cur in setA:
        Overlapped += 1

print(cntA-Overlapped + cntB-Overlapped)