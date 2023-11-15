import ipywidgets as widgets
from IPython.display import display, clear_output
import random

def clear_output_wrapper():
    # Clear output in Colab
    clear_output(wait=True)

def display_random_choice():
    choices = ['Rock', 'Paper', 'Scissors']
    choice = random.choice(choices)
    print(f"Computer's choice: {choice}")
    return choice

def play_game(user_choice):
    computer_choice = display_random_choice()

    if user_choice == computer_choice:
        return 'It\'s a tie!', 0
    elif (user_choice == 'Rock' and computer_choice == 'Scissors') or \
         (user_choice == 'Paper' and computer_choice == 'Rock') or \
         (user_choice == 'Scissors' and computer_choice == 'Paper'):
        return 'You win this round!', 1
    else:
        return 'Computer wins this round!', -1

def on_button_click(b):
    user_choice = b.description
    result, score_change = play_game(user_choice)
    global user_score, computer_score
    user_score += score_change
    clear_output_wrapper()
    print(result)
    print(f"Your choice: {user_choice}")
    print(f"Current Score: User: {user_score} | Computer: {computer_score}")
    if user_score >= num_rounds or computer_score >= num_rounds:
        print("Game Over!")

# Set up the game
num_rounds = 5
user_score = 0
computer_score = 0

# Create buttons for Rock, Paper, Scissors
rock_button = widgets.Button(description="Rock")
paper_button = widgets.Button(description="Paper")
scissors_button = widgets.Button(description="Scissors")

# Set up button click event handlers
rock_button.on_click(on_button_click)
paper_button.on_click(on_button_click)
scissors_button.on_click(on_button_click)

# Display buttons
display(rock_button, paper_button, scissors_button)

#---------------------------------------------------------------------------------------------------------------------------#
## Outputs:
# 1. Three Buttons displayed.
# 2. Any one button clicked
# 3. Message displayed as:
  # You win this round!
  # Your choice: Paper
  # Current Score: User: 1 | Computer: 0
