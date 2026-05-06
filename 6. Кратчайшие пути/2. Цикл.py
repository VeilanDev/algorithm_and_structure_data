N = int(input())

matrix = []
for _ in range(N):
    row = list(map(int, input().split()))
    matrix.append(row)

edges = []
for i in range(N):
    for j in range(N):
        if i != j and matrix[i][j] != 100000:
            edges.append((i, j, matrix[i][j]))

INF = 10**18
dist = [INF] * N
dist[0] = 0

for _ in range(N - 1):
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w

has_negative_cycle = False
for u, v, w in edges:
    if dist[u] + w < dist[v]:
        has_negative_cycle = True
        break

print("YES" if has_negative_cycle else "NO")