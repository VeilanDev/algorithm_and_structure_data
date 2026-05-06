from collections import deque

def solve():
    M, N = map(int, input().split())
    grid = [input().strip() for _ in range(M)]
    
    visited = [[False] * N for _ in range(M)]
    
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    def bfs(sr, sc):
        q = deque()
        q.append((sr, sc))
        visited[sr][sc] = True
        
        while q:
            r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < M and 0 <= nc < N:
                    if not visited[nr][nc] and grid[nr][nc] == '#':
                        visited[nr][nc] = True
                        q.append((nr, nc))
    
    components = 0
    for i in range(M):
        for j in range(N):
            if grid[i][j] == '#' and not visited[i][j]:
                components += 1
                bfs(i, j)
    
    print(components)

solve()