import random

def check_constraints(queens):
    #check rows and columns first
    for n in range(len(queens)):
        for m in range(n+1, len(queens)):
            if queens[n][0] == queens[m][0] or queens[n][0] == queens[m][1]:
                return False           
            
            #check diagonals
            if abs(queens[n][0] - queens[m][0]) == abs(queens[n][1] - queens[m][1]):
                return False
    return True

found = False
while not found:
    queens = []

    #Generate list of 64 random #s
    possible_pos = list(range(1, 65))
    for n in range(8):
        k = random.randint(n, 63)
        possible_pos[n], possible_pos[k] = possible_pos[k], possible_pos[n]

    #Convert random # into grid coords (x, y)
    for num in possible_pos[:8]:
        row = (num-1) // 8 + 1
        col = (num-1) % 8 + 1
        queens.append((row, col))

    found = check_constraints(queens)

print(queens)