class Calendar(object):
    def __init__(self, day:int, month:int, year:int):
        self.day = day
        self.month = month
        self.year = year
    
    def __str__(self):
        s = "{:02d}/{:02d}/{:04d}".format(self.month, self.day, self.year)
        return s
    
    def __eq__(self, other):
        return self.day == other.day and self.month == other.month and self.year == other.year

    def __gt__(self, other):
        if self.year > other.year:
            return True
        elif self.year < other.year:
            return False
        else:
            if self.month > other.month:
                return True
            elif self.month < other.month:
                return False
            else:
                if self.day > other.day:
                    return True
                else:
                    return False
                
    def __ge__(self, other):
        return self.__gt__(other) or self.__eq__(other)
    
    def __lt__(self, other):
        return not self.__ge__(other)
    
    def __le__(self, other):
        return not self.__gt__(other)
    
    def __ne__(self, other):
        return not self.__eq__(other)
                
c1 = Calendar(1, 6, 2024)
c2 = Calendar(1, 6, 2024)
print(c1)
print(c2)
print(c1 != c2)
print(c1 == c2)

           
          




