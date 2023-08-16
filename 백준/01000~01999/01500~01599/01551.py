n, k = map(int, input().split())
numbers = list(map(int, input().split(",")))

while k > 0:
    new_numbers = []
    k-=1
    for i in range(1, len(numbers)):
        delta = numbers[i] - numbers[i-1]
        new_numbers.append(delta)
        
    numbers = new_numbers

answer = ""

for number in numbers:
    answer+=f"{number},"
    
answer = answer.rstrip(",")
print(answer)
    