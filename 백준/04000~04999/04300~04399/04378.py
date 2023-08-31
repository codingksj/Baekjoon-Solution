def fix_error(err_msg : str) -> str:
    possible_errors = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./* "
    ans = []
    for ch in err_msg: 
        index = possible_errors.find(ch)
        ans.append(possible_errors[index-1])

    ans = "".join(ans).replace('*',' ')
    
    return ans

while True:
    try:
        err_msg = input()
        fixed_msg = fix_error(err_msg)

        print(fixed_msg)
    except:
        break

        