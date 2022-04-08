void cancel() {
	system("cls");

	FILE *f, *t;
	int isHaveRoom = 0;
	char roomNumber[10];

//  Check if files are available
	f = fopen("rooms.txt","r");
	t = fopen("temp.txt","w");
	if (f == NULL || t == NULL) exit(0);

//  Input a room to cancel
	printf("Input a room number to cancle: ");
	fflush(stdin);
	scanf("%s", &roomNumber);

	int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Loop each line
    while (fgets(line, sizeof(line), f)) {
		if (line == "") break;

		// Copy a new string from line to line2
		strcpy(line2, line);

		// Split string with delimeters to struct
		// - Get id room
		char * token = strtok(line, ", ");
		s.room2 = strtol(token, NULL, 10);
		
		// Ckeck each line to find exact room
		if (atoi(roomNumber) == s.room2) {
			isHaveRoom = 1;
			//continue;
		} 
		else {
			// Print to "temp.txt"
			 fprintf(t, "%s", line2);
		}
	}

		// Notification
		if (isHaveRoom) {
			textcolor(14);
			printf("Remove successfully!\n");
			setcolor(9);
		}
		else 
			printf("The room that you input doesn't exist\n");

		// File handling
		fclose(f);
		fclose(t);
		remove("rooms.txt");
		rename("temp.txt", "rooms.txt");

		// Go back to main menu
		printf("Press any key to go back to main menu");
		getch();
		mainMenu();
}
