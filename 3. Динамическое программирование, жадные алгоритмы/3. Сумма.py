def find_subset_sum(numbers, S):
    n = len(numbers)
    total_sum = sum(numbers)
    
    if S > total_sum:
        return None
    
    dp = {0: []}
    
    for i, num in enumerate(numbers):
        new_dp = dict(dp)
        
        for current_sum, indices in dp.items():
            new_sum = current_sum + num
            
            if new_sum == S:
                result_indices = indices + [i]
                return [numbers[idx] for idx in result_indices][::-1]
            
            if new_sum <= S and new_sum not in new_dp:
                new_dp[new_sum] = indices + [i]
        
        dp = new_dp
    
    return None

N = int(input())
numbers = list(map(int, input().split()))
S = int(input())

result = find_subset_sum(numbers, S)

if result is None:
    print(-1)
else:
    print(' '.join(map(str, result)))