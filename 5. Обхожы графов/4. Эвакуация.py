from collections import deque
import sys

def solve():
    line = sys.stdin.readline()
    while line.strip() == '':
        line = sys.stdin.readline()
    N = int(line.strip())
    
    line = sys.stdin.readline()
    while line.strip() == '':
        line = sys.stdin.readline()
    K = int(line.strip())
    
    line = sys.stdin.readline()
    while line.strip() == '':
        line = sys.stdin.readline()
    exits = list(map(int, line.split()))
    
    while len(exits) < K:
        line = sys.stdin.readline()
        while line.strip() == '':
            line = sys.stdin.readline()
        exits.extend(map(int, line.split()))
    
    line = sys.stdin.readline()
    while line.strip() == '':
        line = sys.stdin.readline()
    M = int(line.strip())
    
    g = [[] for _ in range(N + 1)]
    edges_read = 0
    while edges_read < M:
        line = sys.stdin.readline()
        while line.strip() == '':
            line = sys.stdin.readline()
        u, v = map(int, line.split())
        g[u].append(v)
        g[v].append(u)
        edges_read += 1
    
    dist = [-1] * (N + 1)
    q = deque()
    
    for ex in exits:
        dist[ex] = 0
        q.append(ex)
    
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    
    print(' '.join(str(dist[i]) for i in range(1, N + 1)))

solve()