import sys
sys.setrecursionlimit(20000)

def solve():
    N, M = map(int, input().split())
    
    g = [[] for _ in range(N + 1)]
    gt = [[] for _ in range(N + 1)]
    
    for _ in range(M):
        u, v = map(int, input().split())
        g[u].append(v)
        gt[v].append(u)
    
    visited = [False] * (N + 1)
    order = []
    
    def dfs1_iter(start):
        stack = [(start, 0)]
        while stack:
            u, state = stack.pop()
            if state == 0:
                if visited[u]:
                    continue
                visited[u] = True
                stack.append((u, 1))
                for v in g[u]:
                    if not visited[v]:
                        stack.append((v, 0))
            else:
                order.append(u)
    
    for i in range(1, N + 1):
        if not visited[i]:
            dfs1_iter(i)
    
    visited = [False] * (N + 1)
    components = 0
    
    def dfs2_iter(start):
        stack = [start]
        visited[start] = True
        while stack:
            u = stack.pop()
            for v in gt[u]:
                if not visited[v]:
                    visited[v] = True
                    stack.append(v)
    
    for u in reversed(order):
        if not visited[u]:
            components += 1
            dfs2_iter(u)
    
    print(components)


solve()