#include<stdio.h>
#include"book_management.h"
#include<stdlib.h>
#include<string.h>
void LibrarianLogin() {
	int on_off = 1;
	char temp;
	while(on_off) {
		printf("Welcome! Dear Librarian!\n");
		printf("Menu\n");
		printf("1.Add book\n2.Remove Book\n3.Search the book\n4.Display the book list\n5.log out\n");
		printf("Please Enter the option: ");
		getchar();
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Add book\n");
			//add_book;
		}
		else if (temp == '2') {
			printf("Remove Book\n");
			//Remove();
		}
		else if (temp == '3') {
			printf("funtion3\n");
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

