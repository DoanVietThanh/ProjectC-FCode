void edit()
{
    system("cls");
    FILE *f, *t;
    f = fopen("rooms.txt", "r");
    t = fopen("temp.txt", "w");
    if (f == NULL) exit(0);
 
    int k = 1, price_per_night2;
    char roomNumber[20];
    textcolor(14);
    printf("Enter Room number of the customer to edit: ");
    setcolor(9);
    scanf("%s", roomNumber);
    fflush(stdin);
 
    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */
 
    // Loop each line
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
            k = 0;
 
            // Validate longstay
            char c;
            RUN10:
                textcolor(14);
                printf("\n* Maximum number of nights can book is 30 *\n");
                setcolor(9);
                printf("Enter period (\'x\'nights) : ");
                fflush(stdin);
                if (scanf("%d%c", &s.longstay2, &c) != 2 || c != '\n' || s.longstay2 <= 0 || s.longstay2 > 30)
                {
                    textcolor(12);
                    printf("Error\n");
                    setcolor(9);
                    goto RUN10;
            }
 
            RUN14:
            // Validate checkin
            isValid = 0;
            while (!isValid) {
                // Input
                printf("\nEnter day you checkin (dd/mm/yy): ");
                fflush(stdin);
                s.checkin2.dd = 0;
                s.checkin2.mm = 0;
                s.checkin2.yy = 0;
                scanf("%d/%d/%d", &s.checkin2.dd,  &s.checkin2.mm,  &s.checkin2.yy);
                int day = s.checkin2.dd;
                int month = s.checkin2.mm;
                int year = s.checkin2.yy;
 
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
                s.checkout2.dd = 0;
                s.checkout2.mm = 0;
                s.checkout2.yy = 0;
                scanf("%d/%d/%d", &s.checkout2.dd, &s.checkout2.mm, &s.checkout2.yy);  
                int day = s.checkout2.dd;
                int month = s.checkout2.mm;
                int year = s.checkout2.yy;
 
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
                    } else {
                        isValid = 0;
                    }
                } else {
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
            substract_2_days(s.checkin2.dd, s.checkout2.dd,
                            s.checkin2.mm, s.checkout2.mm,
                            s.checkin2.yy, s.checkout2.yy,
                            &day_diff, &mon_diff, &year_diff                    
                            );
            textcolor(14);
            printf("\nDifference: %d years %2d months and %2d days.\n", year_diff, mon_diff, day_diff);
            setcolor(9);
            // truong hop 30 dem tuc 31 ngay la tron 1 thang
            if(day_diff != s.longstay2 || year_diff !=0 || mon_diff != 0 ){
                textcolor(12);
                printf("\nThe nights between checkin date and checkout date is not valid !!!");
                printf("\nPlease input again");
                setcolor(9);
                goto RUN14;
            }
 
 
 
            printf("\n\nEnter your fullname: ");
            fflush(stdin);
            gets(s.name2);
 
            // Validate birthday
            isValid = 0;
            while (!isValid) {
                // Input
                printf("\nBirthday (dd/mm/yyyy):");
                fflush(stdin);
                s.birth2.dd = 0;
                s.birth2.mm = 0;
                s.birth2.yy = 0;
                scanf("%d/%d/%d", &s.birth2.dd, &s.birth2.mm, &s.birth2.yy);
                int day = s.birth2.dd;
                int month = s.birth2.mm;
                int year = s.birth2.yy;
 
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
                // scanf("%s", s.sex2[1]);
                s.sex2[1] = getche();
                switch (s.sex2[1])
                {
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
 
            // Validate phone number
            {
                int c;
                char phone[15];
                RUN2: printf("\n\nPhone number: ");
                scanf("%s", phone );
                int length = strlen(phone);
                if( length != 10) {
                    textcolor(12);
                    printf("Phone number contains only 10 number characters ! \n");
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
                s.phone2 = atoi(phone);
            }
 
 
 
 
            // printf("\nEmail:  ");
            // scanf("%s", &s.email2);

            {
        int result1 = 0;
		RUN25:
        printf("\nEmail (Don't have email -->Type \"no\"): ");
        fflush(stdin);
        gets(s.email2);                      
        trim(s.email2);
        result1 = checkmail(s.email2);  
        switch(result1){
            case 1:
            	textcolor(12);
   	        	printf("Your input is unvalid !!!\n");
   	            printf("Please input again\n"); 
   	            setcolor(9);
   	            goto RUN25;
    	        break;
          	case 2:
    	    	textcolor(12);
   	            printf("The end of mail must be @gmail.com !!!\n");
        	   	printf("Please input again\n");
        	   	setcolor(9);
    	        goto RUN25;
    	        break;
            }       	
        }

            printf("\n\nWe have these services\n");
            printf("1. Dry cleaning \t : 100.000\n");
            printf("2. Massages \t\t : 100.000\n");
            printf("3. Car rent \t\t : 200.000\n"); 
            printf("4. Eating buffet \t : 200.000\n");
            printf("5. Guided tours \t : 400.000\n");
            textcolor(14);
            printf("\nNote: If you want to use service 1 type \" 1 for YES or 0 for NO \" ");
            setcolor(9);
            fflush(stdin);
            int a, check[6];
 
            printf("\n\nLet choose :\n");
        RUN3:   for(int a=1; a <= 5; a++){
                printf("\nChoose service %d (Yes / No): ", list_service[a-1].id);
                check[a] = scanf("%d", &s.service_in_use2[a]);
                fflush(stdin);
            }
            for(int a=1; a <= 5; a++){
                if(check[a] == 0) {
                        textcolor(12);
                        printf("\n ERROR !!! \n");
                        printf("\nPlease input again ");
                        setcolor(9);
                    goto RUN3;
                }
                if(check[a] == 1) {
                    if(s.service_in_use2[a] == 0){
                        cost_service[a] = 0;    
                    }
                    else if(s.service_in_use2[a] == 1) {
                        cost_service[a] = list_service[a - 1].price_service;    
                    } else {
                        textcolor(12);
                        printf("\n ERROR !!! \n");
                        printf("\nPlease input again ");
                        setcolor(9);
                        goto RUN3;
                    }  
                }
            }
            // fseek(f, size, SEEK_CUR);  //to go to desired position infile
            fprintf(t, "%d, %d, %d/%d/%d, %d/%d/%d,",
            s.room2,
            s.longstay2,
            s.checkin2.dd, s.checkin2.mm, s.checkin2.yy,
            s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);
 
            fprintf(t, "%s, %d/%d/%d, %c, %d, %s, ",
            s.name2,
            s.birth2.dd, s.birth2.mm, s.birth2.yy,
            s.sex2[1],
            s.phone2,
            s.email2);
           
            for (int a = 1; a <= 5; a++)
                fprintf(t, "%d, ", s.service_in_use2[a]);
 
            if (s.room2 >= 1 && s.room2 <= 5) {
                price_per_night2 = 500000;
            } else if (s.room2 >= 6 && s.room2 <= 10) {
                price_per_night2 = 700000;
            } else if (s.room2 >= 11 && s.room2 <= 15) {
                price_per_night2 = 900000;
            } else if (s.room2 >= 16 && s.room2 <= 20) {
                price_per_night2 = 1100000;
            }
           
            s.total_pay2 = s.longstay2 * (price_per_night2 + s.service_in_use2[1] + s.service_in_use2[2] + s.service_in_use2[3] + s.service_in_use2[4] + s.service_in_use2[5]);
            fprintf(t, "%d\n", s.total_pay2);
            // break;
        } else {
            // Print to "temp.txt"
            fprintf(t, "%s", line2);
        }
    }
 
    if (k == 1) {
        textcolor(12);
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
        setcolor(9);
    } else {
        textcolor(14);
        printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
        setcolor(9);
    }





    //  File handling
    fclose(f);
    fclose(t);
    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");
 
    // Go back to main menu
    printf("Press any key to go back to main menu");
    getch();
    mainMenu();
}


    //ham checkmail
    int checkmail2(char s[]){
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