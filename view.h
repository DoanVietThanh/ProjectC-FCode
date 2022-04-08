void view() {
	FILE *fp;
//	fp = NULL;
	char arr[100000], *sexString;
	fp = fopen("rooms.txt", "r+");

//	int cost
	int lineLength = 255, roomNumber, numClient = 1;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */
    while (fgets(line, sizeof(line), fp)) {
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
		if (roomNumber != s.room2) {
			// Export: Roon number, longstay, checkin, checkout
			printf("\n\n");
			textcolor(6);
			for (int i = 0; i < 32; i++)
			{
				printf("%c", 205);
			}
			printf(" ROOM %d ", s.room2);
			for (int i = 0; i < 32; i++) {
				printf("%c", 205);
			}
			setcolor(9);
			printf("\nPeriod days : %d\n", s.longstay2);
			printf("Checkin     : %d/%d/%d\n", s.checkin2.dd, s.checkin2.mm, s.checkin2.yy);
			printf("Checkout    : %d/%d/%d\n", s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);
			// Export services
			printf("\n\nServices in use: \n Service 1 \t Service 2 \t Service 3 \t Service 4 \t Service 5 \n ");
			for (int a = 0; a < 5; a++) {    	    			
				if (s.service_in_use2[a] == 1 ) {
					printf("YES              ");
				}
				else {
					// cost_service[a]= 0;
					printf("NO              ");		
				}
			}
			// Export total pay
			printf("\nTotal pay: %d\n", s.total_pay2);
			roomNumber = s.room2;
			numClient = 1;
		}

		switch (s.sex2[0]) {
			case 'f':
			case 'F':
				sexString = "Female";
				break;
			case 'm':
			case 'M':
				sexString = "Male";
				break;
			case 'o':
			case 'O':
				sexString = "Others";
				break;	
			// default:
			// 	sexString = '';
		}

		printf("\nPerson %d \n >>----------<< \n Fullname:\t\t%s \n Birthday (mm/dd/yyyy): %d/%d/%d \n Sex: \t\t\t%s \n Phone number:\t\t0%d \n Email:\t\t\t%s\n", 
		numClient,
		s.name2,
		s.birth2.dd, s.birth2.mm, s.birth2.yy,
		sexString,
		s.phone2,
		s.email2);   
		numClient++;
	}
	fclose(fp);
	printf("\nPress anykey to return home screen");
	getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}
