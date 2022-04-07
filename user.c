#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"book_management.h"
#include"user.h"
#include"utility.h"
#include"librarian.h"

void Return(char Username[40]){
    int temp;
    int i;
    Book B;
    printf("Enter the bookID you wanna to return: ");
    scanf("%d",&temp);
    B.id = temp;
    Book *p = a.list->next;
    User *q = b.list->next;
    while(q != NULL){
        if ((strcmp(Username, q->Username)) == 0){
            for(i = 0; i < q->borrowNumber; i++){
                if ((q->borrowed[i]->id) == temp){
                    remove_book(B);
                }
            }
        }
    }
}

void Borrowed(char Username[40]){
    int temp;
    Book B;
    PrintBook(a);
    printf("Enter the bookID you wanna to borrow: ");
    scanf("%d",&temp);
    getchar();
    B.id = temp;
    Book *p = a.list->next;
    User *q = b.list->next;
    while(p != NULL){
        if (temp == p->id){
            while(q != NULL){
                if ((strcmp(Username, q->Username)) == 0){
                    q->borrowed[q->borrowNumber] = p;
                    q->borrowNumber += 1;
                    if ((p->copies) > 1){
                        p->copies -= 1;
                        break;
                    }
                    if((p->copies) == 1){
                        remove_book(B);
                    }
                    break;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
}
void PrintMy_book(char Username[40]){
    User *p = b.list->next;
    while(p != NULL){
        if ((strcmp(Username, p->Username)) == 0){
            printf("ID\tTitle\tAuthors\t\tYear\n");
            for(int i=0; i < p->borrowNumber; i++){
                printf("%d\t%s\t%s\t\t%d\n", p->borrowed[i]->id, p->borrowed[i]->title,p->borrowed[i]->
                authors, p->borrowed[i]->year);
            }
        }
        p = p->next;
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
        printf("1.Borrowed book\n2.Return Book\n3.Search the book\n4.Display the book list\n5.Check My book\n6.log out\n");
        printf("Please Enter the option: ");
        scanf("%c", &temp);
        getchar();
        if (temp == '1') {
            printf("Borrowed book\n");
            Borrowed(username);
        }
        else if (temp == '2') {
            printf("Return Book\n");
            //Return();
            getchar();
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
            printf("Check My book\n");
            PrintMy_book(username);
        }
        else if (temp == '6') {
            on_off = 0;
            printf("Log out......\n");
        }
        else {
            printf("Unknown number!\nPlease enter again!\n");
        }
    }
}
