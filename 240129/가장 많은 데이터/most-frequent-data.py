n = int(input())
color_to_freq = dict()

max_cnt = 0
for _ in range(n):
    color = input()
    if color in color_to_freq:
        color_to_freq[color] += 1
    else:
        color_to_freq[color] = 1
    max_cnt = max(max_cnt, color_to_freq[color])

print(max_cnt)