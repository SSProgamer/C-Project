#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int hp=20, energy=10, gameover=0, day=1, exi=0, win=0, campfire=0;

void screen(){
    system("cls");
    printf("Day %d\t", day);
    printf("HP : ");
    for(int i=1;i<=20;i++){
        if(i<=hp){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\n\tEnergy : ");
    for(int i=1;i<=10;i++){
        if(i<=energy){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf(" Campfire : ");
    for(int i=1;i<=10;i++){
        if(i<=campfire){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\n\n\n\n\n\n1 : Go find someting\n");
    printf("2 : Cook and craft\n");
    printf("3 : Eat\n");
    printf("4 : Sleep\n");
    printf("Press x to end game.\n");
}

void check_log(){
    hp=hp-(10-campfire);
    campfire=0;
}

void logic(){
    if(hp==0){
        gameover=1;
    }
    if(hp>20){
        hp=20;
    }
    if(energy>10){
        energy=10;
    }
    else if(energy<0){
        energy=0;
    }
    if(day==29){
        gameover=1;
        win=1;
    }
}

void input(){
    if(kbhit()){
        switch(getch()){
        case '1':
            energy--;
            campfire++;
            screen();
            break;
        case '2':
            hp++;
            screen();
            break;
        case '3':
            hp--;
            screen();
            break;
        case '4':
            day++;
            energy=10;
            check_log();
            screen();
            break;
        case 'x':
            gameover=1;
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
    while (!exi)
    {
        if(win){
            printf("[=====You Survive=====]\n");
        }
        else{
            printf("[=====Game Over=====]\n");
        }
        printf("Press x to quit.\n");
        if(getch()=='x'){
            break;
        }
        else{
            system("cls");
        }
    }
    return 0;
}
