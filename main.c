#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int gameover=0, day=1, win=0, screen_start=1, screen_main=0, screen_bag=0, screen_explore=0, check_bag=0;
int fish_event=0, screen_fish=0, snake_event=0, screen_snake=0, deer_event=0, screen_deer=0, get_wood=0, snake_option=0;
int hp=20, stamina=10, random=0, location=0;
int campfire=0, food=0, water=0, wood=0, ammo=10;

void start_screen(){
    system("cls");
    printf("===============================================================================================\n");
    printf("##     ## ## ##      ######      ####### ##    ## ######  ##    ## ## ##    ##  ######  ######\n");
    printf("##     ## ## ##      ##   ##     ##      ##    ## ##   ## ##    ## ## ##    ## ##    ## ##   ##\n");
    printf("##  #  ## ## ##      ##   ##     ####### ##    ## ######  ##    ## ## ##    ## ##    ## ######\n");
    printf("## ### ## ## ##      ##   ##          ## ##    ## ##   ##  ##  ##  ##  ##  ##  ##    ## ##   ##\n");
    printf(" ### ###  ## ####### ######      #######  ######  ##   ##   ####   ##   ####    ######  ##   ##\n");
    printf("===============================================================================================\n");
    printf("\t\t\t\t    Survive for 28 days to win.\n");
    printf("\t\t\t\t\tPress 's' to start.\n");
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
    printf("\n                  ______\n");
    printf("                 /     /\\");
    printf("\n                /     /  \\");
    if(campfire>0){
        printf("\n               /_____/----\\_    (");
        printf("\n              \"     \"          ).");
        printf("\n             _ ___          o (:') o");
        printf("\n            (@))_))        o ~/~~\\~ o");
        printf("\n                            o  o  o");
    }
    else{
        printf("\n               /_____/----\\_");
        printf("\n              \"     \"");
        printf("\n             _ ___          o o  o o");
        printf("\n            (@))_))        o ~~~~~~ o");
        printf("\n                            o  o  o");
    }
    printf("\n==================================================");
    printf("\n1 : Exploring\n");
    printf("2 : Check bag\n");
    printf("3 : Fill the campfire (Log-1)\n");
    printf("4 : Sleep (HP-1 per empty campfire)\n");
    printf("Press 'g' to give up.\n");
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
    printf("\n");
    switch(location){
        case 1:
            printf("[Forest]");
            printf("\n==============================================\n");
            printf("               ,@@@@@@@,\n");
            printf("       ,,,.   ,@@@@@@/@@,  .oo8888o.\n");
            printf("    ,&88&8&&8,@@@@@/@@@@@@,8888\\88/8o\n");
            printf("   ,8&\\8&&8&&8,@@@\\@@@/@@@88\\88888/88'\n");
            printf("   8&&8&8&/8&&8@@\\@@/ /@@@88888\\88888'\n");
            printf("   8&&8/ 8&88&&@@\\ V /@@' `88\\8 `/88'\n");
            printf("   `&8\\ ` /8&'    |.|        \\ '|8'\n");
            printf("       |o|        | |         | |\n");
            printf("       |.|        | |         | |\n");
            printf("    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_");
            printf("\n==============================================\n");
            printf("You got %d log.\n", get_wood);
            break;
        case 2:
            printf("[River]");
            printf("\n==============================================\n");
            printf("--~-.______\n");
            printf("          ~~~~-----...___________..--------\n");
            printf("                      |   |     |\n");
            printf("                      | |   |  ||\n");
            printf("                      |  |  |   |\n");
            printf("                      |'. .' .`.|\n");
            printf("______________________|0oOO0oO0o|____________\n");
            printf(" -       -      -    / '  '. ` ` \\    -    -\n");
            printf("     --       --   /    '  . `   ` \\    --\n");
            printf("       ---       /  '                \\ ---\n");
            printf("   ----        /       ' ' .    ` `    \\  ----\n");
            printf("       ----- /   '   '        `      `   \\");
            printf("\n------     /          '    . `     `    `  \\");
            printf("\n         /  '    '      '      `");
            printf("\n==============================================\n");
            printf("You got %d log.\n", get_wood);
            printf("You got 1 water.\n");
            break;
        case 3:
            printf("[Deep forest]");
            printf("\n==============================================\n");
            printf("         A         A          A         A\n");
            printf("        d$b       d$b        d$b       d$b\n");
            printf("       d$$@b     d$$@b      d$$@b     d$$@b\n");
            printf("      d\\$$$ib   d\\$$$ib    d\\$$$ib   d\\$$$ib\n");
            printf("    .d$$$\\$$$b.d$$$\\$$$b  .d$$$\\$$$b.d$$$\\$$$b\n");
            printf("  .d$$@$$$$\\$$ib.$$$\\$$ib.d$$@$$$$\\$$ib.$$$\\$$\n");
            printf("      d$$i$$b   d$$i$$b     d$$i$$b   d$$i$$b\n");
            printf("     d\\$$$$@$b d\\$$$$@$b   d\\$$$$@$b d\\$$$$@$b\n");
            printf("  .d$@$$\\$$$$$@b.\\$$$$$@b.d$@$$\\$$$$$@b.\\$$$$$\n");
            printf(".d$$$$i$$$\\$$$$$$b.\\$$$$$$b.d$$$i$$\\$$$$$$b.\\$\n");
            printf("        ###       ###        ###       ###\n");
            printf("        ###       ###        ###       ###\n");
            printf("VVwwvvWWwwVVvvVVwwWWvvwwVVVVwVVwwvvWWwwVVvvVVw");
            printf("\n==============================================\n");
            printf("You got %d log.\n", get_wood);
            break;
        default:
            printf("[Camp]");
            printf("\n==============================================");
            printf("\n                  ______\n");
            printf("                 /     /\\");
            printf("\n                /     /  \\");
            printf("\n               /_____/----\\_");
            printf("\n              \"     \"");
            printf("\n==============================================\n");
            break;
    }
    printf("1 : Continue exploring (Stamina-1)\n");
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
    printf("   ___\n");
    printf("  /   \\");
    printf("\n |__o__|\n");
    printf(" / : : \\");
    printf("\n(       )\n");
    printf(" `-----'\n");
    printf("==============================================\n");
    printf("1 : Eat food (HP+1)\n");
    printf("2 : Drink water (Stamina+1)\n");
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
    printf("                       .-=-.          .--.\n");
    printf("           __        .'     '.       /  \" )");
    printf("\n   _     .'  '.     /   .-.   \\     /  .-'\\");
    printf("\n  ( \\   / .-.  \\   /   /   \\   \\   /  /    ^\n");
    printf("   \\ `-` /   \\  `-'   /     \\   `-`  /\n");
    printf("    `-.-`     '.____.'       `.____.'\n");
    printf("==============================================\n");
    if(snake_event==0){
        printf("The snake try to bite you, what you want to do?\n");
        printf("1 : Hunt (Chance to fail)\n");
        printf("2 : Shoot (Use ammo)\n");
        printf("3 : Run (Chance to fail)\n");
    }
    else if(snake_event==1&&random>=50&&snake_option==1){
        printf("You successfully escape them.\n");
        printf("Press x to close.\n");
    }
    else if(snake_event==1&&snake_option==1){
        printf("You fail to escape them. (HP-1)\n");
        printf("Press x to close.\n");
    }
    else if(snake_event==1&&random>=50){
        printf("You successfully hunt them. (Food+1)\n");
        printf("Press x to close.\n");
    }
    else if(snake_event==1){
        printf("You fail to hunt them and they bite you back. (HP-2)\n");
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
    printf("          (             )\n");
    printf("           `--(_   _)--'\n");
    printf("                Y-Y\n");
    printf("               /@@ \\");
    printf("\n              /     \\");
    printf("\n              `--'.  \\             ,\n");
    printf("                  |   `.__________/)\n");
    printf("==================================================\n");
    if(deer_event==0){
        printf("You found a deer, want to hunt?\n");
        printf("1 : Hunt (Chance to fail)\n");
        printf("2 : Shoot (Use ammo)\n");
        printf("3 : Ignore\n");
    }
    else if(deer_event==1&&random>=50){
        printf("You successfully kill them. (Food+2)\n");
        printf("Press x to close.\n");
    }
    else if(deer_event==1){
        printf("They escape you.\n");
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
    printf("    o\n");
    printf("   o      ______/~/~/~/__           /((\n");
    printf("     o  // __            ====__    /_((\n");
    printf("    o  //  @))       ))))      ===/__((\n");
    printf("       ))           )))))))        __((\n");
    printf("       \\\\     \\)     ))))    __===\\ _((\n");
    printf("        \\\\_______________====      \\_((\n");
    printf("                                    \\((\n");
    printf("==============================================\n");
    if(fish_event==0){
        printf("You found a fish, try to catch them?\n");
        printf("1 : Yes\n");
        printf("2 : No\n");
    }
    else if(fish_event==1&&random>=50){
        printf("You managed to catch a fish. (Food+1)\n");
        printf("Press x to close.\n");
    }
    else if(fish_event==1){
        printf("All the fish are getting away.\n");
        printf("Press x to close.\n");
    }
}

void exploring_event(){
    random = rand()%100;
    if(random<60){
        location=1;
    }
    else if(random<70){
        location=2;
    }
    else{
        location=3;
    }
    get_wood=0;
    if(location==1){
        random = rand()%100;
        if(random>=90){
            wood=wood+2;
            get_wood=2;
        }
        else if(random>=40){
            wood++;
            get_wood=1;
        }
        random = rand()%100;
        if(random>=85){
            screen_explore=0;
            screen_snake=1;
            snake_option=0;
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
            get_wood=2;
        }
        else if(random>=40){
            wood++;
            get_wood=1;
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
            get_wood=2;
        }
        else{
            wood++;
            get_wood=1;
        }
        random = rand()%100;
        if(random>=80){
            screen_explore=0;
            screen_snake=1;
            snake_option=0;
            snake_screen();
        }
        else if(random>=55){
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
        case 's':
            screen_start=0;
            screen_main=1;
            main_screen();
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
        case 'g':
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
                if(random>=80){
                    food += 2;
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
                    food++;
                }
                else{
                    hp=hp-2;
                }
                snake_event=1;
                snake_screen();
            }
            break;
        case '2':
            if(snake_event==0&&ammo>0){
                random = 99;
                food++;
                ammo--;
                snake_event=1;
                snake_screen();
            }
            break;
        case '3':
            if(snake_event==0){
                random = rand()%100;
                if(random<50){
                    hp--;
                }
                snake_option=1;
                snake_event=1;
                snake_screen();
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
            printf("\t\t\tYou survived %02d day(s).", day);
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
