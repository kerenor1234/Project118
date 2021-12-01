#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
	char* mail, * password, * name, * phone;
}Employer;

bool signUpEmployer(Employer* emp) {
	bool allocate = true, succees = false;
	char input[100];
	printf("SIGN UP:\n Enter company name: ");
	scanf("%s", input);
	emp->name = (char*)malloc(strlen(input) + 1);
	if (emp->name)strcpy(emp->name, input);
	else allocate = false;

	printf("Enter company phone number:");
	scanf("%s", input);
	emp->phone = (char*)malloc(strlen(input) + 1);
	if (emp->phone)strcpy(emp->phone, input);
	else allocate = false;


	printf("Enter company mail:");
	scanf("%s", input);
	emp->mail = (char*)malloc(strlen(input) + 1);
	if (emp->mail)strcpy(emp->mail, input);
	else allocate = false;

	//do {
		printf("Enter your Password:");
		scanf("%s", input);
	//} while (!checkPassword(input));
	emp->password = (char*)malloc(strlen(input) + 1);
	if (emp->password)strcpy(emp->password, input);
	else allocate = false;

	do {
		printf("Reenter your password:");
		scanf("%s", input);
	} while (allocate && strcmp(emp->password, input) != 0);
	succees = true;
	return allocate && succees;
}
bool add_employer_toFiles(Employer* emp) {
	bool sign_up = signUpEmployer(emp);
	char line[255];
	if (sign_up) {
		FILE* ud = fopen("Book1.csv", "a+");
		if (ud) {
			fprintf(ud, "%s, %s, %s, %s, %s, %s\n", emp->mail, emp->password, emp->name, emp->phone);
			fclose(ud);
			return true;
		}
	}
	return false;
}
bool logInEmployer()
{
	bool s = false;
	char str[50] = "";
	char pass[12] = "";
	printf("Enter mail: ");
	scanf("%s", str);
	//strcpy(pass, get_pass_by_mail(str));
	printf("Enter password: ");
	scanf("%s", str);
	if (strcmp(str, pass))
	{
		s = true;
	}
	return s;


}


	int main() 
	{
		
		Employer* e =new Employer;
		bool add_to_file = add_employer_toFiles(e);
		printf(add_to_file ? "%s %s added to the files succeessfully\n" : "%s %s arn't added to the files\n", e->mail, e->password, e->name, e->phone);
}
