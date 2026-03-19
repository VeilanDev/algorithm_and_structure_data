def solve_clowns_buttons(n):
    total = n * (n + 1) // 2
    
    if total % 3 != 0:
        print("NO")
        return
    
    target = total // 3
    
    numbers = list(range(1, n + 1))
    groups = [[], [], []]
    
    used = [False] * (n + 1)
    
    for group_idx in range(3):
        current_sum = 0
        for num in range(n, 0, -1):
            if not used[num] and current_sum + num <= target:
                groups[group_idx].append(num)
                used[num] = True
                current_sum += num
                if current_sum == target:
                    break
        
        if current_sum != target:
            print("NO")
            return
    
    if all(used[1:]):
        for group in groups:
            print(' '.join(map(str, sorted(group))))
    else:
        print("NO")

n = int(input())
solve_clowns_buttons(n)