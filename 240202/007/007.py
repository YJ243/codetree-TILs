# 클래스 선언
class secret:
    def __init__(self, code, loc, time):
        self.code = code
        self.loc = loc
        self.time = time

# 변수 선언 및 입력
code, point, time =  input().split()

# 객체 생성
secrect1 = secret(code, point, time)

# 출력
print(f"secret code : {secrect1.code}")
print(f"meeting point : {secrect1.loc}")
print(f"time : {secrect1.time}")