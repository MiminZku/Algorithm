import sys
from queue import Queue

def main():    
    n, m, r = map(int, sys.stdin.readline().split())
    visited = [0 for i in range(n)]
    edges = [[] for i in range(n)]
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        edges[a-1].append(b)
        edges[b-1].append(a)

    visited[r-1] = 1
    visit_num = 2
    que = Queue()
    que.put(r)
    while que.qsize() != 0:
        u = que.get()
        navers = sorted(edges[u-1])
        for v in reversed(navers):
            if visited[v-1] == 0:
                visited[v-1] = visit_num
                visit_num += 1
                que.put(v)
    for i in visited:
        print(i)

if __name__ == "__main__":
    main()