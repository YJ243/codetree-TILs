import heapq
class PriorityQueue:
    def __init__(self):
        self.items = []

    def push(self, item):
        heapq.heappush(self.items, -item)
    
    def pop(self):
        print(-self.items[0])
        heapq.heappop(self.items)
    
    def size(self):
        print(len(self.items))

    def empty(self):
        if not self.items:
            print(1)
        else:
            print(0)
    
    def top(self):
        print(-self.items[0])


pq = PriorityQueue()

n = int(input())
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