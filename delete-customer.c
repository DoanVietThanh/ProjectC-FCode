//#include <stdio.h>
//#include <string.h>
//
//struct CustomerDetails   //STRUCTURE DECLARATION
//{
//	char roomnumber[10];
//	char name[20];
//	char address[25];
//	char phonenumber[15];
//	char nationality[15];
//	char email[20];
//	char period[10];
//	char arrivaldate[10];
//}s;

void deleteCustomer() {
	FILE *f, *t;
	char roomnumber[10],
		customerName[20];
	int isHaveRoom = 0;
	
//	Check if files are available
	f = fopen("add.txt", "r");
	t = fopen("temp.txt","w");
	if (f == NULL || t == NULL) exit(0);
	
//	Input a customer to cancel
	fflush(stdin);
	printf("Input a room number that you want to delete a customer: ");
	scanf("%s", &roomnumber);
	printf("Input a name of custumer that you want to delete: ");
	scanf("%s", &customerName);
	
	while (fread(&s, sizeof(s), 1, f) == 1) {
		if (strcmp(roomnumber, s.roomnumber) == 0 && strcmp(customerName, s.name) == 0)  {
			isHaveRoom = 1;
			//continue;
		} else
			fwrite(&s, sizeof(s), 1, t);
	}
	
//	Validate Notification
	if (isHaveRoom)
		printf("\nYour customer is removed successfully!");
	else {
		printf("Your room or your customer doesn't exist. Please try again!\n\n");
		main();
	}
	
//	File Handling
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt", "add.txt");
}
