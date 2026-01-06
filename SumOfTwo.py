def sum_of_two(lyst:list[int], target:int) -> tuple[int]:
    for k in range(len(lyst)-1):
        for n in range(k+1, len(lyst)):
            if lyst[k]+lyst[n] == target:
                return (k,n)
    return (-1,-1)

def sum_of_two_dict(lyst:list[int], target:int) -> tuple[int]:
    sum_dict = {}
    for k in range(len(lyst)):
        if target - lyst[k] in sum_dict:
            return sum_dict[target - lyst[k]],k
        if lyst[k] not in sum_dict:
            sum_dict[lyst[k]] = k
    return (-1,-1)

L = [n for n in range(100001)]
print(sum_of_two_dict(L, 199999))