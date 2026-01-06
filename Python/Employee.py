class Employee(object):
    def __init__(self, name:str, position:str, salary:float):
        self.name = name
        self.position = position
        self.salary = salary
        
    def __str__(self):
        s = ""
        s += "Employee name: " + self.name
        s += "\nEmployee position: " + self.position
        s += "\nEmployee monthly salary: " + str(self.salary)
        return s
    
    def computePaycheck(self)->float:
        return self.salary * 0.80

    def giveSalaryRaise(self):
        self.salary = self.salary * 1.05


class Manager(Employee):
    def __init__(self, name:str, position:str, salary:float, bonus:float):
        super().__init__(name, position, salary)
        self.bonus = bonus

    def __str__(self):
        s = super().__str__()
        s += "\nBonus: " + str(self.bonus)
        return s

    def computePaycheck(self) -> float:
        addon = self.bonus * 0.8
        return super().computePaycheck() + addon/12
                              
e1 = Employee("John Smith","Junior Programmer", 7000)
print(e1)
paycheck = e1.computePaycheck()
print("Here is your monthly paycheck:", paycheck)
e1.giveSalaryRaise()
print(e1)

e2 = Manager("Alice Lidell", "CFO", 10000, 2000)
print(e2)
paycheck = e2.computePaycheck()
print("Here is your monthly paycheck:", paycheck)
e2.giveSalaryRaise()
print(e2)
