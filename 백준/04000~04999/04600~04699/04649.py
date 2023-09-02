def check_tanning(bed : int, customers : str) -> str:
    queue : dict = {}
    cnt : int = 0
    
    for customer in customers:
        if customer not in queue.keys():
            if len(queue) >= bed:
                cnt += 1
            else:
                queue[customer] = 1
        else:
            del queue[customer]
            
    return cnt//2
    

while True:
    line = input()
    if line == "0":
        break
    bed, customers = line.split()
    bed = int(bed)
    
    cnt = check_tanning(bed, customers)
    
    if cnt:
        print(f"{cnt} customer(s) walked away.")
    else:
        print("All customers tanned successfully.")
    
    