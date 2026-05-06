import heapq

N = int(input())

price = [0] * (N + 1)
line = input().split()
for i in range(1, N + 1):
    price[i] = int(line[i - 1])

M = int(input())

g = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

INF = 10**18
dist = [INF] * (N + 1)
dist[1] = price[1]

heap = [(price[1], 1)]

while heap:
    cost, u = heapq.heappop(heap)
    
    if cost > dist[u]:
        continue
    
    for v in g[u]:
        if v == N:
            new_cost = cost
        else:
            new_cost = cost + price[v]
        
        if new_cost < dist[v]:
            dist[v] = new_cost
            heapq.heappush(heap, (new_cost, v))

if dist[N] == INF:
    print(-1)
else:
    print(dist[N])
