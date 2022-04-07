#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"book_management.h"
#include"library.h"
#include"librarian.h"
#include"login.h"
#include"utility.h"

Book Enter_book1(){
    Book book;
    printf("Please enter the bookID you want to remove: ");
    scanf("%d", &book.id);
    getchar();
    book.title = "0";
    book.authors = "0";
    book.year = 0;
    book.copies = 0;
    return book;
}

Book Enter_book(){
    Book book;
    char temp[100]="qwer";
    printf("Please enter the book title: ");
    scanf("%s", temp);
    book.title = (char*)malloc(strlen(temp)+1);
    strcpy( book.title,temp);
    getchar();
    printf("Please enter the book author: ");
    scanf("%s", temp);
    book.authors = (char*)malloc(strlen(temp)+1);
    strcpy(book.authors,temp);
    getchar();
    printf("Please enter the book year: ");
    scanf("%d", &book.year);
    getchar();
    printf("Please enter the book copies: ");
    scanf("%d", &book.copies);
    getchar();
    return book;
}
int remove_book(Book book){
    Book* p = a.list->next;
    Book* q = a.list;
    while(p->next != NULL){
        if (p->id == book.id){
            q->next = p->next;
            a.length -= 1;
            DeleteNode(p);
        }
        p = p->next;
        q = q->next;
    }
    if ((p->next) == NULL){
        if (p->id == book.id){
            q->next = NULL;
            a.length -= 1;
            DeleteNode(p);
        }
    }
    return 0;
}
int add_book(Book book) {
    Book *p = a.list->next;
    Book *q;
    while (p != NULL) {
        if ((strcmp(p->title, book.title)) == 0 && (strcmp(p->authors, book.authors)) == 0 && (p->year == book.year)){
            //p->copies = p->copies + book.copies;
            printf("NOOOOOO!\n");
            return 0;
        } else if (p->next == NULL) {
            book.next = NULL;
            a.length += 1;
            book.id = p->id+1;
            q = &book;
            p->next = q;
            q->next = NULL;
            printf("Successfully add!\n");
            return 0;
        }
        p = p->next;
    }
}
void LibrarianLogin(){
	int on_off = 1;
	char temp;
	getchar();
	while(on_off) {
		printf("--------Welcome! Dear Librarian!--------\n");
		printf("***  Menu  ***\n");
		printf("1.Add book\n2.Remove Book\n3.Search the book\n4.Display the book list\n5.log out\n");
		printf("Please Enter the option: ");
		scanf("%c",&temp);
		getchar();
		if (temp == '1') {
			printf("Add book\n");
			add_book(Enter_book());
			PrintBook(a);
		}
		else if (temp == '2') {
			printf("Remove Book\n");
            PrintBook(a);
			remove_book(Enter_book1());
            PrintBook(a);
		}
		else if (temp == '3') {
			printf("Search Books\n");
			Search(a.list);
		}
		else if (temp == '4') {
			printf("Display the book list\n");
			PrintBook(a);
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

