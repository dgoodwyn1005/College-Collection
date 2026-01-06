def extend_path(path):
    new_path_list = []
    state = path[-1]
    #one smallbot goes
    new_state = (1-state[0], state[1], state[2], state[3])
    if new_state in legal_states and new_state not in path:
        new_path = path + [new_state]
        new_path_list.append(new_path)
    #two smallbots go
    if state[0] == state[1]:
        new_state = (1-state[0], 1-state[1], state[2], state[3])
        if new_state in legal_states and new_state not in path:
            new_path = path + [new_state]
            new_path_list.append(new_path)
    #tallbot 1 goes
    if state[0] == state[2]:
        new_state = (state[0], state[1], 1 - state[2], state[3])
        if new_state in legal_states and new_state not in path:
            new_path = path + [new_state]
            new_path_list.append(new_path)
    #tallbot 2 goes
    if state[0] == state[3]:
        new_state = (state[0], state[1], state[2], 1 - state[3])
        if new_state in legal_states and new_state not in path:
            new_path = path + [new_state]
            new_path_list.append(new_path)

    return new_path_list

legal_states = [(0,0,0,0), (1,0,0,0),(0,1,0,0), (1,1,0,0),
                (0,0,1,0),(0,0,0,1),(1,0,1,0),(1,0,0,1),(0,0,1,1),
                (1,1,0,1),(1,1,1,0),(1,1,1,1)]

start = (0,0,0,0)
goal = (1,1,1,1)
path = [start]
boundary = [path]
count = 0
while boundary:
    current_path = boundary.pop(0)
    if current_path[-1] == goal:
        break
    new_paths = extend_path(current_path)
    boundary = boundary + new_paths
    #boundary = new_paths + boundary
    count += 1

if boundary:
    print("solution:", current_path)
    print(count)
else:
    print("No solutions found")