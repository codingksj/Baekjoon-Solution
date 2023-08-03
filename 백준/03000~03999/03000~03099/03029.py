HOUR = 3600
MIN = 60

h1, m1, s1 = map(int, input().split(':'))
h2, m2, s2 = map(int, input().split(':'))

t1 = h1*HOUR + m1*MIN + s1
t2 = h2*HOUR + m2*MIN + s2

t = t2 - t1 if t2>t1 else t2-t1+24*HOUR
h, m ,s = t//60//60, t//60 % 60, t%60
print("%02d:%02d:%02d" % (h, m, s))