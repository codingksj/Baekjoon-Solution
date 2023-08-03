n = input()
length = len(n)//2
left = n[:length]
right = n[length:]

sum_left = 0
sum_right = 0

for number in left:
    sum_left+=int(number)

for number in right:
    sum_right+=int(number)
    
if sum_left == sum_right:
    print("LUCKY")
else:
    print("READY")