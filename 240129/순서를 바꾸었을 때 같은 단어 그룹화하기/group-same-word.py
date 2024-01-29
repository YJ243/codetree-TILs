n = int(input())

arr = [list(input()) for _ in range(n)]


ans = 0
for i in range(n):
    freq_first = dict()
    for k in arr[i]:
        if k not in freq_first:
            freq_first[k] = 1
        else:
            freq_first[k] += 1

    cur = 1
    first_list = [[key, value] for key, value in freq_first.items()]
    for j in range(i+1,n):
        freq_second = dict()
        for k in arr[j]:
            if k not in freq_second:
                freq_second[k] = 1
            else:
                freq_second[k] += 1
        IsSame = True
        for i in range(len(first_list)):
            if first_list[i][0] not in freq_second:
                IsSame = False
            elif first_list[i][1] != freq_second[first_list[i][0]]:
                IsSame = False
        if IsSame:
            cur += 1
    ans = max(ans, cur)

print(ans)