def upper_first_part(s = "", n = 0):
    return s[:n].upper() + s[n:].lower()

result = upper_first_part("PROGRAMMING", 5)
print(result)
result = upper_first_part("PROGRAMMING")
print(result)
result = upper_first_part(n = 2)
print(result)
