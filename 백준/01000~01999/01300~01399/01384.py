
group_num = 0   

while True:
    group_num += 1
    name, word = [], []
    n = int(input())
    
    if n == 0:  
        break
    
    for _ in range(n):
        line = input().split()  
        name.append(line[0]) 
        
        for i in range(1,n):
            word.append(line[i]) 
            
    print(f"Group {group_num}")
    
    size = n-1  
    nasty = False
    
    for i in range(len(word)):  
        if word[i] == 'N':  
            print(f"{name[size]} was nasty about {name[i//(n-1)]}")
            nasty = True
            
        size -= 1
        if size == -1:
            size = n-1
            
    if not nasty:   
        print("Nobody was nasty")
        
    print("")
