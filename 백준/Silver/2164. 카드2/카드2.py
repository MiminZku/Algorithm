from queue import Queue

n = int(input())
q = Queue()
for i in range(n):
    q.put(i+1)
    
while n > 1:
    q.get()
    q.put(q.get())
    n -= 1
print(q.get())