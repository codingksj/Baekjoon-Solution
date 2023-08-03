while True:
    count = 0
    string = input()
    if string == '#':
        break
    for letter in string:
        if letter in ['a','e','i','o','u'] or letter in ['A','E','I','O','U']:
            count = count+1
    print(count)