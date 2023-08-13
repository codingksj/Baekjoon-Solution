expressions = []
n = int(input())
for _ in range(2*n-1):
    expressions.append(input())
expression = "".join(expressions).replace("/","//")
print(eval(expression))