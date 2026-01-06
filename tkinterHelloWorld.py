import tkinter as tk

def handle_keypress(event):
    print("clicked")
window = tk.Tk()

greeting = tk.Button(text = "My first tkinter program", fg = "green", bg = "red")
greeting.bind("<Button-1>", handle_keypress)
greeting.pack()
window.mainloop()
