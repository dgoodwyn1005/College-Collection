def alphabet_position(s: str) -> str:
    ''' returns a string of alphabet positions of letters in a parameter
    string '''
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    
    s = s.lower()
    for letter in s:
        if letter in alphabet:
            print(ord(letter) - ord('a') + 1, end = " ")
        
alphabet_position("Python Programming")


