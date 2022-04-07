#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"book_management.h"
#include"utility.h"

BookList find_book_by_year(unsigned int year){
    BookList S_year;
    Book *h, *last;
    CreateNode(h);
    h->next = NULL;
    last = h;
    S_year.list = h;
    Book* q = a.list->next;
    while(q->next != NULL){
        if (q->year == year){
            Book *p;
            CreateNode(p);
            p->title = (char *) malloc(100);
            p->authors = (char *) malloc(100);
            p->next = NULL;
            p->id = q->id;
            strcpy(p->title, q->title);
            strcpy(p->authors, q->authors);
            p->year = q->year;
            p->copies = q->copies;
            last->next = p;
            last = p;
        }
        q = q->next;
    }
    return S_year;
}

BookList find_book_by_author(const char* author){
    BookList S_author;
    Book *h, *last;
    CreateNode(h);
    h->next = NULL;
    last = h;
    S_author.list = h;
    Book* q = a.list->next;
    while(q->next != NULL){
        if ((strcmp(q->authors,author)) == 0){
            Book *p;
            CreateNode(p);
            p->title = (char *) malloc(100);
            p->authors = (char *) malloc(100);
            p->next = NULL;
            p->id = q->id;
            strcpy(p->title, q->title);
            strcpy(p->authors, q->authors);
            p->year = q->year;
            p->copies = q->copies;
            last->next = p;
            last = p;
        }
        q = q->next;
    }
    return S_author;
}

BookList find_book_by_title(const char* title){
    BookList S_title;
    Book *h, *last;
    CreateNode(h);
    h->next = NULL;
    last = h;
    S_title.list = h;
    Book* q = a.list->next;
    while(q->next != NULL){
        if ((strcmp(q->title,title)) == 0){
            Book *p;
            CreateNode(p);
            p->title = (char *) malloc(100);
            p->authors = (char *) malloc(100);
            p->next = NULL;
            p->id = q->id;
            strcpy(p->title, q->title);
            strcpy(p->authors, q->authors);
            p->year = q->year;
            p->copies = q->copies;
            last->next = p;
            last = p;
        }
        q = q->next;
    }
    return S_title;
}

void PrintBook(BookList list) {
    Book* p = list.list->next;
    printf("ID\tTitle\t%%20sAuthors\tYear\tCopies\t\n");
    while (p != NULL) {
        printf("%d\t%20s\t%20s\t%d\t%d\t\n", p->id, p->title, p->authors, p->year, p->copies);
        p = p->next;
    }
}
void Search(Book* list) {
    char buff[100];
    int bufff;
    int on_off = 1;
    char temp;
    while (on_off) {
        printf("1.Find book by title\n2.Find book by authors\n3.Find book by year\n4.Exit\n");
        printf("Please Enter the option: ");
        scanf("%c", &temp);
        getchar();
        if (temp == '1') {
            printf("Find book by title\n");
            printf("Enter the title you wanna to search: ");
            scanf("%s",buff);
            PrintBook(find_book_by_title(buff));
            getchar();
        }
        else if (temp == '2') {
            printf("Find book by author\n");
            printf("Enter the title you wanna to search: ");
            scanf("%s",buff);
            PrintBook(find_book_by_author(buff));
            getchar();
        }
        else if (temp == '3') {
            printf("Find book by year\n");
            printf("Enter the title you wanna to search: ");
            scanf("%d",&bufff);
            PrintBook(find_book_by_year(bufff));
            getchar();
        }
        else if (temp == '4') {
            on_off = 0;
            printf("Exit.....\n");
        }
        else {
            printf("Unknown number!\nPlease enter again!\n");
        }
    }
}


