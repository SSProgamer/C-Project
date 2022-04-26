#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int gameover=0, day=1, win=0, screen_start=1, screen_tutorial=0, screen_main=0, screen_bag=0, screen_explore=0, check_bag=0;
int fish_event=0, screen_fish=0, snake_event=0, screen_snake=0, deer_event=0, screen_deer=0;
int hp=20, stamina=10, random=0, location=0;
int campfire=0, food=0, water=0, wood=0, ammo=10;

void start_screen(){
    system("cls");
    printf("##     ## ## ##      ######      ####### ##    ## ######  ##    ## ## ##    ##  ######  ######\n");
    printf("##     ## ## ##      ##   ##     ##      ##    ## ##   ## ##    ## ## ##    ## ##    ## ##   ##\n");
    printf("##  #  ## ## ##      ##   ##     ####### ##    ## ######  ##    ## ## ##    ## ##    ## ######\n");
    printf("## ### ## ## ##      ##   ##          ## ##    ## ##   ##  ##  ##  ##  ##  ##  ##    ## ##   ##\n");
    printf(" ### ###  ## ####### ######      #######  ######  ##   ##   ####   ##   ####    ######  ##   ##\n");
    printf("\n\t\t\t\t\t1 : Start\n");
    printf("\t\t\t\t\t2 : Tutorial\n");
}

void tutorial_screen(){
    system("cls");
    printf("Press x to close.\n");
}

void main_screen(){
    system("cls");
    printf("==================================================\n");
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
    printf("\n==================================================");
    printf("\n        ______\n");
    printf("       /     /\\");
    printf("\n      /     /  \\");
    if(campfire>0){
        printf("\n     /_____/----\\_    (");
        printf("\n    \"     \"          ).");
        printf("\n   _ ___          o (:') o");
        printf("\n  (@))_))        o ~/~~\\~ o");
        printf("\n                  o  o  o");
    }
    else{
        printf("\n     /_____/----\\_");
        printf("\n    \"     \"");
        printf("\n   _ ___          o o  o o");
        printf("\n  (@))_))        o ~~~~~~ o");
        printf("\n                  o  o  o");
    }
    printf("\n==================================================");
    printf("\n1 : Exploring\n");
    printf("2 : Check bag\n");
    printf("3 : Fill the campfire\n");
    printf("4 : Sleep\n");
    printf("Press x to give up.\n");
}

void exploring(){
    system("cls");
    printf("==============================================\n");
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
    printf("\n==============================================\n");
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
    printf("==============================================\n");
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
    printf("\n==============================================\n");
    printf("Log : %d\n", wood);
    printf("Food : %d\n", food);
    printf("Water : %d\n", water);
    printf("Ammo : %d\n", ammo);
    printf("\n\n1 : Eat food\n");
    printf("2 : Drink water\n");
    printf("3 : Close bag\n");
}

void snake_screen(){
    system("cls");
    printf("==============================================\n");
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
    printf("\n==============================================\n");
    if(snake_event==0){
        printf("Snake, fight?\n\n\n\n\n\n");
        printf("1 : Fight\n");
        printf("2 : Shoot\n");
        printf("3 : Run\n");
    }
    else if(snake_event==1&&random>=50){
        printf("Yes, win!\n\n\n\n\n\n");
        printf("Press x to close.\n");
    }
    else if(snake_event==1){
        printf("You lose.\n\n\n\n\n\n");
        printf("Press x to close.\n");
    }
}

void deer_screen(){
    system("cls");
    printf("==============================================\n");
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
    printf("\n==============================================\n");
    printf("(             )\n");
    printf(" `--(_   _)--'\n");
    printf("      Y-Y\n");
    printf("     /@@ \\");
    printf("\n    /     \\");
    printf("\n    `--'.  \\             ,\n");
    printf("        |   `.__________/)\n");
    printf("==================================================\n");
    if(deer_event==0){
        printf("Deer, hunt?\n");
        printf("1 : Hunt\n");
        printf("2 : Shoot\n");
        printf("3 : No\n");
    }
    else if(deer_event==1&&random>=50){
        printf("Yes, you kill them!\n");
        printf("Press x to close.\n");
    }
    else if(deer_event==1){
        printf("They escape.\n");
        printf("Press x to close.\n");
    }
}

void fish_screen(){
    system("cls");
    printf("==============================================\n");
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
    printf("\n==============================================\n");
    if(fish_event==0){
        printf("Fish, want?\n\n\n\n\n\n");
        printf("1 : Want\n");
        printf("2 : No\n");
    }
    else if(fish_event==1&&random>=50){
        printf("Yes, fish!\n\n\n\n\n\n");
        printf("Press x to close.\n");
    }
    else if(fish_event==1){
        printf("No fish for you.\n\n\n\n\n\n");
        printf("Press x to close.\n");
    }
}

void exploring_event(){
    random = rand()%100;
    if(random<60){
        location=1;
    }
    else if(random<80){
        location=2;
    }
    else{
        location=3;
    }

    if(location==1){
        random = rand()%100;
        if(random>=90){
            wood=wood+2;
        }
        else if(random>=40){
            wood++;
        }
        random = rand()%100;
        if(random>=85){
            screen_explore=0;
            screen_snake=1;
            snake_screen();
        }
        else if(random>=65){
            screen_explore=0;
            screen_deer=1;
            deer_screen();
        }
        else{
            exploring();
        }
    }
    else if(location==2){
        random = rand()%100;
        if(random>=90){
            wood=wood+2;
        }
        else if(random>=40){
            wood++;
        }
        water++;
        screen_explore=0;
        screen_fish=1;
        fish_screen();
    }
    else if(location==3){
        random = rand()%100;
        if(random>=80){
            wood=wood+2;
        }
        else{
            wood++;
        }
        random = rand()%100;
        if(random>=85){
            screen_explore=0;
            screen_snake=1;
            snake_screen();
        }
        else if(random>=65){
            screen_explore=0;
            screen_deer=1;
            deer_screen();
        }
        else{
            exploring();
        }
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
    if(screen_start){
        switch(getch()){
        case '1':
            screen_start=0;
            screen_main=1;
            main_screen();
            break;
        case '2':
            screen_start=0;
            screen_tutorial=1;
            tutorial_screen();
            break;
        default:
            break;
        }
    }
    else if(screen_tutorial){
        switch(getch()){
        case 'x':
            screen_tutorial=0;
            screen_start=1;
            start_screen();
            break;
        default:
            break;
        }
    }
    else if(screen_main){
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
                exploring_event();
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
    else if(screen_deer){
        switch (getch()){
        case '1':
            if(deer_event==0){
                random = rand()%100;
                if(random>=50){
                    food++;
                }
                deer_event=1;
                deer_screen();
            }
            break;
        case '2':
            if(deer_event==0&&ammo>0){
                random = 99;
                food++;
                ammo--;
                deer_event=1;
                deer_screen();
            }
            break;
        case '3':
            if(deer_event==0){
                screen_deer=0;
                screen_explore=1;
                exploring();
            }
            break;
        case 'x':
            if(deer_event==1){
                deer_event=0;
                screen_deer=0;
                screen_explore=1;
                exploring();
            }
            break;
        default:
            break;
        }
    }
    else if(screen_snake){
        switch (getch()){
        case '1':
            if(snake_event==0){
                random = rand()%100;
                if(random>=50){
                    food=food+2;
                }
                else{
                    hp--;
                }
                snake_event=1;
                snake_screen();
            }
            break;
        case '2':
            if(snake_event==0&&ammo>0){
                random = 99;
                food=food+2;
                ammo--;
                snake_event=1;
                snake_screen();
            }
            break;
        case '3':
            if(snake_event==0){
                screen_snake=0;
                screen_explore=1;
                exploring();
            }
            break;
        case 'x':
            if(snake_event==1){
                snake_event=0;
                screen_snake=0;
                screen_explore=1;
                exploring();
            }
            break;
        default:
            break;
        }
    }
    else if(screen_fish){
        switch (getch()){
        case '1':
            if(fish_event==0){
                random = rand()%100;
                if(random>=50){
                    food++;
                }
                fish_event=1;
                fish_screen();
            }
            break;
        case '2':
            if(fish_event==0){
                screen_fish=0;
                screen_explore=1;
                exploring();
            }
            break;
        case 'x':
            if(fish_event==1){
                fish_event=0;
                screen_fish=0;
                screen_explore=1;
                exploring();
            }
            break;
        default:
            break;
        }
    }
}

int main(){
    srand(time(0));
    start_screen();
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
