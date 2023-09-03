def find_safe_square(grid : list[list[int]], 
                     r : int,
                     c : int) -> int:
    max_size = min(r,c)
    count = 0
    
    for size in range(1, max_size + 1):  
        for i in range(r - size + 1):
            for j in range(c - size + 1):
                has_one = False
                
                for x in range(i, i + size):
                    for y in range(j, j + size):
                        if grid[x][y] == 1:
                            has_one = True
                
                if not has_one:
                    count += 1
    
    return count
        
tc : int = int(input())

for i in range(1, tc+1):
    r, c, monster = map(int, input().split())
    grid = [[0] * c for _ in range(r)]
    
    for j in range(monster):
        ri, ci = map(int, input().split())
        grid[ri][ci] = 1
        
    safe = find_safe_square(grid, r, c)
    print(f"Case #{i}: {safe}")

