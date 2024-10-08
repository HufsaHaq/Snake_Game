# Snake Game in C (ncurses)

## Overview
This project is a classic implementation of the Snake game using **C** and the **ncurses** library. The game offers an interactive and visually appealing terminal-based snake game where players control a snake to collect food, grow longer, and avoid collisions. The program is designed to be simple yet engaging, with various features like a dynamic scoreboard, color support, and increasing difficulty.

## Features
- **Dynamic Gameplay**: The snake's speed increases as the score goes up, making the game progressively challenging.
- **Responsive Controls**: Players can control the snake using the arrow keys for smooth and responsive movement.
- **Colorful Interface**: Utilizes **ncurses** colors to differentiate the snake, food, and scoreboard, enhancing the visual experience.
- **Pause Functionality**: Players can pause and resume the game by pressing `p`, providing control over gameplay.
- **Scoreboard**: A dynamic scoreboard at the top of the screen displays the current score and remaining hearts (lives).
- **Random Food Placement**: Food is randomly generated within the full playable area, ensuring it doesn't overlap with the snake.
- **Game Over Screen**: When the player loses, a game over screen appears with the option to restart or quit the game.
- **Screen Wrapping**: The snake wraps around the screen when it reaches the borders, with hearts (lives) decreasing when this happens.

## How to Play
1. **Controls**:
   - Use the arrow keys (`UP`, `DOWN`, `LEFT`, `RIGHT`) to move the snake.
   - Press `p` to pause or resume the game.
   - Press `ESC` to quit the game at any time.
2. **Objective**: 
   - Collect as much food (`*`) as possible to increase your score. Each food item collected increases the snake's length.
   - Avoid running into the snake's own body or exceeding the border limits, as this reduces your hearts (lives).
   - The game ends when you run out of hearts, and you have the option to retry or quit.

## Installation & Setup
To run the game, make sure you have the **ncurses** library installed. You can install it via:
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```
## Compile and Run

**Compile the program using cc:**
   ```bash
   cc -o snake_game.c -lncurses
   ./a.out
   ```
**Requirements**

  - GCC: Ensure you have GCC installed for compiling the program.
  - ncurses Library: The game relies on ncurses for handling terminal graphics and user input.

**Game Rules**
  - The snake starts at the center of the screen and moves in the initial direction set (right).
  - Food (*) appears randomly within the screen, and the snake grows longer when it collects food.
  - The game speed increases as the score increases, adding to the difficulty.
  - If the snake collides with itself or the boundaries, hearts decrease. If all hearts are lost, the game ends.

**Future Improvements**

- High Score Tracking: Save and display the highest score across game sessions.
- Multiple Levels: Implement different levels with unique obstacles and layouts.
- Additional Power-ups: Add various power-ups that grant temporary invincibility, double points, etc.
- Sound Effects: Incorporate simple sound effects for a more immersive experience.

