def divisors(n = 2):
    lyst = []
    for k in range(2, n):
        if n % k == 0:
            lyst.append(k)
            
    if lyst:
        return lyst
    else:
        return str(n) + " is prime"

print(divisors(n = 12))
