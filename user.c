#include<stdio.h>
#include"book_management.h"
#include<stdlib.h>
#include<string.h>
void OtherLogin(char username[40]) {
	int on_off = 1;
	char temp;
	printf("************  Welcome!  *************\n");
	while (on_off) {
		printf("Account: %s\n", username);
		printf("Menu\n");
		printf("1.Borrowed book\n2.Return Book\n3.Search the book\n4.Display the book list\n5.log out\n");
		printf("Please Enter the option: ");
		getchar();
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Borrowed book\n");
			//Borrowed();
		}
		else if (temp == '2') {
			printf("Return Book\n");
			//Return();
		}
		else if (temp == '3') {
			printf("Search the book\n");
			//Search_Book();
		}
		else if (temp == '4') {
			printf("Display the book list\n");
			//Display_list();
		}
		else if (temp == '5') {
			on_off = 0;
			printf("Log out......\n");
		}
		else {
			printf("Unknown number!\nPlease enter again!\n");
		}
	}
}
