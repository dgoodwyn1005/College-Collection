top_file = open("toppings.txt", "r")
pepperoni_set = set()
mushroom_set = set()
cheese_set = set()
for line in top_file:
    line = line.strip()
    line_list = line.split(":")
    for topping in line_list[1:]:
        if topping == "pepperoni":
            pepperoni_set.add(line_list[0])
        elif topping == "mushrooms":
            mushroom_set.add(line_list[0])
        else:
            cheese_set.add(line_list[0])

#the names of people who like pepeproni
print("People who like pepperoni: ", pepperoni_set)
#the names of people who like all three toppings
print("People who like all three toppings: ", pepperoni_set & mushroom_set &
      cheese_set)
#the names of people who like pepperoni and mushrooms but not cheese
print("People who like pepperoni and mushroom but not cheese: ", (pepperoni_set &
      mushroom_set) - cheese_set)
#the names of people who like cheese but not pepperoni and not mushrooms
print("People who like cheese but not pepperoni and not mushrooms: ", (cheese_set -
      pepperoni_set) - mushroom_set)


top_file.close()
