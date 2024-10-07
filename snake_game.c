#include <curses.h>
#include <unistd.h>

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
    vec2 head = {0,0}; // {x,y}
    vec2 dir = {1,0};
    
    while(true) {
        int pressed = wgetch(win);
        //react to players input
        if (pressed == KEY_LEFT){
            dir.x = -1;
            dir.y = 0;            
        }
        if (pressed == KEY_RIGHT){
            dir.x = 1;
            dir.y = 0;            
        }
        if (pressed == KEY_UP){
            dir.x = 0;
            dir.y = 1;            
        }
        if (pressed == KEY_DOWN){
            dir.x = 0;
            dir.y = -1;            
        }
        if (pressed == '\e'){ //escape key
            break;            
        }

        head.x += dir.x;
        head.y += dir.y;

        // draw to the screen
        erase();
        mvaddch(head.y , head.x , '0');
        usleep(150000);

    }
    endwin();

    return 0;

}
