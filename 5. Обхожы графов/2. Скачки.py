import sys
sys.setrecursionlimit(10000)

def solve():
    N, K = map(int, input().split())

    g = [[] for _ in range(N + 1)]
    
    while True:
        line = input().strip()
        if not line:
            continue
        
        parts = list(map(int, line.split()))
        
        if len(parts) == 1 and parts[0] == 0:
            break
        
        X, Y = parts[0], parts[1]
        g[X].append(Y)
    
    visited = [False] * (N + 1)
    
    def dfs(u):
        visited[u] = True
        for v in g[u]:
            if not visited[v]:
                dfs(v)
    
    dfs(K)
    
    for i in range(1, N + 1):
        if i != K and not visited[i]:
            print("No")
            return
    
    print("Yes")


solve()