def capital_indexes(word):
    out_list = []
    
    for index in range(len(word)):
        if word[index].isupper():
            out_list.append(index)
    return out_list
            
s = "HeLlO"
out_list = capital_indexes(s)
print(out_list)