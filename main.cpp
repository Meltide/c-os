#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

using namespace std;

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

int main(){
    string username;
    string passwd;
    string defpasswd = "114514";
    string version = "0.3";
    int count = 1;
    int space;
    system("clear");
    cout << "\nC-OS V" << version << endl;
    cout << "   ____       ___  ____  " << endl;
    cout << "  / ___|     / _ \\/ ___| " << endl;
    cout << " | |   _____| | | \\___ \\ " << endl;
    cout << " | |__|_____| |_| |___) |" << endl;
    cout << "  \\____|     \\___/|____/ \n" << endl;
    cout << "A fake system based on C++\n\nAuthor: MeltIce\nAuthor's QQ: 3480656548\nAuthor's Github: Meltide\n" << endl;
    cout << "View this project on github: github.com/Meltide/c-os\n" << endl;
    while (count == 1) {
        cout << "Login: ";
        getline(cin, username);
        if (username == "root") {
            cout << "Password: ";
            hideInput(true);
            getline(cin, passwd);
            if (passwd == defpasswd) {
                hideInput(false);
                cout << endl;
                while (count == 1) {
                    string input;
                    cout << "[root@localhost] ~ # ";
                    getline(cin, input);
                    if (input == "help") {
                        cout << "ls         View the path." << endl;
                        cout << "time       Get time and date." << endl;
                        cout << "version    Show the version of C-OS." << endl;
                        cout << "clear      Clean the screen." << endl;
                        cout << "exit       Log out." << endl;
                        cout << "shutdown   Shutdown the system." << endl;
                    }
                    else if (input == "time") {
                        time_t currentTime;
                        time(&currentTime);
                        cout << ctime(&currentTime);
                    }
                    else if (input == "ls") {
                        cout << "Documents  Music  Video  Downloads" << endl;
                    }
                    else if (input == "version") {
                        cout << "C-OS V" << version << endl;
                    }
                    else if (input == "clear") {
                        system("clear");
                    }
                    else if (input == "exit") {
                        break;
                    }
                    else if (input == "shutdown") {
                        system("clear");
                        count = 0;
                    }
                    else if (input == "") {
                        space = 0;
                    }
                    else {
                        cout << "Unknown command." << endl;
                    }
                }
            }
        }
        else {
            cout << "Wrong username." << endl;
        }
    }
    return 0;
}