class Question(object):
    def __init__(self):
        self.text = ""
        self.answer = ""
    
    def setQuestion(self, questionText:str):
        self.text = questionText
        
    def setAnswer(self, answer:str):
        self.answer = answer
        
    def checkAnswer(self, studentAnswer:str):
        return self.answer.upper() == studentAnswer.upper()
    
    def display(self):
        print(self.text)
        
class ChoiceQuestion(Question):
    def __init__(self):
        super().__init__()
        self.choices = []
        
    def addChioce(self, choice:str, flag:bool):
        self.choices.append(choice)
        if flag:
            self.setAnswer(choice)

    def display(self):
        super().display()
        for choice in self.choices:
            print(choice)
        
        
q1 = ChoiceQuestion()
q1.setQuestion("Who is the current president of the US?")
q1.addChioce("Joe Biden", True)
q1.addChioce("Donald Trump", False)
q1.addChioce("George Washington", False)
q1.addChioce("Tom Cruise", False)
q1.display()
s_answer = input("What is your answer?: ")
print(q1.checkAnswer(s_answer))




