# 입력:
n, g = tuple(map(int, input().split()))     # n: 사람 명수, g: 그룹 개수
people = [list(map(int, input().split())) for _ in range(g)]    # 그룹의 멤버들 입력받기
total_invited = set()

for sublist in people:
    sublist[1:] = sorted(sublist[1:])

people.sort(key=lambda x: (x[0], x[1]))

total_invited.add(1)

for group in people:
    total_cnt = group[0]
    invited_cnt = 0
    # 초대받은 인원수 확인
    for i in range(1, len(group)):
        if group[i] in total_invited:   # 만약 해당 번호를 가진 사람이 초대받았다면
            invited_cnt += 1            # 초대받은 명수 추가

    # 한번더 확인하면서 개수가 k-1인지 확인
    for i in range(1, len(group)):
        if group[i] not in total_invited:
            if invited_cnt == total_cnt-1:
                total_invited.add(group[i])
                invited_cnt += 1

print(len(total_invited))