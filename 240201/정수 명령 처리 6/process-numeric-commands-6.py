import heapq

class PriorityQueue:        
    def __init__(self):         # 빈 Priority Queue 하나를 생성
        self.items = []

    def push(self, item):       # 우선순위 큐에 데이터를 추가
        heapq.heappush(self.items, -item)
    
    def pop(self):              # 우선순위 큐에 있는 데이터 중 최댓값에 해당하는 데이터를 반환하고 제거
        print(-self.items[0])
        heapq.heappop(self.items)
    
    def size(self):             # 우선순위 큐에 있는 데이터 수를 반환
        print(len(self.items))

    def empty(self):            # 우선순위 큐가 비어있으면 True를 반환
        if not self.items:
            print(1)
        else:
            print(0)
    
    def top(self):              # 우선순위 큐에 있는 데이터 중 최댓값에 해당하는 데이터를 제거하지 않고 반환 
        print(-self.items[0])


# 변수 선언 및 입력
n = int(input())
pq = PriorityQueue()
for _ in range(n):
    cmd = input().split()

    if cmd[0] == "push":
        pq.push(int(cmd[1]))

    elif cmd[0] == "pop":
        pq.pop()

    elif cmd[0] == "size":
        pq.size()

    elif cmd[0] == "empty":
        pq.empty()

    else:
        pq.top()

''' 해설 '''
'''
import heapq

class PriorityQueue:
    def __init__(self):          # 빈 Priority Queue 하나를 생성합니다.
        self.items = []
                
    def push(self, item):        # 우선순위 큐에 데이터를 추가합니다.
        heapq.heappush(self.items, -item)
                
    def empty(self):             # 우선순위 큐가 비어있으면 True를 반환합니다.
        return not self.items
                
    def size(self):              # 우선순위 큐에 있는 데이터 수를 반환합니다.
        return len(self.items)
        
    def pop(self):               # 우선순위 큐에 있는 데이터 중 최댓값에 해당하는 데이터를 반환하고 제거합니다.
        if self.empty():
            raise Exception("PriorityQueue is empty")
            
        return -heapq.heappop(self.items)
                
    def top(self):               # 우선순위 큐에 있는 데이터 중 최댓값에 해당하는 데이터를 제거하지 않고 반환합니다.
        if self.empty():
            raise Exception("PriorityQueue is empty")
                        
        return -self.items[0]


# 변수 선언 및 입력:
n = int(input())
pq = PriorityQueue()

for _ in range(n):
    command = input()
    if command.startswith("push"):
        x = int(command.split()[1])
        pq.push(x)
    elif command == "pop":
        print(pq.pop())
    elif command == "size":
        print(pq.size())
    elif command == "empty":
        print(1 if pq.empty() else 0)
    else:
        print(pq.top())
'''