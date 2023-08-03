from math import pi
MILE = 5280
FEET = 12
HOUR = 3600

i = 1
while True:
    diameter, rotate, sec = map(float, input().split())
    if rotate == 0:
        break
    distance = diameter/(MILE*FEET)*pi*rotate
    mph = distance/sec*HOUR
    print("Trip #%d: %.2f %.2f" % (i, distance, mph))
    i += 1

            