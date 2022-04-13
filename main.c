#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int hp=10, energy=10, gameover=0, day=1;
char test[9999];

void screen(){
    system("cls");
    printf("Day %d\t", day);
    printf("HP:");
    for(int i=1;i<=10;i++){
        if(i<=hp){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\nEnergy:");
    for(int i=1;i<=10;i++){
        if(i<=energy){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\n1 : Go find someting\n");
    printf("2 : Cook and eat\n");
    printf("3 : Equipment\n");
    printf("4 : Sleep\n");
    printf("Press X to quit.\n");
}

void logic(){
    if(hp==0){
        gameover=1;
    }
}

void input(){
    if (kbhit()) {
        switch (getch()) {
        case '1':
            hp--;
            screen();
            break;
        case '2':
            energy--;
            screen();
            break;
        case '3':
            gameover = 1;
            break;
        case '4':
            day++;
            screen();
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

int main(){
    screen();
    while (!gameover)
    {
        input();
        logic();
    }
    system("cls");
    printf("===== ควยเล่นกาก =====");
    while (1)
    {
        continue;
    }
    
    return 0;
}
