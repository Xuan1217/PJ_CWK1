#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"book_management.h"
#include"user.h"
#include"utility.h"

void Borrowed(char Username[40]){
    int temp;
    printf("Enter the bookID you wanna to borrow: ");
    scanf("%d",&temp);
    Book *p = a.list->next;
    User *q = b.list->next;
    while(p->next != NULL){
        if (temp == p->id){
            while(q->next != NULL){
                if ((strcmp(Username, q->Username)) == 0){
                    q->borrowed[q->borrowNumber] = p;
                    q->borrowNumber += 1;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
}
void PrintMybook(char Username[40]){
    User *p = b.list->next;
    while(p->next != NULL){
        if ((strcmp(Username, p->Username)) == 0){
            printf("ID\tTitle\tAuthors\t\tYear\tCopies\t\n");
            printf("%d\t%s\t%s\t\t%d\t  %d\t\n", p->borrowed[p->borrowNumber]->id, p->borrowed[p->borrowNumber]->title,
                   p->borrowed[p->borrowNumber]->authors, p->borrowed[p->borrowNumber]->year, p->borrowed[p->borrowNumber]->copies);
        }
    }
}
void OtherLogin(char username[40]) {
    int on_off = 1;
    char temp;
    getchar();
    printf("************  Welcome!  *************\n");
    while (on_off) {
        printf("Now is %s\n", username);
        printf("***  Menu  ***\n");
        printf("1.Borrowed book\n2.Return Book\n3.Search the book\n4.Display the book list\n5.log out\n");
        printf("Please Enter the option: ");
        scanf("%c", &temp);
        getchar();
        if (temp == '1') {
            printf("Borrowed book\n");
            Borrowed(username);
            PrintMybook(username);
        }
        else if (temp == '2') {
            printf("Return Book\n");
            //Return();
        }
        else if (temp == '3') {
            printf("Search the book\n");
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
