void mainMenu() {
	system("cls");
	int input;

	for(i = 0 ; i < 80 ; i ++) printf("-");
	printf("\n");
	printf("   ****************************  |MAIN MENU|  *************************** \n");
	for(i = 0; i < 80; i ++) printf("-");
	printf("\n");

	printf("\t\t      Please enter your choice for menu\n\n");



	textcolor(10);
	printf("\t   %c", 218);
	for (int i = 0; i <= 50; i++)
		printf("%c", 196);
	printf("%c\n", 191);

	printf("\t   %c Enter 1 %c Book a room                             %c \n", 179, 179, 179);

	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

	printf("\t   %c Enter 2 %c View Customer Record                    %c\n", 179, 179, 179);

	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

	printf("\t   %c Enter 3 %c Cancel A Room                           %c\n", 179, 179, 179);
	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

	printf("\t   %c Enter 4 %c Search Customer Record                  %c\n", 179, 179, 179);
	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

	printf("\t   %c Enter 5 %c Edit Record                             %c\n", 179, 179, 179);
	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

	printf("\t   %c Enter 6 %c Add Room cleaning Schedule              %c\n", 179, 179, 179);
	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

    printf("\t   %c Enter 7 %c Show Room cleaning Schedule             %c\n", 179, 179, 179);
	printf("\t   %c", 195);
	for (int i = 0; i <= 50; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 180);

	printf("\t   %c Enter 8 %c Exit                                    %c\n", 179, 179, 179);
	printf("\t   %c", 192);
	for (int i = 0; i <= 50; i++) { 
		printf("%c", 196);
	}
	printf("%c", 217);

	setcolor(9);
	printf("\n\n\t\t\t    Your choice is: ");
	fflush(stdin);
	input = getchar();
	switch (input) {
		case '1':
			system("cls");
			bookroom();
			break;
		case '2':
			system("cls");
			view();
			break;
		case '3':
			system("cls");
			cancel();
			break;
		case '4':
			system("cls");
			search();
			break;
		case '5':
			system("cls"); 
			edit();
			break;
		case '6': 
			system("cls");
			addCleaningSchedule();
			break;
		case '7':
			system("cls");
			showCleaningSchedule();
			break;
		case '8':
			system("cls");
			exiting();
			break;
		default:
			mainMenu();
	}
}
