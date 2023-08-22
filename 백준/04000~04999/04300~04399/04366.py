speed, before, distance = 0,0,0

while True:
    try:
        line = input().split()
        h, m, s = map(int, line[0].split(":"))
        now = h * 3600 + m * 60 + s
        distance += (now - before)/3600 * speed
        before = now
        
        if len(line) == 2:
            speed = int(line[1])
             
        else:
            print(f"{line[0]} {distance:.2f} km")
            
    except:
        break