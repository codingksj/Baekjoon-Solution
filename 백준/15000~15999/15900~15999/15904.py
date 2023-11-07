import re

ignore = "[a-zA-Z ]"
pattern = re.compile(f'{ignore}*U{ignore}*C{ignore}*P{ignore}*C{ignore}*') 
string = input()
m = pattern.match(string)

print("I love UCPC" if m else "I hate UCPC")