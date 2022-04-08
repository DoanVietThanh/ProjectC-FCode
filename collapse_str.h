
char* ltrim(char s[]){
	int i=0;
	while(s[i] == ' ') i++;
	if(i>0) strcpy(&s[0], &s[i]); //
	return s;
}

char* rtrim(char s[]){
	int length = strlen(s);
	int i=length-1;
	while(s[i] == ' ') i--;
	s[i+1] = '\0'; /* add null sau chuoi*/
	return s;
}


char* trim(char s[]){
   rtrim(ltrim(s));
   char *ptr = strstr(s," ");//2 dau cach
   while(ptr != NULL){ //while two blanks exist
   	strcpy(ptr, ptr+1);   //remove one blank
   	ptr = strstr(s, " ");//2 dau cach
   }
   return s;
}