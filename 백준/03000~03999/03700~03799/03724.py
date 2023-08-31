def make_product_list(matrix : list[list[int]], c : int) -> list[int]:
    products = [1]*c
    
    for i in range(c):
        for row in matrix:
            products[i] *= row[i]
            
    return products
    
tc = int(input())

for _ in range(tc):
    c, r = map(int, input().split())
    matrix : list[list[int]]  = [list(map(int, input().split())) for _ in range(r)]
    products : list[int] = make_product_list(matrix, c)
    maxV = max(products)
    
    for i in range(c-1, -1, -1):
        if products[i] == maxV:
            print(i+1)
            break