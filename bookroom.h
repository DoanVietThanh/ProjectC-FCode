void bookroom() {
	char ch;
	int i;

    //Set id for each room
	textcolor(14);
	for (i = 1; i <= 20; ++i)
		roomnumber[i].id_room = i;
	roomstatus(roomnumber);
	setcolor(9);
// Pick room
	RUN1: {
	// ch = "";
	printf("\n\n    Which room number you choose: ");
	fflush(stdin);
	scanf("%d", &i);
	};
    	
   	//Check status of this room
		if (roomnumber[i].status == 1 || i > 20 || i < 1) {
			textcolor(12);
			printf("\nThe room you choose is not available now or have been booked !\n");
			printf("\nPlease pick another room >>   \n\n");
			setcolor(9);
		RUN5:
			printf("\nReturn to home press --> \"H\" \nPick another room press --> \"A\" \n>>> ");
			ch = getch();
			if (ch == 'h' || ch == 'H')
			{
				mainMenu();
			}
			if (ch == 'a' || ch == 'A')
				goto RUN1;
			if (ch != 'a' || ch != 'A' || ch != 'h' || ch != 'H')
				goto RUN5;
    }
				
//======================================================================================
		
	//room type 1 max people is 2
	if (i >= 1 && i <= 5 ){		
		int h = 0; //h bieu thi chi so index cua cau truc kieu mang cost_room[4]
		add(h, i); 
  	}
    
   	//room type 2 max people is 5
   	if (i >= 6 && i <= 10 ){
		int h = 1;
		add(h, i);
   	}
   	//room type 3 max people is 8
   	if (i >= 11 && i <= 15 ){
		int h = 2;
		add(h, i);
   	}
   	//room type 4 max people is 11
   	if (i >= 16 && i <= 20){
   		int h = 3;
   		add(h, i); 
	}
}
 
void add (int h, int i) { 
   fp = fopen("rooms.txt", "a+"); 
	if (fp == 0) {
    	fp = fopen("rooms.txt", "a+");
	    printf("Please hold on while we set our database in your computer !!");
	    printf("\n Process completed press any key to continue !!");
	    getch();
	} 

	system("cls");
	roomnumber[i].numclient = 0;
	roomnumber[i].id_room = i;
    printf("=================== ROOM %d ===================\n", i);
    printf("\nPrice per night is %d", cost_room[h].price_per_night); 
	printf("\nNote: Max people in %s is %d", cost_room[h].type, cost_room[h].max_people );		   

	// Validate longstay
	char c;
	RUN8:
		textcolor(14);
		printf("\n* Maximum number of nights can book is 30 *");
		setcolor(9);
		printf("\nEnter period (\'x\'nights): ");
		fflush(stdin);
		if (scanf("%d%c", &roomnumber[i].longstay, &c) != 2 || c != '\n' || roomnumber[i].longstay <= 0 || roomnumber[i].longstay > 30)
		{ // has changed
			textcolor(12);
			printf("Error\n");
			setcolor(9);
			goto RUN8;	
	}

    RUN14:
	// Validate checkin
	isValid = 0;
	while (!isValid) {
		// Input
		printf("\nEnter day you checkin (dd/mm/yy): ");
		fflush(stdin);
		scanf("%d/%d/%d", &roomnumber[i].checkin.dd, &roomnumber[i].checkin.mm, &roomnumber[i].checkin.yy);
		int day = roomnumber[i].checkin.dd;
		int month = roomnumber[i].checkin.mm;
		int year = roomnumber[i].checkin.yy;

		//check year
		if (year >= 2022 && year <= 2100) { 
			//check month
			if (month >= 1 && month <= 12) {
				//check days
				if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
					isValid = 1;
				else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
					isValid = 1;
				else if((day >= 1 && day <= 28) && (month == 2))
					isValid = 1;
				else if(day == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
					isValid = 1;
				else
					isValid = 0;
			}
			else {
				isValid = 0;
			}
		}
		else {
			isValid = 0;
		}

		// Notification
		if (isValid != 1) {
			textcolor(12);
			printf("Your input is unvalid. Please try again!\n");
			setcolor(9);
		}
	}

	// Validate checkout
	isValid = 0;
	while (!isValid) {
		// Input
		printf("\nEnter day you checkout (dd/mm/yy): " );
		fflush(stdin);
		scanf("%d/%d/%d", &roomnumber[i].checkout.dd, &roomnumber[i].checkout.mm, &roomnumber[i].checkout.yy );	
		int day = roomnumber[i].checkout.dd;
		int month = roomnumber[i].checkout.mm;
		int year = roomnumber[i].checkout.yy;

		//check year
		if (year >= 2022 && year <= 2100) {
			//check month
			if (month >= 1 && month <= 12) {
				//check days
				if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
					isValid = 1;
				else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
					isValid = 1;
				else if((day >= 1 && day <= 28) && (month == 2))
					isValid = 1;
				else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
					isValid = 1;
				else
					isValid = 0;
			}
			else {
				isValid = 0;
			}
		}
		else {
			isValid = 0;
		}

		// Notification
		if (isValid != 1) {
			textcolor(12);
			printf("Your input is unvalid. Please try again!\n");
			setcolor(9);
		}
	}

	//check day out - day in = longstay ? 
	int day_diff; int mon_diff; int year_diff;	
	substract_2_days(roomnumber[i].checkin.dd, roomnumber[i].checkout.dd, 
	                 roomnumber[i].checkin.mm, roomnumber[i].checkout.mm,
					 roomnumber[i].checkin.yy, roomnumber[i].checkout.yy,
					 &day_diff, &mon_diff, &year_diff                    
					);
	textcolor(14);
	printf("\nDifference: %d years %2d months and %2d days.", year_diff, mon_diff, day_diff);
	setcolor(9);
	// truong hop 30 dem tuc 31 ngay la tron 1 thang
	if(day_diff != roomnumber[i].longstay || year_diff !=0 || mon_diff != 0 ){
    	textcolor(12);
    	printf("\nThe nights between checkin date and checkout date is not valid !!!");
    	printf("\nPlease input again\n");
    	setcolor(9);
    	goto RUN14;
	}

	
	
	
      
    printf("\n--------------------------------------------------");

	//Book service
	printf("\n\nWe have these services\n");
	printf("1. Dry cleaning \t : 100.000\n");
	printf("2. Massages \t\t : 100.000\n");
	printf("3. Car rent \t\t : 200.000\n"); 
	printf("4. Eating buffet \t : 200.000\n");
	printf("5. Guided tours \t : 400.000\n");
	textcolor(14);
	printf("\nNote: If you want to use service 1 type \" 1 for YES or 0 for NO \" ");
	setcolor(9);
	int a, check[6];
	printf("\n\nLet choose  :\n");
RUN3:	for(int a=1; a <= 5; a++){
		printf("\nChoose service %d (Yes / No): ", list_service[a-1].id);
		check[a] = scanf("%d", &roomnumber[i].service_in_use[a]);
		fflush(stdin);
	}
	for(int a=1; a <= 5; a++){
		if(check[a] == 0) {
		    	textcolor(12);
			    printf("\n ERROR !!! \n");
			    printf("\nPlease input again ");
			    setcolor(9);
			    //delay(5);
		    	//system("cls");
	
			goto RUN3; 
		}
		if(check[a] == 1) {
			if(roomnumber[i].service_in_use[a] == 0){
			    cost_service[a] = 0;	
			}
			else if(roomnumber[i].service_in_use[a] == 1) {
				cost_service[a] = list_service[a - 1].price_service;	
			}
			else {
				textcolor(12);
			    printf("\n ERROR !!! \n");
			    printf("\nPlease input again ");
			    setcolor(9);
		    	//delay(5);
		    	//system("cls");
			    goto RUN3;
			}	
		}
	} 
	printf("\n======================================================================================");		
	printf("\n\n           !!---Please fill this form---!!        \n");
	
	roomnumber[i].numclient = 1;
	while (roomnumber[i].numclient <= cost_room[h].max_people) {
	   		
		printf("\n         >>----Person %d----<<\n", roomnumber[i].numclient );

		printf("\n\nEnter your fullname: ");
		fflush(stdin);
		gets(roomnumber[i].client.name);

		// Validate birthday
		isValid = 0;
		while (!isValid) {
			// Input
			printf("\nBirthday (dd/mm/yyyy): ");
			fflush(stdin);
			scanf("%d/%d/%d", &roomnumber[i].client.birth.dd, &roomnumber[i].client.birth.mm, &roomnumber[i].client.birth.yy);
			int day = roomnumber[i].client.birth.dd;
			int month = roomnumber[i].client.birth.mm;
			int year = roomnumber[i].client.birth.yy;

			//check year
			if (year >= 1900 && year <= 2100) {
				//check month
				if (month >= 1 && month <= 12) {
					//check days
					if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
						isValid = 1;
					else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
						isValid = 1;
					else if((day >= 1 && day <= 28) && (month == 2))
						isValid = 1;
					else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
						isValid = 1;
					else
						isValid = 0;
				}
				else {
					isValid = 0;
				}
			}
			else {
				isValid = 0;
			}

			// Notification
			if (isValid != 1) {
				textcolor(12);
				printf("Your input is unvalid. Please try again!\n");
				setcolor(9);
			}
			// !isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
		}
		
		// Validate sex
		isValid = 0;
		while (!isValid) {
			// Input
			printf("\nSex (M: Male/ F: Female/ O: Others):  ");
        	roomnumber[i].client.sex = getche();

			switch (roomnumber[i].client.sex) {
				case 'M':
				case 'm':
				case 'F':
				case 'f':
				case 'O':
				case 'o':
					isValid = 1;
					break;
				default:
					isValid = 0;
			};

			// Notification
			if (isValid != 1) {
				textcolor(12);
				printf("\nYour input is unvalid. Please try again!\n");
				setcolor(9);
			}
			// !isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
		}
		printf("\n");

        // Validate phone number
		{
			int c;
			char phone[15];
			RUN2: printf("\nPhone number: ");
			scanf("%s", phone);
			int length = strlen(phone);
			if( length != 10)
			{
				textcolor(12);
				printf("Phone number contains only 10 number characters!!! Please try again\n");
				setcolor(9);
				goto RUN2;
			}
			//check first number must be 0
			if(phone[0] != '0')
			{
				textcolor(12);
				printf("Phone number is not valid !!!\n");  // change
				setcolor(9);
				goto RUN2;
			}
			//check second number must be > 0
		    if(phone[1] == '0')
			{
				textcolor(12);
				printf("Phone number is not valid !!!\n");  // change
				setcolor(9);
				goto RUN2;
			}
			for (c = 2; c < 10; c++ ) 
			{
				if (phone[c] < '0' || phone[c] > '9') 
				{
					printf("Phone number is number !!! \n");
					goto RUN2;
				}
			}
			roomnumber[i].client.phone = atoi(phone);
		}








        // printf("\nEmail:  ");
        // scanf("%s", roomnumber[i].client.email);
		{
        int result1 = 0;
		RUN15:
        printf("\nEmail (Don't have email -->Type \"no\"): ");
        fflush(stdin);
        gets(roomnumber[i].client.email);                      
        trim(roomnumber[i].client.email);
        result1 = checkmail(roomnumber[i].client.email);  
        switch(result1){
            case 1:
            	textcolor(12);
   	        	printf("Your input is unvalid !!!\n");
   	            printf("Please input again\n");
   	            setcolor(9);
   	            goto RUN15;
    	        break;
          	case 2:
    	    	textcolor(12);
   	            printf("The end of mail must be @gmail.com !!!\n");
        	   	printf("Please input again\n");
        	   	setcolor(9);
    	        goto RUN15;
    	        break;
        }       	
    }


		// Print to "rooms.txt" file
		fprintf(fp, "%d, %d, %d/%d/%d, %d/%d/%d,", 
		roomnumber[i].id_room,
		roomnumber[i].longstay,
		roomnumber[i].checkin.dd, roomnumber[i].checkin.mm, roomnumber[i].checkin.yy,
		roomnumber[i].checkout.dd, roomnumber[i].checkout.mm, roomnumber[i].checkout.yy);

		fprintf(fp, "%s, %d/%d/%d, %c, %d, %s, ", 
	    roomnumber[i].client.name,
	    roomnumber[i].client.birth.dd, roomnumber[i].client.birth.mm, roomnumber[i].client.birth.yy,
	    roomnumber[i].client.sex,
	    roomnumber[i].client.phone,
	    roomnumber[i].client.email);   
	    		

        RUN6:
		printf("\n\nDo you want to add one more people press \"Y\" \n If NO press \"N\"");      	     		
        printf("\nY/N >>>  ");
		fflush(stdin);
        ch = getch();
        if (ch == 'N' || ch == 'n') {
			for (int a = 1; a <= 5; a++) fprintf(fp, "%d, ", roomnumber[i].service_in_use[a]);   	    			

			// Caluculate total pay
			roomnumber[i].total_pay = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
			// Print total pay to "rooms.txt"	
			fprintf(fp, "%d\n", roomnumber[i].total_pay);
		  	break; 
	} else if (ch == 'Y' || ch == 'y') {
         	roomnumber[i].numclient++;
     	        if (roomnumber[i].numclient > cost_room[h].max_people) {
				textcolor(12);
				printf("Sorry the room has max people !\n");
				setcolor(9);
				break;
		   } 
    	}
	else goto RUN6;

		// Print to "rooms.txt" file
		for (int a = 1; a <= 5; a++) fprintf(fp, "%d, ", roomnumber[i].service_in_use[a]);   	    			

		// Caluculate total pay
		roomnumber[i].total_pay = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
		// Print total pay to "rooms.txt"	
		fprintf(fp, "%d\n", roomnumber[i].total_pay);
   } 

	
	//Print total pay to screen
	printf("\nYour total bill: %d VND ", roomnumber[i].total_pay );  
	fclose(fp);	
    
    roomnumber[i].status = 1; // 1: Room has been booked
	textcolor(14);
	printf("\nSuccesfully requested booking\n");
	setcolor(9);
	printf("Press any key to return to main menu");
	getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}


void roomstatus(struct room_hotel *roomnumber){
	char *pc;
	FILE *f;
	f = fopen("rooms.txt", "r");

	int lineLength = 255, roomNum;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Read file to assign room.status = 1
    while (fgets(line, sizeof(line), f)) {
		if (line == "") break;

		// Split string with delimeters to struct
		// - Get room number
		char * token = strtok(line, ", ");
		roomNum = strtol(token, NULL, 10);

		roomnumber[roomNum].status = 1;
	}
	fclose(f);

    printf("\t\n\tRoom   \t  Category  \tPrice per night  \tAvailable\n");				
	for (i = 1; i <= 5; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \n\n", i,  cost_room[0].type, cost_room[0].price_per_night, pc);
	}
	for (i = 6; i <= 10; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \n\n", i,  cost_room[1].type, cost_room[1].price_per_night, pc);
	}
	for (i = 11; i <= 15; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \n\n", i,  cost_room[2].type, cost_room[2].price_per_night, pc);
	}
	for (i = 16; i <= 20; ++i) {
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                 %s  \n\n", i,  cost_room[3].type, cost_room[3].price_per_night, pc);
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//ham tinh khoang cach 2 ngay
int substract_2_days(int day1, int day2, int mon1, int mon2, int year1, int year2, int *day_diff, int *mon_diff, int *year_diff){
    if(day2 < day1)
    {      
        // borrow days from february
        if (mon2 == 3)
        {
            //  check whether year is a leap year
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            {
                day2 += 29;
            }
            else
            {
                day2 += 28;
            }                        
        }
        // borrow days from April or June or September or November
        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) 
        {
           day2 += 30; 
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           day2 += 31;
        }

        mon2 = mon2 - 1;
    }

    if (mon2 < mon1)
    { 
        mon2 += 12;
        year2 -= 1;
    }        

    *day_diff = day2 - day1;
    *mon_diff = mon2 - mon1;
    *year_diff = year2 - year1;

return *day_diff, *mon_diff, *year_diff;
}

//ham checkmail
int checkmail(char s[]){
   int result = 0;
   char *check;
   char reject[5] = "no";
   char end[12] = "@gmail.com";
                     
   if(s[0] == '\0') 
   result = 1;
   else if(strcmp(s, end) == 0)  
   result = 1;       //nguoi nhap no nhap@gmail.com
   else if(strcmp(s, reject) != 0){
   	    check = strstr(s, end); //kiem tra xem co mien mail
   	    if( strstr(s, end) == NULL) 
		result = 2;
		else if(strstr(s, end) != NULL){
			if(strcmp(check, end) != 0) 
			result = 2;
		}
   	}
    return result;
}
