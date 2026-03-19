def count_paths(N, M):
    dp = [[0] * M for _ in range(N)]
    
    for i in range(N):
        for j in range(M):
            if i == 0 and j == 0:
                dp[i][j] = 1
            elif i == 0:
                dp[i][j] = dp[i][j-1]
            elif j == 0:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
    return dp[N-1][M-1]

N, M = map(int, input().split())
print(count_paths(N, M))