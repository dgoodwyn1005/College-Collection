class FootballGame(object):
    def __init__(self, home_team:str, away_team:str):
        self.home_team = home_team
        self.away_team = away_team
        self.home_score = 0
        self.away_score = 0
        
    def __str__(self):
        s = self.home_team + ":" + str(self.home_score) + "\n"
        s += self.away_team + ":" + str(self.away_score) + "\n"
        return s
    
    def scoreTouchdown(self, team:str):
        if team == "home":
            self.home_score += 7
        else:
            self.away_score += 7
    
    def scoreFieldGoal(self, team:str):
        if team == "home":
            self.home_score += 3
        else:
            self.away_score += 3
            
    def getWinningTeam(self):
        if self.home_score > self.away_score:
            return self.home_team + " won!"
        elif self.home_score < self.away_score:
            return self.away_team + " won!"
        else:
            return "No Winning Team"
        
fg = FootballGame("Kansas City Chiefs", "San Francisco 49ers")
print(fg)
fg.scoreTouchdown("home")
print(fg)
fg.scoreFieldGoal("away")
print(fg)
fg.scoreTouchdown("away")
print(fg)
print(fg.getWinningTeam())
