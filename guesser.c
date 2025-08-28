
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>

void printfColor(int r, int g, int b, const char* text, ...) {
    va_list vList;
    va_start(vList, text);
    printf("\033[38;2;%d;%d;%dm", r, g, b);
    vprintf(text, vList);
    printf("\033[38;2;255;255;255m"); 
    va_end(vList);
}

int main() {

    srand(time(NULL));

    int maxValue = 0;
    int minValue = 0;
    int userInput = 0;
    int tries = 1;

    printf("Von 0 bis wie viel möchtest du eine Zahl erraten?: ");
    scanf("%d", &maxValue);

    int computerNum = rand() % (maxValue - minValue + 1) + minValue;

    printf("Try: %d Gib eine Zahl von 0 - %d ein: ", tries, maxValue);
    scanf("%d", &userInput);

    while(true) {

        if(computerNum == userInput) {
            printfColor(0, 255, 0, "Korrekt!\n");
            printf("Du hast %d Versuche gebraucht!\n", tries);
            break;
        }
        else{
            
            if(userInput > computerNum) {
                printf("Zu groß!\n");
            }
            else {
                printf("Zu klein!\n");
            }

            tries++;
            printf("Try:");
            printfColor(0, 0, 255, " %d ", tries);
            printfColor(255, 0, 0, "Gib eine neue Zahl zwischen 0 - %d ein: ", maxValue);
            scanf("%d", &userInput);
        }   
    }

    return 0;
}