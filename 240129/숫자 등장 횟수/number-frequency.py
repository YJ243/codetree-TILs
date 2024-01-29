n, m = tuple(map(int, input().split()))
arr = list(map(int, input().split()))
num_to_index = dict()
for i, num in enumerate(arr):
    if num in num_to_index:
        num_to_index[num] += 1
    else:
        num_to_index[num] = 1

key_num = list(map(int, input().split()))
for num in key_num:
    if num in num_to_index:
        print(num_to_index[num], end=' ')
    else:
        print(0, end=' ')