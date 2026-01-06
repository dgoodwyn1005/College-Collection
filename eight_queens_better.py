import random
def check_diagonals(queens):
    for n in range(len(queens)):
        for m in range(n+1, len(queens)):
            if abs(queens[n] - queens[m]) == abs(n-m):
                return False
    return True

found = False
problem_size = 10
while not found:
    queens = list(range(1, problem_size+1))
    for n in range(len(queens)-1):
        pos = random.randint(n, len(queens)-1)
        queens[n], queens[pos] = queens[pos], queens[n]
    found = not check_diagonals(queens)

print(queens)