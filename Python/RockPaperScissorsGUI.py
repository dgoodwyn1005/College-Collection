import tkinter as tk
import random

def determine_winner(comp:str, user:str)->int:
    winner = 0
    if user == "Rock" and comp == "Scissors":
        winner = 1
    elif user == "Paper" and comp == "Rock":
        winner = 1
    elif user == "Scissors" and comp == "Paper":
        winner = 1
    elif user == "Rock" and comp == "Paper":
        winner = -1
    elif user == "Paper" and comp == "Scissors":
        winner = -1
    elif user == "Scissors" and comp == "Rock":
        winner = -1
    return winner

def handle_click(choice:str):
    computer_choice = random.choice(["Rock", "Paper", "Scissors"])
    winner = determine_winner(computer_choice, choice)
    match winner:
        case 0:
            result["text"] = "{} - It was a tie!".format(computer_choice)
        case 1:
            result["text"] = "{} - Human Wins!".format(computer_choice)
        case -1:
            result["text"] = "{} - Computer wins.".format(computer_choice)

window = tk.Tk()
window.minsize(width = 400, height = 100)
window.maxsize(width = 400, height = 100)

var = tk.IntVar()

rock = tk.Radiobutton(text = "Rock", command = lambda: handle_click("Rock"), height = 2, width = 15, variable = var, value = 1)
paper = tk.Radiobutton(text = "Paper", command = lambda: handle_click("Paper"), height = 2, width = 15, variable = var, value = 2)
scissors = tk.Radiobutton(text = "Scissors", command = lambda: handle_click("Scissors"), height = 2, width = 15, variable = var, value = 3)
result = tk.Label(text = "Let's play a game!", height = 2, width = 20)

rock.grid(row = 0, column = 0, sticky = "news")
paper.grid(row = 0, column = 1, sticky = "news")
scissors.grid(row = 0, column = 2, sticky = "news")
result.grid(row = 1, column = 1)
window.mainloop()
