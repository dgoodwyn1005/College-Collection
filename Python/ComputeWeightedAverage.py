def compute_weighted_average(grade_list:list, weight_list:list) -> float:
    '''computes the weighted average of grades given in grade_lsit and
    weights given by weight_list'''
    final_grade = 0
    for n in range(len(grade_list)):
        final_grade += grade_list[n]*weight_list[n]/sum(weight_list)
    return final_grade

print(compute_weighted_average([80, 95, 100], [20, 50, 30]))
    
