def get_common_letters_list(first:str, last:str) -> list[str]:
    L = []
    for letter in first:
        if letter in last and letter not in L:
            L.append(letter)
    return L

def get_common_letters_set(first:str, last:str) -> set:
    set1 = set(first)
    set2 = set(last)
    return set1 & set2

def get_symmetric_difference(first:str, last:str) -> set:
    set1 = set(first)
    set2 = set(last)
    return set1 ^ set2

s1 = "abcdefabcdef"
s2 = "abdeachr"
print(get_common_letters_list(s1,s2))
print(get_common_letters_set(s1,s2))
print(get_symmetric_difference(s1,s2))
