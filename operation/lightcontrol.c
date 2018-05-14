/*  */
#include <stdio.h>

#define OFF   0
#define ON    1
#define EXIT  9


// Check if the light is on or not, 1 if on, 0 if off;
int isLightOn(unsigned char status, int n) {
    unsigned char mask = 1;                 // 00000001
    unsigned char temp = status >> (n-1);   // Logical right shift
    temp = temp & mask;                     // Unsetting
    if(temp == OFF)
        return OFF;
    else
        return ON;
}

// Turn the light on
void turnLightOn(unsigned char *status, int n) {
    unsigned char mask = 1;                 // 00000001
    mask = mask << (n-1);                   // Logical left shift
    *status = *status | mask;               // Setting
}

// Turn the light off
void turnLightOff(unsigned char *status, int n) {
    unsigned char mask = 1;                 // 00000001
    mask = mask << (n-1);                   // Logical left shift
    mask = ~mask;                           // Not
    *status = *status & mask;               // Unsetting
}

// Print the status of all lights
void printLightStatus(unsigned char status) {
    int i = 0;
    printf("### Light Status ###\n");
    printf("L8\tL7\tL6\tL5\tL4\tL3\tL2\tL1\n");
    for(i=8 ; i>=1 ; i--) {
        if(isLightOn(status, i) == 1)
            printf("ON\t");
        else
            printf("OFF\t");
    }
    printf("\n\n");
}

int main(int argc, char **argv) {
    int cmd = OFF;
    int light = 1;
    unsigned char status = 0;

    printLightStatus(status);

    while(1) {
        printf("Select commands (turn off: 0, turn on: 1, exit: 9):");
        scanf("%d", &cmd);

        switch(cmd) {
            case OFF:
            case ON:
                while(1) {
                    printf("Select light (1 ~ 8):");
                    scanf("%d", &light);
                    if(light>=1 && light<=8) {
                        if(cmd == ON) {
                            turnLightOn(&status, light);
                        } else {
                            turnLightOff(&status, light);
                        }
                        printLightStatus(status);
                        break;
                    } else {
                        printf("[ERROR] Light not found!\n");
                    }
                }
                break;
            case EXIT:
                return 0;
            default:
                printf("[ERROR] Command not found!\n");
        }
    }
}
