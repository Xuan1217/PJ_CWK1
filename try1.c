#include<stdio.h>
#include"book_management.h"
#include<stdlib.h>
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
int Option(void){
	int option = -1;
	char Enter[80];
	fgets(Enter, 80, stdin);
	option = (int)atoi(Enter);
	return option;
}
void LibraryOpen(FILE *file) {
	InitializeLibrary(file);
	int on_off = 1;
	int temp;
	while (on_off) {
		printf("Menu\n");
		printf("1.Register a account\n2.Login\n3.Search the book\n4.Display the book list\n5.Exit\n");
		printf("Please Enter the option: ");
		temp = Option();
		if (temp == 1) {
			printf("Register an account\n");
			//Register();
		}
		else if (temp == 2) {
			printf("Login");
			//Login();
		}
		else if (temp == 3) {
			printf("Search the book\n");
			//Search_Book();
		}
		else if (temp == 4) {
			printf("Display the book\n");
			PrintBook(a.list);
		}
		else if (temp == 5) {
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