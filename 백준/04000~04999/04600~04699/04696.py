while True:
    sum : float = 0

    n = input()
    if n == "0":
        break
    else:
        n = float(n)
        sum = 1 + n + pow(n,2) + pow(n,3) + pow(n,4)
        print(f"%.2f"%sum)
     