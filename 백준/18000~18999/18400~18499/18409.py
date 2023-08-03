n = int(input())
s = input()
count = 0
for letter in s:
    if letter in ['a','e','i','o','u']:
        count = count+1
print(count)