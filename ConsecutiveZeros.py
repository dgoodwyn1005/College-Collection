def consecutive_zeros(lyst):
    max_zeroes = 0
    current_zeroes = 0
    
    for i in binary_list:
        if i == 0:
            current_zeroes += 1
        else:
            if max_zeroes < current_zeroes:
                max_zeroes = current_zeroes
            current_zeroes = 0
    if max_zeroes < current_zeroes:
        max_zeroes = current_zeroes    
        
    return max_zeroes

def consecutive_zeros_mod(lyst):
    current_zeroes = 0
    zero_length_list = []
    
    for i in binary_list:
        if i == 0:
            current_zeroes += 1
        else:
            zero_length_list.append(current_zeroes)
            current_zeroes = 0 
    zero_length_list.append(current_zeroes)   
    return max(zero_length_list)

binary_list = [1,0,0,1,1,0,1,0,0,0,1,1,0]
max_z = consecutive_zeros_mod(binary_list)
print(max_z)