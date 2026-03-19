def count_rabbit_paths(K, N):
    dp = [0] * (N + 1)
    dp[0] = 1
    
    for i in range(1, N + 1):
        for jump in range(1, K + 1):
            if i - jump >= 0:
                dp[i] += dp[i - jump]
    
    return dp[N]

K, N = map(int, input().split())

print(count_rabbit_paths(K, N))