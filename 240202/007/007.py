class secret:
    def __init__(self, code, loc, time):
        self.code = code
        self.loc = loc
        self.time = time

code, point, time =  input().split()

secrect1 = secret(code, point, time)
print("secret code :", secrect1.code)
print("meeting point :", secrect1.loc)
print("time :", secrect1.time)