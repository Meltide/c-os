 #ifndef HIDE_INPUT
#define HIDE_INPUT
#include <unistd.h>
#include <termios.h>
void hideInput(bool hide) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (hide) {
        tty.c_lflag &= ~ECHO;
    } else {
        tty.c_lflag |= ECHO;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
#endif
