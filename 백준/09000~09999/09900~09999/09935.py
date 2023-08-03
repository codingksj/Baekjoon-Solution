def remove_bomb(string, bomb):
    string_list = list(string)
    bomb_length = len(bomb)
    stack = []

    for char in string_list:
        stack.append(char)
 
        if char == bomb[-1] and ''.join(stack[-bomb_length:]) == bomb:
            for _ in range(bomb_length):
                stack.pop()

    return ''.join(stack)

string = input()
bomb = input()
result = remove_bomb(string, bomb)

if not result:
    print("FRULA")
else:
    print(result)
