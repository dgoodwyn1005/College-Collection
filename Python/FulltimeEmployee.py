from Employee import Employee

class FulltimeEmployee(Employee):
    def __init__(self, first_name, last_name, salary):
        super().__init__(first_name, last_name)
        self.salary = salary

    def get_salary(self):
        return self.salary

    def raisePay(self, percentageRaise):
        self.salary += self.salary * percentageRaise * 0.01
       

e1 = FulltimeEmployee("John", "Smith", 50000)
print(e1.get_salary())
print(e1.full_name)


