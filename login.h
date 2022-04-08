struct login                           // before the first use of `l`.
{
    char username[30];
    char password[30];
} l;

//#define createLoginSystem main

void login(void) {
    system("cls");

    int i = 0;
    char username[30], password[30], c;
    FILE *log;
 
    log = fopen("account.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    textcolor(14);
    printf("\nPlease Enter your login credentials below\n\n");
    setcolor(9);
    fflush(stdin);

    printf("Username:  ");
    scanf("%s", &username);
    
    

    printf("\nPassword: ");
 /*   // fgets(password, 30, stdin);
    while (i < 30) {
	    password[i] = getch();
	    c = password[i];
	    if (c==13) break; else printf("*");
	    i++;
	}
	password[i]='\0'; */
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 	const int maxPL = 30; //maxPl
 	password[maxPL + 1];
 	char ch;
 	int characterPosition = 0;
// 	printf("Please Enter password. Length 1 - %d\n", maxPL);
 	
 	while (1){
 		ch = getch();
 		if(ch == 13) //when user hits ENTER button
 	    	break;
 		else if(ch == 8){ //when user hits Backspace key
 		    if(characterPosition > 0){
 		    	characterPosition--;
 		       password[characterPosition] = '\0';
 		       printf("\b \b"); // cho nay chua hieu	
			 }
	   }else if(ch == 32 || ch == 9){ //when user hits space or tab
	        continue; 	    
	   }else{
	   	    if(characterPosition < maxPL) {
	   	    	password[characterPosition] = ch; //vd gan ki tu dau tien dang dc luu tru trong ch sang password[0]
	   	    	characterPosition ++;
	   	    	printf("*");
			}
//			else{
//				printf("\nYour input exceeds maximum password length of %d.  So only firts %d characters will be consider", maxPL, maxPL);
//				break;
//			}
	   }
    }
    password[characterPosition] = '\0';
    if(strlen(password) == 0) printf("\nNo password entered");
//    else printf("\nPass is %s", password);
    
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Get first line
    while (fgets(line, sizeof(line), log)) {
        // Split string with delimeters to struct (Get username and pass)
        char * token = strtok(line, " ");
        if (token != NULL) strcpy(l.username, token);

        token = strtok(NULL, "");
        if (token != NULL) strcpy(l.password, token);
    }

    if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0) {
        textcolor(6);
        printf("\n\nSuccessful Login\n");
        setcolor(9);
    } else {
        textcolor(12);
        printf("\n\nIncorrect Login Details !!!\n"); // change do
        setcolor(9);
        printf("\nPlease enter the correct credentials\n");
        printf("Press 'A': Type again\n");
        printf("Press 'C': Create an account if you don't have any account\n");
        c = getch();
        if (c == 'a' || c == 'A') {
            login();
        } else if (c == 'c' || c == 'C') {
                registration();
        } else {
            printf("Invalid input. Please try again!");
            getch();
            home();
        }
    } 

    printf("\nPress any key to continue...");
    getch();
    mainMenu();
    fclose(log);
    return;
}
 
void registration(void) { 
    system("cls");
    int i = 0;
    char name[15], c;
    FILE *log;
    log = fopen("account.txt", "w");
    if (log == NULL) {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    textcolor(14);
    printf("\nWe need to enter some details for registration.\n\n");
    setcolor(9);
    printf("\nEnter Username : ");
    scanf("%s", l.username);
/*    while (i < 30) {
	    l.password[i] = getch();
	    c = l.password[i];
	    if (c==13) break; else  printf("*"); 
		//else if (c != 8 && c!= 9 && c != 127) printf("*");
	    i++;
	}
	l.password[i] = '\0'; */
	
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 	const int maxPL = 30; //maxPl
 	l.password[maxPL + 1];
 	char ch;
 	int characterPosition = 0;
 	printf("Enter password (Length 1 - %d) : ", maxPL);
 	
 	while (1){
 		ch = getch();
 		if(ch == 13) //when user hits ENTER button
 	    	break;
 		else if(ch == 8){ //when user hits Backspace key
 		    if(characterPosition > 0){
 		    	characterPosition--;
 		       l.password[characterPosition] = '\0';
 		       printf("\b \b"); // cho nay chua hieu	
			 }
	   }else if(ch == 32 || ch == 9){ //when user hits space or tab
	        continue; 	    
	   }else{
	   	    if(characterPosition < maxPL) {
	   	    	l.password[characterPosition] = ch; //vd gan ki tu dau tien dang dc luu tru trong ch sang password[0]
	   	    	characterPosition ++;
	   	    	printf("*");
			}
			else{
				printf("\nYour input exceeds maximum password length of %d.  So only firts %d characters will be consider", maxPL, maxPL);
				break;
			}
	   }
    }
    l.password[characterPosition] = '\0';
    if(strlen(l.password) == 0) printf("\nNo password entered");
    else printf("\nYour Password is : %s", l.password);	
	
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    fprintf(log, "%s %s", l.username, l.password);
    fclose(log);
    textcolor(14);
    printf("\n\nRegistration Successful!\n");
    setcolor(9);
    printf("\nPress any key to continue...");
    getch();
    system("CLS");
    login();
}