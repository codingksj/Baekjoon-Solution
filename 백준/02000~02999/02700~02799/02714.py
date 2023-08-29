def decode_binary(binary: str, r: int, c: int) -> str:
    matrix = [binary[c * i:c * i + c] for i in range(r)]
    check = [[False] * (c + 1) for _ in range(r + 1)]
    i, j, cnt = 0, 0, 2
    check[i][j] = True
    decoded_binary = matrix[i][j]
    
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    dir = 0
    
    while cnt <= r * c:
        di, dj = directions[dir]
        
        if 0 <= i + di < r and 0 <= j + dj < c and not check[i + di][j + dj]:
            i += di
            j += dj
            check[i][j] = True
            cnt += 1
            decoded_binary += matrix[i][j]
        else:
            dir = (dir + 1) % 4
    
    indexes = [int(decoded_binary[5 * i:5 * i + 5], 2) for i in range(r * c // 5)]
    alpha = " ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    msg = "".join(alpha[index] for index in indexes).rstrip()
    
    return msg

tc = int(input())

for _ in range(tc):
    r, c, binary = input().split()
    r, c = int(r), int(c)
    
    msg = decode_binary(binary, r, c)
    
    print(msg)
