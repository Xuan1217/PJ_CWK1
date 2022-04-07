#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"book_management.h"
#include"login.h"
#include"librarian.h"
#include"user.h"
void Login(User* list) {
	User* p = list->next;
	char temU[100];
	char temP[100];
	printf("Please enter the username: ");
	scanf("%s", temU);
	getchar();
	if (!strcmp(temU, "librarian")) {
		printf("Successfully found your account!\nPlease enter your password: ");
		scanf("%s", temP);
		if (!strcmp(temP, "librarian")) {
			printf("Successfully login!\n");
			LibrarianLogin();
		}
		else {
			printf("Error password!\n");
			exit(0);
		}
	}
	else {
		while (p != NULL) {
			if ((strcmp(temU, p->Username)) == 0) {
				printf("Successfully found your account!\nPlease enter your password: ");
				scanf("%s", temP);
				getchar();
				if ((strcmp(temP, p->Password)) == 0) {
					printf("Successfully login!\n");
                    getchar();
					OtherLogin(temU);
				}
				else {
					printf("Error password!\n");
					return ;
				}
			}
			p = p->next;
		}
		printf("Sorry! Can't find your account, please register first!\n");
	}
}
