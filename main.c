#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int gameover=0, day=1, win=0, screen_main=1, screen_bag=0, screen_explore=0,  check_bag=0, fish_event=0;
int hp=20, stamina=10, random=0, location=0;
int campfire=0, food=0, water=0, wood=0, ammo=10;

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
    printf("3 : Fill the campfire\n");
    printf("4 : Sleep\n");
    printf("Press x to give up.\n");
}

void fish(){
    
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
    printf("\n");
    switch(location){
        case 1:
            printf("[Forest]");
            break;
        case 2:
            printf("[River]");
            break;
        case 3:
            printf("[Deep forest]");
            break;
        default:
            break;
    }
    printf("\n\n\n\n\n\n");
    printf("1 : Continue exploring\n");
    printf("2 : Check bag\n");
    printf("3 : Back to camp\n");
}

void bag(){
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
    printf("\nLog : %d\n", wood);
    printf("Food : %d\n", food);
    printf("Water : %d\n", water);
    printf("Ammo : %d\n", ammo);
    printf("\n\n1 : Eat food\n");
    printf("2 : Drink water\n");
    printf("3 : Close bag\n");
}

void exploring_event(){
    random = rand()%10;
    if(random<6){
        location=1;
    }
    else if(random<8){
        location=2;
    }
    else{
        location=3;
    }
}

void check_campfire(){
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
            screen_bag=1;
            bag();
            break;
        case '3':
            if(wood>0&&campfire<10){
                wood--;
                campfire++;
                main_screen();
            }
            break;
        case '4':
            day++;
            stamina=10;
            check_campfire();
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
        switch (getch()){
        case '1':
            if(stamina>0){
                stamina--;
                wood++;
                food++;
                water++;
                exploring_event();
                exploring();
            }
            break;
        case '2':
            screen_explore=0;
            screen_bag=1;
            bag();
            break;
        case '3':
            screen_main=1;
            screen_explore=0;
            check_bag=0;
            location=0;
            main_screen();
            break;
        default:
            break;
        }
    }
    else if(screen_bag){
        switch(getch()){
        case '1':
            if(food>0&&hp<20){
                food--;
                hp++;
                bag();
            }
            break;
        case '2':
            if(water>0&&stamina<10){
                water--;
                stamina++;
                bag();
            }
            break;
        case '3':
            if(check_bag){
                screen_explore=1;
                screen_bag=0;
                exploring();
            }
            else{
                screen_main=1;
                screen_bag=0;
                main_screen();
            }
            break;
        default:
            break;
        }
    }
}

int main(){
    srand(time(0));
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
