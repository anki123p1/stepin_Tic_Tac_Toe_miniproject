//LEARNPROGRAMO-PROGRAMMING MADE SIMPLE
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include"passwin.h"

int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,comp;

void menu();
void go(int n);
void start_game();
void help();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch,int pos);
COORD coord= {0,0}; // this is global variable
//center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void main()
{
    system("cls");
    menu();
    getch();

}

void menu()
{
    int choice;
    system("cls");
    printf("\n--------MENU--------");
    printf("\n1 : Play with X \n\n");
    printf("\n2 : Play with O \n\n");
    printf("\n3 : Exit \n\n");
	printf("\n4 : Help \n\n");
    printf("\nEnter your choice:>");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        player_first();
        break;
    case 2:
        player = 0;
        comp = 1;
        start_game();
        break;
    case 3:
        exit(1);
	case 4:
	    player = 1;
        comp = 0;
	    help();
		break;
    default:
        menu();
    }
}

int make2()
{
    if(board[5] == 2)
        return 5;
    if(board[2] == 2)
        return 2;
    if(board[4] == 2)
        return 4;
    if(board[6] == 2)
        return 6;
    if(board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if(board[1] == 2)
        return 1;
    if(board[3] == 2)
        return 3;
    if(board[7] == 2)
        return 7;
    if(board[9] == 2)
        return 9;
    return 0;
}


void go(int n)
{
    if(turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void player_first()
{
    int pos;

    check_draw();
    draw_board();
    gotoxy(30,18);
    printf("Your Turn :> ");
    scanf("%d",&pos);

    if(board[pos] != 2)
        player_first();

    if(pos == posswin(player))
    {
        go(pos);
        draw_board();
        gotoxy(30,20);
        //textcolor(128+RED);
        printf("congratulations you won !!!!");
        getch();
        exit(0);
    }

    go(pos);
    draw_board();
    start_game();
}
