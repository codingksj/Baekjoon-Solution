HOUR = 3600
MINUTE = 60

h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))

time = (h2-h1)*HOUR + (m2-m1)*MINUTE + s2-s1
if time < 0 :
    time = time+24*HOUR
print(time)