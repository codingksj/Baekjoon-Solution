n = int(input())

for i in range(n):
    target, copied = map(str, input().split())
    if copied in target:
        target = target.replace(copied, "*")
    print(len(target))
    
                
                
            
        