def custom_mul(a:str, b:str):
    ans = 0
    for digit_a in a:
        for digit_b in b:
            ans += int(digit_a)*int(digit_b)
    return ans

a, b = input().split()
ans = custom_mul(a,b)
print(ans)