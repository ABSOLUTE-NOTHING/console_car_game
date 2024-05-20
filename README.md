# console_car_game

This is a simple yet exciting car racing game developed in C++. The game provides a thrilling experience of dodging cars on a four-lane highway. The game is designed to run on a console and uses basic console functions to create a visually appealing interface.

## Features

- Four-lane highway for the car to move around.
- Randomly generated opponent cars that the player needs to dodge.
- Score tracking based on the number of cars successfully dodged.
- Simple and intuitive controls for moving the car left and right.

## How to Play

- Press 'A' or 'a' to move the car to the left.
- Press 'D' or 'd' to move the car to the right.
- The game ends when the player's car collides with another car.

## Code Structure

The code is structured into several functions, each responsible for a specific aspect of the game:

- `gotoxy(int x, int y)`: This function sets the cursor position in the specified console screen buffer.
- `loading()`: This function displays the loading screen of the game.
- `player_v()`: This function displays the player's vehicle on the screen.
- `erase_pv()`: This function erases the player's vehicle from the screen.
- `opp_v(int a[])`: This function displays the opponent's vehicle on the screen.
- `erase_ov(int a[])`: This function erases the opponent's vehicle from the screen.
- `accident()`: This function checks if the player's car has collided with another car.
- `gameover()`: This function displays the game over screen when the player's car collides with another car.
- `play()`: This function contains the main logic of the game.
- `main()`: This function is the entry point of the program.

## How to Run

To run the game, you need a C++ compiler. Compile the code and run the generated executable. The game will start in your console.

## Passion and Love for Trying Something New

Creating this game was a journey of exploration and learning. It was a thrilling experience to dive into the world of game development and see the game come to life from simple lines of code. The joy of seeing the car move around the screen, dodging other cars, was unparalleled. This project was a testament to the power of programming and its ability to create engaging experiences. It was a reminder of why I fell in love with coding in the first place - the ability to create something new and exciting from scratch. This game is just the beginning, and I look forward to creating more complex and engaging games in the future. Happy gaming!
