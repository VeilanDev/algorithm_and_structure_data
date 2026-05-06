import heapq

N, M, start, finish = map(int, input().split())

g = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, prob = input().split()
    u = int(u)
    v = int(v)
    prob = float(prob)
    g[u].append((v, prob))

dist = [0.0] * (N + 1)
dist[start] = 1.0
prev = [-1] * (N + 1)

heap = [(-1.0, start)]

while heap:
    neg_prob, u = heapq.heappop(heap)
    prob = -neg_prob
    
    if prob < dist[u] - 1e-12:
        continue
    
    for v, edge_prob in g[u]:
        new_prob = prob * edge_prob
        if new_prob > dist[v] + 1e-12:
            dist[v] = new_prob
            prev[v] = u
            heapq.heappush(heap, (-new_prob, v))

if dist[finish] == 0.0:
    print(-1)
else:
    path = []
    cur = finish
    while cur != -1:
        path.append(cur)
        cur = prev[cur]
    path.reverse()
    print(' '.join(map(str, path)))
    print(f"{dist[finish]:.4f}")