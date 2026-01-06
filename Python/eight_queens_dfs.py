def expand_solution(partial_solution):
    possible_solutions = []
    for n in range(1, problem_size):
        if n not in partial_solution and check_diagonals(partial_solution + [n]):
            possible_solutions.append(partial_solution + [n])
    return possible_solutions

def check_diagonals(queens):
    for n in range(len(queens)):
        for m in range(n+1, len(queens)):
            if abs(queens[n] - queens[m]) == abs(n-m):
                return False
    return True

problem_size = 15
boundary = []
for n in range(1, problem_size+1):
    boundary.append([n])

partial_solution = []
while len(partial_solution) != problem_size:
    partial_solution = boundary.pop()
    if len(partial_solution) != problem_size:
        expanded_solutions = expand_solution(partial_solution)
        boundary = boundary + expanded_solutions

print(partial_solution)
