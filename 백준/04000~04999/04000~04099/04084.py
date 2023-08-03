while True:
    conv = 0
    a,b,c,d = map(int,input().split())
    if a==0 and b==0 and c==0 and d==0:
        break
    else:
        while not (a==b and b==c and c==d):
            new_a, new_b, new_c, new_d = abs(a-b), abs(b-c), abs(c-d), abs(d-a)
            a,b,c,d = new_a, new_b, new_c, new_d
            conv = conv+1
        print(conv)
    
    