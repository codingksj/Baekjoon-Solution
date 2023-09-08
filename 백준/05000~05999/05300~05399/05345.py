def find_PLU_pattern(text : str) -> int:
    text = text.lower()
    length = len(text)
    u_index = 0
    count = 0
    
    for i in range(length):
        p_index = text.find('p',u_index)
        if p_index == -1:
            break
        l_index = text.find('l',p_index)
        if l_index == -1:
            break
        u_index = text.find('u',l_index)
        if u_index == -1:
            break
        count+=1
    
    return count
        
tc = int(input())

for _ in range(tc):
    line = input()
    count = find_PLU_pattern(line)
    print(count)