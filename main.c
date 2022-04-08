#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include <errno.h>

#define home main 
#include "constants.h"
#include "graphic.h"
#include "add-cleaning-schedule.c"
#include "login.h"
#include "main-menu.h"
#include "collapse_str.h"
#include "bookroom.h" 
#include "cancel.h"
#include "edit.h"
#include "exit.h"
#include "search.h"
#include "view.h"

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
if(GetConsoleScreenBufferInfo(hStdOut,&csbi)) {
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
	SetConsoleTextAttribute(hStdOut,wColor);
	}
}

void home() {
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int option;
	time_t t;
	time(&t);
	char choice;
	system("cls"); 
	textcolor(6);
	printf("%c", 201);
	for (int i = 0; i <= 80; i++) printf("%c", 205);
	printf("%c\n", 187);
	printf("%c                                                                                 %c\n", 186, 186);       
	printf("%c                                                                                 %c\n", 186, 186);
	printf("%c  OOOOOO    OOOOOO  OOOOOO  OOOOOO  OOOOOO  OOOOOO  O      O  OOOOOOO   OOOOOO   %c\n", 186, 186);
	printf("%c  O         O    O  O       O         O       O     O O    O  O         O        %c\n", 186, 186);
	printf("%c  O  OOOOO  OOOOOO  OOOOO   OOOOO     O       O     O  O   O  O  OOOOO  OOOOOO   %c\n", 186, 186);
	printf("%c  O    O    O  O    O       O         O       O     O   O  O  O    O         O   %c\n", 186, 186);
	printf("%c  OOOOOO    O   O   OOOOOO  OOOOOO    O     OOOOOO  O    O O  OOOOOO    OOOOOO   %c\n", 186, 186);
	printf("%c                                                                                 %c\n", 186, 186);
	
	printf("%c", 204);
	for (int i = 0; i <= 80; i++)
		printf("%c", 205);
	printf("%c\n", 185); 

	printf("%c\t\t                                                  \t\t  %c\n", 186, 186);
	printf("%c\t\t *************************************************\t\t  %c\n", 186, 186);
	printf("%c\t\t *                                               *\t\t  %c\n", 186, 186);
	printf("%c\t\t *         -----------------------------         *\t\t  %c\n", 186, 186);
	printf("%c\t\t *            WELCOME TO HOTEL TEAM 1            *\t\t  %c\n", 186, 186);
	printf("%c\t\t *         -----------------------------         *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                                               *\t\t  %c\n", 186, 186);
	printf("%c\t\t *            Mentor: Le Ngoc Son                *\t\t  %c\n", 186, 186);
	printf("%c\t\t *           Members: Nguyen Hoang Anh           *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                    Tran Hai Dang              *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                    Doan Viet Thanh            *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                                               *\t\t  %c\n", 186, 186);
	printf("%c\t\t *************************************************\t\t  %c\n", 186, 186);
	printf("%c\t\t                                                  \t\t  %c\n", 186, 186);
	printf("%c", 200);
	for (int i = 0; i <= 80; i++)   
		printf("%c", 205);
	printf("%c\n", 188);
	
	setcolor(15);
	for (i = 0; i < 83; i++)
		printf("-");
	    printf("\n                 Current date and time : %s",ctime(&t));
	    for(i=0;i<83;i++)
		printf("-");
	printf(" \n                            Press any key to continue  ");

	getch();	 
	system("cls");

RUN11: {
	textcolor(10);
	printf("\t\t%c", 218);
	for (int i = 0; i <= 38; i++) {
		printf("%c", 196); 
	}
	printf("%c\n", 191);
	printf("\t\t%c\t Enter '1' to Register \t\t%c\n", 179, 179);
	printf("\t\t%c\t Enter '2' to Login    \t\t%c\n", 179, 179);
}

	printf("\t\t%c", 192);
	for (int i = 0; i <= 38; i++) {
		printf("%c", 196); 
	}
	printf("%c\n", 217);

	setcolor(9);
	printf("\t\t\t   Your choice is : ");
	scanf("%d", &option);
    getchar();

    if (option == 1)
        { 
            system("CLS");
            registration();
        } 
    else if (option == 2)
        {
            system("CLS");
            login();
        }  
	else
	 	{
			textcolor(12);
			printf("\n");
			printf("                            Choose 1 or 2 !!!               "); // doi thanh mau do 
	 	    printf("\n                          Enter any key to back");
			getch();
			setcolor(9);
			system("cls");
			goto RUN11;
			//home();
		}
    system("cls");
	mainMenu();
}