def to_camel_case(s:str) -> str:
    '''converts string from snake case into camel case'''
    mod_s = ""
    n = 0
    while n < len(s):
        if s[n] == "_" or s[n] == "-":
            mod_s += s[n+1].upper()
            n += 1
        else:
            mod_s += s[n]
        n += 1
    return mod_s

print(to_camel_case("the-stealth-warrior"))
print(to_camel_case("The_Stealth_Warrior"))
print(to_camel_case("The_Stealth-Warrior"))
