def determine_scale(notes: str):
    c, a = 0, 0
    bars = notes.split("|")
    for bar in bars:
        if bar[0] in "ADE":
            a+=1
        elif bar[0] in "CFG":
            c+=1

    if c>a:
        return "C-major"
    elif c<a:
        return "A-minor"
    else:
        if bar[-1][-1] in "CFG":
            return "C-major"
        else:
            return "A-minor"
                   
notes = input()
ans = determine_scale(notes)
print(ans)
        
    