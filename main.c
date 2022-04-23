#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int gameover=0, day=1, win=0, screen_main=1, screen_ed=0, screen_explore=0,  check_bag=0;
int hp=20, stamina=10, ammo=10;
int campfire=0, food=0, water=0;

void main_screen(){
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
    printf("\n\tStamina : ");
    for(int i=1;i<=10;i++){
        if(i<=stamina){
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
    printf("\n\n\n\n\n\n1 : Exploring\n");
    printf("2 : Check bag\n");
    printf("3 : Sleep\n");
    printf("Press x to harakiri.\n");
}

void exploring(){
    system("cls");
    printf("HP : ");
    for(int i=1;i<=20;i++){
        if(i<=hp){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf(" Stamina : ");
    for(int i=1;i<=10;i++){
        if(i<=stamina){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\n\n\n\n\n");
    printf("1 : Continue exploring\n");
    printf("2 : Check bag\n");
    printf("3 : Back to camp\n");
}

void eat_drink(){
    system("cls");
    printf("HP : ");
    for(int i=1;i<=20;i++){
        if(i<=hp){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf(" Stamina : ");
    for(int i=1;i<=10;i++){
        if(i<=stamina){
            printf("0");
        }
        else{
            printf("-");
        }
    }
    printf("\nFood : %d\n", food);
    printf("Water : %d\n", water);
    printf("\n\n\n\n\n\n1 : Eat food\n");
    printf("2 : Drink water\n");
    printf("3 : Close bag\n");
}

void check_log(){
    hp=hp-(10-campfire);
    campfire=0;
}

void logic(){
    if(hp<=0){
        gameover=1;
    }
    else if(hp>20){
        hp=20;
    }

    if(stamina>10){
        stamina=10;
    }
    else if(stamina<0){
        stamina=0;
    }

    if(day>=29&&hp>0){
        gameover=1;
        win=1;
    }
}

void input(){
    if(screen_main){
        switch(getch()){
        case '1':
            screen_main=0;
            screen_explore=1;
            check_bag=1;
            exploring();
            break;
        case '2':
            screen_main=0;
            screen_ed=1;
            eat_drink();
            break;
        case '3':
            day++;
            stamina=10;
            check_log();
            main_screen();
            break;
        case 'x':
            gameover=1;
            break;
        default:
            break;
        }
    }
    else if(screen_explore){
        switch (getch())
        {
        case '1':
            if(stamina>0){
                stamina--;
                campfire++;
                exploring();
            }
            break;
        case '2':
            screen_explore=0;
            screen_ed=1;
            eat_drink();
            break;
        case '3':
            screen_main=1;
            screen_explore=0;
            check_bag=0;
            main_screen();
            break;
        default:
            break;
        }
    }
    else if(screen_ed){
        switch(getch()){
        case '1':
            hp++;
            eat_drink();
            break;
        case '2':
            stamina++;
            eat_drink();
            break;
        case '3':
            if(check_bag){
                screen_explore=1;
                screen_ed=0;
                exploring();
            }
            else{
                screen_main=1;
                screen_ed=0;
                main_screen();
            }
            break;
        default:
            break;
        }
    }
}

int main(){
    /*while (1)
    {
        printf("##     ## ## ##      ######      ####### ##    ## ######  ##    ## ## ##    ##  ######  ######\n");
        printf("##     ## ## ##      ##   ##     ##      ##    ## ##   ## ##    ## ## ##    ## ##    ## ##   ##\n");
        printf("##  #  ## ## ##      ##   ##     ####### ##    ## ######  ##    ## ## ##    ## ##    ## ######\n");
        printf("## ### ## ## ##      ##   ##          ## ##    ## ##   ##  ##  ##  ##  ##  ##  ##    ## ##   ##\n");
        printf(" ### ###  ## ####### ######      #######  ######  ##   ##   ####   ##   ####    ######  ##   ##\n");
        printf("\n\t\t\t\t\tPress x to play.\n");
        if(getch()=='x'){
            break;
        }
        else{
            system("cls");
        }
    }*/
    main_screen();
    while (!gameover)
    {
        input();
        logic();
    }
    system("cls");
    while (1)
    {
        if(win){
            printf("=============================================================================\n");
            printf("        ####### ##    ## ######  ##    ## ## ##    ## ####### ######\n");
            printf("        ##      ##    ## ##   ## ##    ## ## ##    ## ##      ##   ##\n");
            printf("        ####### ##    ## ######  ##    ## ## ##    ## #####   ##   ##\n");
            printf("             ## ##    ## ##   ##  ##  ##  ##  ##  ##  ##      ##   ##\n");
            printf("        #######  ######  ##   ##   ####   ##   ####   ####### ######\n");
            printf("=============================================================================\n");
        }
        else{
            printf("=============================================================================\n");
            printf("          ##    ##  ######  ##    ##     ######  ## ####### ######\n");
            printf("           ##  ##  ##    ## ##    ##     ##   ## ## ##      ##   ##\n");
            printf("            ####   ##    ## ##    ##     ##   ## ## #####   ##   ##\n");
            printf("             ##    ##    ## ##    ##     ##   ## ## ##      ##   ##\n");
            printf("             ##     ######   ######      ######  ## ####### ######\n");
            printf("=============================================================================\n");
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
