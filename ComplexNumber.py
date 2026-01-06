class ComplexNumber(object):
    def __init__(self, real_part:float = 0., imaginary_part:float=0.):
        self.x = real_part
        self.y = imaginary_part
        
    def __str__(self):
        if self.y == 0:
            s = str(self.x)
        elif self.x == 0:
            s = "i" + str(self.y)
        elif self.y == 1:
            s = str(self.x) + " + i"
        elif self.y < 0:
            s = str(self.x) + " - i" + str(-self.y)
        else:
            s = str(self.x) + " + i" + str(self.y)
        return s
    
    def __add__(self,other):
        if type(other) == ComplexNumber:          
            x = self.x + other.x
            y = self.y + other.y
        elif type(other) == int or type(other) == float:
            x = self.x + other
            y = self.y
        return ComplexNumber(x,y)
    
    def __radd__(self,other):
        return self.__add__(other)
    
    def __sub__(self,other):
        if type(other) == ComplexNumber:
            x = self.x - other.x
            y = self.y - other.y
        elif type(other) == int or type(other) == float:
            x = self.x - other
            y = self.y
        return ComplexNumber(x,y)
    
    def __rsub__(self, other):
        z1 = (-1) * self
        return z1.__add__(other)
    
    def __mul__(self, other):
        if type(other) == ComplexNumber:
            x = self.x * other.x - self.y * other.y
            y = self.x * other.y + self.y * other.x
        elif type(other) == int or type(other) == float:
            x = self.x * other
            y = self.y * other
        return ComplexNumber(x,y)
    
    def __rmul__(self,other):
        return self.__mul__(other)
    
    def __truediv__(self, other):
        if type(other) == ComplexNumber:
            x = (self.x * other.x + self.y * other.y) / (other.x**2 + other.y**2)
            y = (self.y * other.x - self.x * other.y) / (other.x**2 + other.y**2)
        elif type(other) == int or type(other) == float:
            x = self.x / other
            y = self.y / other
        return ComplexNumber(x,y)
    
    def __rtruediv__(self, other):
        z1 = ComplexNumber(other, 0)
        return z1.__truediv__(self)
    
# print("testing with real part and imaginary part positive")
# z1 = ComplexNumber(2, 3)
# if (z1.__str__() == "2 + i3"):
#     print("Test 1 passed")
# else:
#     print("Test 1 failed")
    
# print("testing with real part 0 and imaginary part positive")
# z1 = ComplexNumber(0, 3)
# if (z1.__str__() == "i3"):
#     print("Test 2 passed")
# else:
#     print("Test 2 failed")
    
# print("testing with real part 0 and imaginary part 0")
# z1 = ComplexNumber(0, 0)
# if (z1.__str__() == "0"):
#     print("Test 3 passed")
# else:
#     print("Test 3 failed")

# print("testing with real part 0 and imaginary part negative")
# z1 = ComplexNumber(0, -3)
# if (z1.__str__() == "- i3"):
#     print("Test 4 passed")
# else:
#     print("Test 4 failed")
    
# print("testing with real part 0 and imaginary equal 1")
# z1 = ComplexNumber(0, 1)
# if (z1.__str__() == "i"):
#     print("Test 5 passed")
# else:
#     print("Test 5 failed")

# print("testing with real part positive and imaginary equal 1")
# z1 = ComplexNumber(2, 1)
# if (z1.__str__() == "2 + i"):
#     print("Test 6 passed")
# else:
#     print("Test 6 failed")
    
# print("testing with real part negative and imaginary equal 1")
# z1 = ComplexNumber(-2, 1)
# if (z1.__str__() == "-2 + i"):
#     print("Test 7 passed")
# else:
#     print("Test 7 failed")
    
# print("testing with real part positive and imaginary part 0")
# z1 = ComplexNumber(4, 0)
# if (z1.__str__() == "4"):
#     print("Test 8 passed")
# else:
#     print("Test 8 failed")

assert 3 > 10    