d = {"The Great Gaspy": "Scott Fitzgerald", "To Kill a Mockingbird": "Harper Lee",
     "Moby Dick": "Herman Melville", "Don Quixote": "Miguel de Cervantes",
     "Alice in Wonderland": "Lewis Carrol"}
title = input("What is the title of the book?")
if title in d:
    print("The author of", title, "is", d[title])
else:
    print("The title is not in the dictionary")