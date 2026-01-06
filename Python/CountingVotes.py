def determine_winner(vote_dict:dict, out_votes:int) -> list:
    m = max(vote_dict.values())
    pos_winners = []
    for cand in vote_dict:
        if (vote_dict[cand] + out_votes) > m:
            pos_winners.append(cand)
    return pos_winners

cur_votes = {'X':5, 'Y':8, 'Z':1, 'Q':4}
print(determine_winner(cur_votes, 4))
