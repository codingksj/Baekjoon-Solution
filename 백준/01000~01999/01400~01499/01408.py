H = 3600
M = 60

h, m ,s = map(int, input().split(":"))
start_time = h*H+m*M+s

h, m ,s = map(int, input().split(":"))
mission_time = h*H+m*M+s

delta = mission_time - start_time

if delta < 0:
    delta += H*24
    
h = delta//H
m = delta%H//60
s = delta%60

print(f"{h:02d}:{m:02d}:{s:02d}")