void search() {
    system("cls");
    FILE *f;
    char roomNumber[20];
    int flag = 1;
    f = fopen("rooms.txt", "r+");
    if(f == 0)
        exit(0);
    fflush(stdin);
	textcolor(14);
	printf("Enter Room number of the customer to search its details: \n");
	setcolor(9);
	scanf("%s", roomNumber);

	int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

    while (fgets(line, sizeof(line), f)) {
		// Copy a new string from line to line2
		strcpy(line2, line);

		// Split string with delimeters to struct
		// - Get id room
		char * token = strtok(line, ", ");
		s.room2 = strtol(token, NULL, 10);

		// - Get longstay
		token = strtok(NULL, ", ");
		s.longstay2 = strtol(token, NULL, 10);

		// - Get checkin
		token = strtok(NULL, "/");
		s.checkin2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.checkin2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.checkin2.yy = strtol(token, NULL, 10);

		// - Get checkout
		token = strtok(NULL, "/");
		s.checkout2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.checkout2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.checkout2.yy = strtol(token, NULL, 10);
		
		// - Get name
		token =  strtok(NULL, ",");
		if (token != NULL) strcpy(s.name2, token);

		// - Get birthday
		token = strtok(NULL, "/");
		s.birth2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.birth2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.birth2.yy = strtol(token, NULL, 10);

		// - Get sex
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.sex2, token);

		// - Get phone number
		token = strtok(NULL, ", ");
		s.phone2 = strtol(token, NULL, 10);		
		strcpy(s.email2, strtok(NULL, ", "));

		// - Get services
		token = strtok(NULL, ", ");
		s.service_in_use2[0] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.service_in_use2[1] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");		
		s.service_in_use2[2] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.service_in_use2[3] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.service_in_use2[4] = strtol(token, NULL, 10);

		// - Get total pay
		token = strtok(NULL, ", ");
		s.total_pay2 = strtol(token, NULL, 10);
		
		// Handling
		if (atoi(roomNumber) == s.room2) {
			flag = 0;
            printf("\n\tRecord Found\n ");

            printf("\nLongstay:\t %d", s.longstay2);
            printf("\nCheckin:\t %d/%d/%d", 
			s.checkin2.dd, s.checkin2.mm, s.checkin2.yy);
			printf("\nCheckout:\t %d/%d/%d", 
			s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);
            printf("\nName:\t\t %s", s.name2);
            printf("\nDate of birth:\t %d/%d/%d", 
			s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);
            printf("\nPhone:\t\t %d", s.phone2);
            printf("\nEmail:\t\t %s", s.email2);
            printf("\nTotal pay:\t %d\n\n", s.total_pay2);
		} 
	}

   
    if (flag == 1){    
        printf("\n\tRequested Customer could not be found!");
    }
    printf("\nPress any key to go back to main menu");
    getch();
    mainMenu();
    fclose(f);
}


