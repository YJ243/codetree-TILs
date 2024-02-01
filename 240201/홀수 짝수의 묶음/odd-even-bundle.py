n = int(input())
arr = list(map(int, input().split()))
odd = 0     # 홀수
even = 0    # 짝수

for num in arr:
    if num % 2 == 0:
        even += 1
    else:
        odd += 1

# 일단 짝수를 먼저 없애놓기
ans = 0
if odd > even:
    # 가능한 입력 중에서 짝수가 홀수보다 많거나 같을 경우
    ans += even*2 # 그 짝수 개수만큼 답 증가(짝/홀/짝/홀...이렇게 짝수 개수만큼 뽑기)
    # 그럼 이제 홀수는 총 개수-짝수개만큼 남음
    odd -= even
    if odd > 0:

        # 이제 계산 시작, 홀수가 odd개인 배열에서 적당히 묶어서 짝/홀/짝/홀 번갈아 나오도록 하기!
        tmp = [0 for _ in range(odd)]     # 0: 묶어서 짝수, 1: 묶어서 홀수
        for i in range(odd):
            if i % 3 == 2:
                tmp[i] = 1

        if tmp[odd-1] == 1 and tmp[odd-2] == 1:
            ans += 1
            odd = odd-4
            ans += (odd // 3)*2
        else:
            if tmp[odd-1] == 1 and odd[odd-2] == 0:
                odd += 2
                odd = odd-3
                ans += (odd//3)*2
            elif tmp[odd-1] == 0:

                ans += 1
                odd = odd-2
                ans += (odd // 3 )*2
else:
    if odd == even:
        ans = odd*2
    else:
        ans = odd*2+1
print(ans)