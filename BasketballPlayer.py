class BasketballPlayer(object):
    def __init__(self, name:str, team:str, position:str):
        self.name = name
        self.team = team
        self.position = position
    
    def __str__(self):
        s = "Player's name: " + self.name
        s += "\nPlayer's team: " + self.team
        s += "\nPlayer's position: " + self.position
        return s
    
#create a BasketballPlayer object
bbp = BasketballPlayer("Michael Jordan", "Chicago Bulls", "Shooting Guard")
print(bbp)