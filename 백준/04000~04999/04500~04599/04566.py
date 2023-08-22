import re

pattern = r'"([^"]*)" \1'

while True:
    sentence = input()
    if sentence == 'END':
        break
    
    if re.fullmatch(pattern, sentence):
        match = re.match(pattern, sentence)
        phrase = match.group(1)
        print(f'Quine({phrase})')
    else:
        print('not a quine')
