#include <curses.h>

typedef struct {
    int x;
    int y;
} vec2;

int main() {
    int screen_width = 40;
    int screen_height = 20;

    // initialise screen
    WINDOW *win = initscr();

    //take player input
    keypad(win,true);
    nodelay(win,true); // non blocking , program doesnt wait for input just keeps running

    curs_set(0); // hides the curser

    //snake
    vec2 head = {0,0};
    vec2 dir = {1,0};
    

    return 0;

}
