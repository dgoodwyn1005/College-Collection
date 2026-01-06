import sys

def nim_sum(state):
    result = 0
    for pile in state:
        result = xor(result, pile)
    return result

def game_over(state):
    for pile in state:
        if pile != 0:
            return False
    return True

def get_possible_moves(state):
    #Moves will contatin pile #, # of stones removed, and final state
    moves = []
    for i in range(len(state)):
        for remove in range(1, state[i] + 1):
            new_state = list(state)
            new_state[i] -= remove
            moves.append((i, remove, tuple(new_state)))
    return moves

def minimax(state, maximizing):
    if game_over(state):
        if not maximizing:
            return (1, None)
        else:
            return (-1, None)
    
    if maximizing:
        maximum_eval = -float('inf') #Negative infinity
        best_move = None
        for move in get_possible_moves(state):
            (_, _, new_state) = move
            (eval, _) = minimax(new_state, False)
            if eval > maximum_eval:
                maximum_eval = eval
                best_move = move
        return maximum_eval, best_move
    else:
        minimum_eval = float('inf') #Positive infinity
        best_move = None
        for move in get_possible_moves(state):
            (_, _, new_state) = move
            (eval, _) = minimax(new_state, True)
            if eval < minimum_eval:
                minimum_eval = eval
                best_move = move
        return minimum_eval, best_move

def show_gameboard(state):
    for i, pile in enumerate(state):
        print(f"Pile {i + 1}: Stones - ({pile})")

def xor(a, b):
    result = 0
    power = 1
    while a > 0 or b > 0:
        a_bit = a % 2
        b_bit = b % 2
        xor_bit = (a_bit + b_bit) % 2  # XOR: 1 if bits differ, 0 if the same
        result += xor_bit * power
        a //= 2
        b //= 2
        power *= 2
    return result

def main():
    print("This is the Game of Nim!")
    
    # Initial setup (max 3 piles)
    piles = []
    for i in range(3):
        stones = int(input(f"Enter number of stones in pile {i + 1} (0 is acceptable): "))
        piles.append(stones)
    
    state = tuple(piles)
    #Player goes first
    player_turn = True

    while not game_over(state):
        print("\nGame Board - ")
        show_gameboard(state)

        if player_turn:
            while True:
                try:
                    pile = int(input("Choose a pile (1-3): ")) - 1
                    stones = int(input("# of Stones to remove: "))
                    if pile < 0 or pile >= 3 or stones < 1 or stones > state[pile]:
                        raise ValueError
                    state = list(state)
                    state[pile] -= stones
                    state = tuple(state)
                    break
                except ValueError:
                    print("Invalid option. Try again.")
        else:
            (_, move) = minimax(state, True)
            (pile, stones, new_state) = move
            print(f"Opponent removed {stones} stone(s) from pile # {pile + 1}.")
            state = new_state

        #Changes turn
        player_turn = not player_turn

    print("\nEnd Game - ")
    show_gameboard(state)
    if player_turn:
        print("Computer wins!")
    else:
        print("You win!")

if __name__ == "__main__":
    main()
