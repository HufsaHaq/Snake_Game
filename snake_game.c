#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} vec2;

#define MAX_SNAKE_LENGTH 100

void generate_food(vec2 *food, vec2 snake[], int snake_length, int screen_width, int screen_height) {
    int valid_position = 0;
    while (!valid_position) {
        // Generate food within the playable area (not on borders)
        food->x = (rand() % (screen_width - 2)) + 1;
        food->y = (rand() % (screen_height - 3)) + 2;

        // Check if the food position overlaps with any part of the snake
        valid_position = 1; // Assume position is valid
        for (int i = 0; i < snake_length; i++) {
            if (snake[i].x == food->x && snake[i].y == food->y) {
                valid_position = 0; // Invalid if overlapping
                break;
            }
        }
    }
}

void draw_scoreboard(int score, int hearts, int screen_width) {
    mvprintw(0, 1, "Score: %d  Hearts: %d", score, hearts);
}

int main() {
    int screen_width = 40;
    int screen_height = 20;

    // Initialise screen
    WINDOW *win = initscr();
    keypad(win, true);
    nodelay(win, true);
    curs_set(0);
    srand(time(NULL));

    // Snake setup
    vec2 snake[MAX_SNAKE_LENGTH];
    int snake_length = 1;
    snake[0] = (vec2){screen_width / 2, screen_height / 2}; // Start in the middle
    vec2 dir = {1, 0}; // Initial direction: right

    // Food setup
    vec2 food;
    generate_food(&food, snake, snake_length, screen_width, screen_height);

    // Game state
    int hearts = 3;
    int score = 0;

    while (true) {
        int pressed = wgetch(win);

        // React to player's input
        if (pressed == KEY_LEFT && dir.x == 0) {
            dir.x = -1;
            dir.y = 0;            
        } else if (pressed == KEY_RIGHT && dir.x == 0) {
            dir.x = 1;
            dir.y = 0;            
        } else if (pressed == KEY_UP && dir.y == 0) {
            dir.x = 0;
            dir.y = -1;            
        } else if (pressed == KEY_DOWN && dir.y == 0) {
            dir.x = 0;
            dir.y = 1;            
        } else if (pressed == 27) { // Escape key (27 is ESC)
            break;
        }

        // Update snake's position
        vec2 new_head = {snake[0].x + dir.x, snake[0].y + dir.y};

        // Check collisions with the screen boundaries
        if (new_head.x <= 0) {
            new_head.x = screen_width - 2;
            hearts--;
        } else if (new_head.x >= screen_width - 1) {
            new_head.x = 1;
            hearts--;
        } else if (new_head.y <= 1) { // The top line is reserved for the border
            new_head.y = screen_height - 2;
            hearts--;
        } else if (new_head.y >= screen_height - 1) {
            new_head.y = 2;
            hearts--;
        }

        // If no hearts left, game over
        if (hearts <= 0) {
            break;
        }

        // Check collision with itself
        int collided = 0;
        for (int i = 1; i < snake_length; i++) {
            if (snake[i].x == new_head.x && snake[i].y == new_head.y) {
                hearts--;
                collided = 1;
                break;
            }
        }

        // If collided with itself and no hearts left, break
        if (collided && hearts <= 0) {
            break;
        }

        // Update snake body only if no collision with itself
        if (!collided) {
            for (int i = snake_length; i > 0; i--) {
                snake[i] = snake[i - 1];
            }
            snake[0] = new_head;
        }

        // Check if snake eats the food
        if (new_head.x == food.x && new_head.y == food.y) {
            if (snake_length < MAX_SNAKE_LENGTH) {
                snake_length++;
            }
            score++;
            generate_food(&food, snake, snake_length, screen_width, screen_height);
        }

        // Draw to the screen
        erase();
        box(win, 0, 0); // Draw the border
        draw_scoreboard(score, hearts, screen_width);
        mvaddch(food.y, food.x, '*');
        for (int i = 0; i < snake_length; i++) {
            mvaddch(snake[i].y, snake[i].x, 'O');
        }
        refresh();
        usleep(150000);
    }

    // Game over message
    mvprintw(screen_height / 2, (screen_width / 2) - 5, "GAME OVER");
    refresh();
    sleep(2);

    endwin();
    return 0;
}
