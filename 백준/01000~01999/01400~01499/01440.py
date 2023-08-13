def check_valid_time(time:str):
    h,m,s = map(int,time.split(":"))

    if 0 < h <= 12 and 0 <= m < 60 and 0 <= s < 60:
        return True
    else:
        return False

available_times = []
times= []
h,m,s = input().split(":")

times.append(f"{h}:{m}:{s}")
times.append(f"{h}:{s}:{m}")
times.append(f"{m}:{h}:{s}")
times.append(f"{m}:{s}:{h}")
times.append(f"{s}:{m}:{h}")
times.append(f"{s}:{h}:{m}")

for time in times:
    if check_valid_time(time):
        available_times.append(time)
        
print(len(available_times))
        
        