#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include"passwin.h"

int turn ,flag ;
int player,comp;
int go();
int make2();
int gotoxy();
int make4();
int player_first();

void start_game()
{
    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(make2())
        go(make2());
    else
        go(make4());
    draw_board();
    if(flag)
    {
        gotoxy(30,20);
        //textcolor(128+RED);
        printf("Computer wins");
        getch();
    }
    else
        player_first();
}
