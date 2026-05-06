N = int(input())

d, v = map(int, input().split())

R = int(input())

edges = []
for _ in range(R):
    dep, time_dep, arr, time_arr = map(int, input().split())
    edges.append((dep, time_dep, arr, time_arr))

INF = 10**9
time = [INF] * (N + 1)
time[d] = 0

for _ in range(N * 100):
    updated = False
    for dep, time_dep, arr, time_arr in edges:
        if time[dep] <= time_dep and time_arr < time[arr]:
            time[arr] = time_arr
            updated = True
    if not updated:
        break

if time[v] == INF:
    print(-1)
else:
    print(time[v])