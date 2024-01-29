inp = list(input())
count = dict()

for e in inp:
    if e not in count:
        count[e] = 1
    else:
        count[e] += 1

ans = ""
for e in inp:
    if count[e] == 1:
        ans += e
        break

if ans == "":
    ans = "None"
print(ans)