#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(){
    char username[256];
    char passwd[256];
    char defpasswd[] = "114514";
    int count = 1;
    int space;
    system("clear");
    printf("\nC-OS V0.1\n\n");
    while(count == 1){
        printf("Login: ");
        scanf("%s", &username);
        if(0 == strcmp(username, "root")){
            while(count == 1){
                printf("Password: ");
                scanf("%s", &passwd);
                if(0 == strcmp(passwd, defpasswd)){
                    printf("\n");
                    while(count == 1){
                        char input[256];
                        printf("~ $ ");
                        scanf("%s", &input);
                        if(0 == strcmp(input, "help")){
                            printf("ls         View the path.\n");
                            printf("time       Get time and date.\n");
                            printf("version    Show the version of C-OS.\n");
                            printf("clear      Clean the screen.\n");
                            printf("exit       Log out.\n");
                            printf("shutdown   Shutdown the system.\n");
                        }
                        else if(0 == strcmp(input, "time")){
                            time_t currentTime;
                            time(&currentTime);
                            printf("%s", ctime(&currentTime));
                        }
                        else if(0 == strcmp(input, "calc")){
                            char operator;
                            float firstNumber,secondNumber;
                            printf("Input (+, -, *, /): ");
                            scanf("%c", &operator);
                            printf("\n");
                            printf("Input two numbers: ");
                            scanf("%f %f", &firstNumber, &secondNumber);
                            switch(operator){
                                case '+':
                                    printf("%f + %f = %f\n",firstNumber, secondNumber, firstNumber + secondNumber);
                                    break;
                                case '-':
                                    printf("%f - %f = %f\n",firstNumber, secondNumber, firstNumber - secondNumber);
                                    break;
                                case '*':
                                    printf("%f * %f = %f\n",firstNumber, secondNumber, firstNumber * secondNumber);
                                    break;
                                case '/':
                                    printf("%f / %f = %f\n",firstNumber, secondNumber, firstNumber / secondNumber);
                                    break;
                                default:
                                    printf("Error! operator is not correct\n");
                            }
                        }
                        else if(0 == strcmp(input, "ls")){
                            printf("Documents  Music  Video  Downloads\n");
                        }
                        else if(0 == strcmp(input, "version")){
                            printf("C-OS V0.1\n");
                        }
                        else if(0 == strcmp(input, "clear")){
                            system("clear");
                        }
                        else if(0 == strcmp(input, "exit")){
                            break;
                        }
                        else if(0 == strcmp(input, "shutdown")){
                            system("clear");
                            count = 0;
                        }
                        else if(0 == strcmp(input, "")){
                            int space = 0;
                        }
                        else{
                            printf("Unknown command.\n");
                        }
                    }
                }
                else if(0 == strcmp(passwd, "")){
                    printf("Wrong password.\n");
                }
                else{
                    printf("Wrong password.\n");
                }
            }
        }
        else if(0 == strcmp(username, "")){
            printf("Wrong username.\n");
        }
        else{
            printf("Wrong username.\n");
        }
    }
    return 0;
}