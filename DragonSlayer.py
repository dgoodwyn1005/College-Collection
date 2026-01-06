class Dragon(object):
    #class variable to keep the number of dragon objects
    num_of_dragons = 0
    def __init__(self, name:str, strength:int):
        if Dragon.num_of_dragons >= 10:
            raise PermissionError
        self.name = name
        self.strength = strength
        Dragon.num_of_dragons += 1

    def __str__(self):
        s = "Dragon {} with strength {}".format(self.name, self.strength)
        s += "\nThe current number of dragons is " + str(Dragon.num_of_dragons)
        return s
    
    def __del__(self):
        Dragon.num_of_dragons -= 1
        print("Dragon killed")

    @classmethod
    def createDragon(cls, name, strength):
        if cls.num_of_dragons < 10:
            return cls(name, strength)
        else:
            print("Too many dragons")

dList = []
for n in range(12):
    d = Dragon.createDragon("dragon" + str(n+1), 10*n)
    print(d)
    if d:
        dList.append(d)
        
print(len(dList))

#del dlist[0]
#print(dragon.num_of_dragons)
# d1 = Dragon("dragon 1", 100)
# print(d1)
# d2 = Dragon("dragon 2", 50)
# print(d2)

# print(Dragon.num_of_dragons)
# del(d1)
# print(d2)
# print(Dragon.num_of_dragons)
# del(d2)