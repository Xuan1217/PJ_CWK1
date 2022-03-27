#include<stdio.h>
#include"book_management.h"
#include<stdlib.h>
#include<string.h>
void InitializeLibrary(FILE*file) {
	load_books(file);
	load_users();
	printf("Successfully initialize!\n");
}

void load_users() {
	User* h, * p, * last;
	CreateNode(h);
	last = h;
	b.list = h;
	h->next = NULL;
	CreateNode(p);
	p->next = NULL;
	p->Username[40] = "librarian";
	p->Password[40] = "librarian";
	b.Userlength += 1;
	last->next = p;
	last = p;
}

void Login() {
	User* p;
	char temU[100];
	char temP[100];
	printf("Please enter the username: ");
	scanf("%s", temU);
	if (!strcmp(temU,"librarian")) {
		printf("Successfully found your account!\nPlease enter your password: ");
		scanf("%s", temP);
		if (!strcmp(temP,"librarian")) {
			printf("Successfully login!\n");
			LibrarianLogin();
		}
		else {
			printf("Error password!");
			exit(0);
		}
	}
	else {
		while (p != NULL) {
			if (p->Username == temU) {
				printf("Successfully found your account!\nPlease enter your password: ");
				scanf("%s", temP);
				if (p->Password == temP) {
					printf("Successfully login!\n");
					OtherLogin(temU);
				}
			}
		}
	}
	}

void LibrarianLogin() {
	int on_off = 1;
	char temp;
	while(on_off) {
		printf("Welcome! Dear Librarian!");
		printf("Menu\n");
		printf("1.Add book\n2.Remove Book\n3.Search the book\n4.Display the book list\n5.log out\n");
		printf("Please Enter the option: ");
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Add book");
			//add_book;
		}
		else if (temp == '2') {
			printf("Remove Book");
			//Remove();
		}
		else if (temp == '3') {
			printf("funtion3");
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
			printf("Unknown number!\nPlease enter again!");
		}
	}
}
void OtherLogin(char username) {
	int on_off = 1;
	char temp;
	printf("************  Welcome!  *************\n");
	
	while (on_off) {
		printf("Now is %s\n", username);
		printf("Menu\n");
		printf("1.Borrowed book\n2.Return Book\n3.Search the book\n4.Display the book list\n5.log out\n");
		printf("Please Enter the option: ");
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Borrowed book");
			//Borrowed();
		}
		else if (temp == '2') {
			printf("Return Book");
			//Return();
		}
		else if (temp == '3') {
			printf("Search the book");
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
			printf("Unknown number!\nPlease enter again!");
		}
	}
}
void Register(User* list) {
	char buf[100];
	User* p = list->next;
	User* q;
	CreateNode(q);
	printf("Please enter your username: ");
	scanf("%s",q->Username);
	getchar();
	printf("Please enter your password: ");
	scanf("%s",q->Password);
	getchar();
	while (p ->next != NULL) {
		p = p->next;
	}
			p->next = q;
			q->next = NULL;
}

int CheckName(char username[40], User* list) {
	User* p = list->next;
	while (p != NULL) {
		if (strcmp(p->Username[40], username[40]) == 0) {
			return 1;
		}
		p = p->next;
	}
	return 0;
}
int load_books(FILE* file) {
	if ((file = fopen("books.txt", "r")) == NULL) {
		printf("Error\nBook file does not exist");
		return 0;
	}
	else {
		file = fopen("books.txt", "r");
		int x;
		Book* h, * p, * last;
		char buf[100];
		CreateNode(h);
		h->next = NULL;
		last = h;
		a.list = h;
		while (fgets(buf, 100, file) != NULL) {
			CreateNode(p);
			p->title = (char*)malloc(100);
			p->authors = (char*)malloc(100);
			buf[strlen(buf) - 1] = '\0';
			p->next = NULL;
			sscanf(buf, "%d\n", &p->id);
			fgets(buf, 100, file);
			sscanf(buf, "\%[^\n]", p->title);
			fgets(buf, 100, file);
			sscanf(buf, "\%[^\n]", p->authors);
			fgets(buf, 100, file);
			sscanf(buf, "%d\n", &p->year);
			fgets(buf, 100, file);
			sscanf(buf, "%d\n", &p->copies);
			a.length += 1;
			last->next = p;
			last = p;
		}
		return 1;
	}
}

void PrintBook(Book*list) {
	Book* p = list->next;
	while (p != NULL) {
		printf("id:%d\n", p->id);
		printf("title:%s\n", p->title);
		printf("author:%s\n", p->authors);
		printf("year:%d\n", p->year);
		printf("copies:%d\n", p->copies);
		p = p->next;
	}
}

void LibraryOpen(FILE *file) {
	InitializeLibrary(file);
	int on_off = 1;
	char temp;
	while (on_off) {
		printf("Menu\n");
		printf("1.Register a account\n2.Login\n3.Search the book\n4.Display the book list\n5.Exit\n");
		printf("Please Enter the option: ");
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Register an account\n");
			Register(b.list);
		}
		else if (temp == '2') {
			printf("Login\n");
			Login();
		}
		else if (temp == '3') {
			printf("Search the book\n");
			//Search_Book();
		}
		else if (temp == '4') {
			printf("Display the book\n");
			PrintBook(a.list);
		}
		else if (temp == '5') {
			on_off = 0;
			printf(" Thank you to use the library mangement system!\nGoodbye!\n");
		}
		else {
			printf("Unknown number!\nPlease enter again!\n");
		}
	}
}
int main(){
FILE *fp;
LibraryOpen(fp);
return 0;}
