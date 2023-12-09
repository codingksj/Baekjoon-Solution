n = int(input())
count = 0

for i in range(n):
    day_left = int(input()[2:])
    if day_left <= 90:
        count += 1
        
print(count)



