# About
Tic Tac Toe, also known as Noughts and Crosses, is a classic two-player game played on a 3x3 grid. The objective is to form a line of three of your symbols (either 'X' or 'O') horizontally, vertically, or diagonally before your opponent does.

# Game Rules:
    -The game is played on a 3x3 grid.
    -Two players take turns to place their symbol ('X' or 'O') on an empty cell.
    -The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins.
    -If the entire grid is filled without a winner, the game is a draw.

# Approach:
      1. Board Representation:
          -The game board is represented as a 3x3 matrix.
          -Empty cells are denoted by '0', 'X' for player 1, and 'O' for player 2.
  
      2. Player Moves:
          -Players take turns making moves.
          -During each turn, the current player selects an empty cell to place their symbol.
  
      3. Winning Condition:
          -A player wins if they have three of their symbols in a row.
          -Winning combinations can be horizontal, vertical, or diagonal.
  
      4. Draw Condition:
          -The game ends in a draw if the entire grid is filled without a winner.
  
      5. Game Flow:
          -The game alternates between players until there is a winner or a draw.
          -Players are prompted for their moves during their turns.
  
      6. Computer Move (Optional):
          -For single-player mode, a simple computer move logic can be implemented.
  
      7. End of Game:
          -The game announces the winner or declares a draw at the end.
          -Players have the option to restart the game.

# Implementation:
    -The code provides a text-based interface for players to input their moves.
    -Players alternate turns, and the game state is updated accordingly.
    -The game checks for a winner or a draw after each move.
