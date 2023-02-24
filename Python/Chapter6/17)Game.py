'''
Create a game to play rock,paper or scissor
'''
import random

list = ["ROCK","PAPER","SCISSOR"]

while True:
    randomValue = random.randint(0,len(list)-1)
    userInput = input('Enter Rock, Paper or scissor = ').upper().strip()
    computerInput = str(list[randomValue])

    print("Computer generated = "+computerInput)

    if userInput == computerInput:
        print("Close!!!\n")
        continue
    elif userInput == "ROCK":
        if computerInput == "PAPER":
            print("You lost!!!")
        else:
            print("You won!!!")
    elif userInput == "PAPER":
        if computerInput == "SCISSOR":
            print("You lost!!!")
        else:
            print("You won!!!")
    elif userInput == "SCISSOR":
        if computerInput == "ROCK":
            print("You lost!!!")
        else:
            print("You won!!!")
    else:
        print("Invalid input")
    
    print()