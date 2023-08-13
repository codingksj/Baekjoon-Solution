def DecodeMessage(codes:list[str]):
    decodes = [codes[0][0]]
    prevL = len(codes[0])
    
    for code in codes[1:]:
        nowL = len(code)
        if nowL < prevL:
            decodes.append(" ")
        else:
            decode = code[prevL-1]
            decodes.append(decode)
        prevL = nowL
        
    decoded_message = "".join(decodes)
    print(decoded_message)

test = int(input())
code_message = input()

codes = code_message.split()

DecodeMessage(codes)
   