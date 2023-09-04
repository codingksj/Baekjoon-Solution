def find_page_to_print(max_p : int, 
                       print_ranges : list[str]) -> int:
    
    checks : list[bool] = [False] * (max_p + 1)
    
    for print_range in print_ranges:
        if print_range.find("-") != -1:
            low, high = map(int, print_range.split("-"))
            high = min(high, max_p)
            for page in range(low, high+1):
                checks[page] = True
        else:
            page = int(print_range)
            if 0 < page <= max_p:
                checks[page] = True
    
    count = checks.count(True)
    
    return count
    
while True:
    max_p = int(input())
    if max_p == 0:
        break
    print_ranges = list(input().split(","))
    pages = find_page_to_print(max_p, print_ranges)
    print(pages)