#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"book_management.h"
#include"library.h"
#include"librarian.h"
#include"login.h"
#include"user.h"
#include"utility.h"

void load_users() {
        User* h, * p, * last;
        CreateNode1(h);
        last = h;
        h->next = NULL;
        CreateNode1(p);
        p->next = NULL;
       // p->Username[40] = "librarian";
       // p->Password[40] = "librarian";
        b.length = 0;
        last->next = p;
        last = p;
        b.list = h;
    }

void InitializeLibrary(FILE*file){
    printf("Initializing........\n");
	load_books(file);
	load_users();
	printf("Successfully initialize!\n\n");
}

void Register(User* list){
    char buf[100];
    User* p = list->next;
    User* f = list;
    User* q;
    CreateNode1(q);
    q->borrowNumber = 0;
    printf("Please enter your username: ");
    scanf("%s",q->Username);
    getchar();
    f=f->next;
    while(f->next != NULL){
        printf("1");
        if (strcmp(f->Username,q->Username) == 0){
            printf("Sorry! The account name is used, please change the Username!\n");
            return;
        }
        f = f->next;
    }
    printf("Please enter your password: ");
    scanf("%s",q->Password);
    getchar();
    while (p ->next != NULL) {
        p = p->next;
    }
    p->next = q;
    q->next = NULL;
    printf("Registering.......\n");
    printf("Successfully register!!\nYour can login by choosing second option!\n\n");
}

int load_books(FILE* file){
    if ((file = fopen("books.txt", "r")) == NULL) {
        printf("Error\nBook file does not exist");
        return 0;
    } else {
        file = fopen("books.txt", "r");
        int x;
        Book *h, *p, *last;
        char buf[100];
        CreateNode(h);
        h->next = NULL;
        last = h;
        a.list = h;
        while (fgets(buf, 100, file) != NULL) {
            CreateNode(p);
            p->title = (char *) malloc(100);
            p->authors = (char *) malloc(100);
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

void LibraryOpen(FILE *file){
	InitializeLibrary(file);
	int on_off = 1;
	char temp;
	while (on_off) {
		printf("***  Menu  ***\n");
		printf("1.Register a account\n2.Login\n3.Search the book\n4.Display the book list\n5.Exit\n");
		printf("Please Enter the option: ");
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Register an account\n");
			Register(b.list);
			//PrintUser(b.list);
		}
		else if (temp == '2') {
			printf("Login\n");
			Login(b.list);
		}
		else if (temp == '3') {
			printf("Search the book\n");
			Search(a.list);
		}
		else if (temp == '4') {
			printf("Display the book\n");
			PrintBook(a);
		}
		else if (temp == '5') {
			on_off = 0;
			printf(" Thank you to use the library management system!\nGoodbye!\n");
		}
		else {
			printf("Unknown number!\nPlease enter again!\n");
		}
	}
}