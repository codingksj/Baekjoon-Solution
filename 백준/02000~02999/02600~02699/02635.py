def find_longest_seq(n : int) -> list[int]:
    ans : list[int] = [n]
    
    for i in range(1, n+1):
        tmp : list[int] = [n, i]
        
        delta = tmp[-2]-tmp[-1]
        
        while tmp[-1] >= 0:
            delta = tmp[-2]-tmp[-1]
            tmp.append(delta)
            
        tmp.pop()
            
        if len(ans) < len(tmp):
            ans = tmp
            
    return ans
    
n = int(input())

result : list[int] = find_longest_seq(n)

print(len(result))
print(*result)