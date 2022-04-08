#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#include"book_management.h"
#include"user.h"
#include"utility.h"
#include"librarian.h"

void load_U(char *Uname){
    char name[100],buf[100];
    int i = 0;
    strcpy(name,Uname);
    strcat(Uname,"B.txt");
    FILE *f = fopen(Uname,"r");
    User *p = b.list->next;
    while(strcmp(p->Username,name)!=0){
        p = p->next;
    }
    while(fgets(buf,100,f)!=NULL){
        p->borrowed[i]->id = atoi(buf);
        fgets(buf,100,f);
        strcpy(p->borrowed[i]->title,buf);
        fgets(buf,100,f);
        strcpy(p->borrowed[i]->authors,buf);
        fgets(buf,100,f);
        p->borrowed[i]->year = atoi(buf);
        fgets(buf,100,f);
        p->borrowed[i]->copies = atoi(buf);
    }
}

void store_user(){
    FILE*U;
    U = fopen("User.txt","w");
    User*p = b.list->next;
    while(p != NULL){
        fputs(p->Username,U);
        fputc('\n',U);
        fputs(p->Password,U);
        fputc('\n',U);
        fprintf(U,"%i\n",p->borrowNumber);
        p = p->next;
    }
}

void store_user_book(char *Uname){
    char name[100];
    strcpy(name,Uname);
    strcat(Uname,"B");
    char *o = strcat(Uname,".txt");
    User * p = b.list;
    while(strcmp(p->Username,name)!=0){
        p = p->next;
    }
    FILE *f = fopen(o,"w");
    for(int i = 0;i<p->borrowNumber;i++){
        fprintf(f,"%i\n",p->borrowed[i]->id);
        fputs(p->borrowed[i]->title,f);
        fputc('\n',f);
        fputs(p->borrowed[i]->authors,f);
        fputc('\n',f);
        fprintf(f,"%i\n",p->borrowed[i]->year);
        fprintf(f,"%i\n",p->borrowed[i]->copies);
    }
    fclose(f);
}

void Return(char Username[40]){
    int temp;
    int i;
    int j;
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
                    for(j = i ; j < q->borrowNumber - 1;j++){
                        q->borrowed[j] = q->borrowed[j+1];
                    }
                    q->borrowNumber -= 1;
                    while(p != NULL){
                        if (B.id == p->id){
                            p->copies ++;
                        }
                        p = p->next;
                    }
                    return ;//question here!
                }
            }
            printf("Sorry! you don't have this book!\n");
            return;
        }
        q = q->next;
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
                    if ((p->copies) >= 1){
                        p->copies -= 1;
                        break;
                    }
                    if((p->copies) == 0){
                        printf("This book no copies\n");
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
            printf("----Return Book----\n");
            Return(username);
            getchar();
        }
        else if (temp == '3') {
            printf("----Search the book----\n");
            Search(a.list);
        }
        else if (temp == '4') {
            printf("----Display the book list----\n");
            PrintBook(a);
        }
        else if (temp == '5') {
            printf("----Check My book----\n");
            PrintMy_book(username);
        }
        else if (temp == '6') {
            on_off = 0;
            FILE *L;
            store_user();
            store_user_book(username);
            store_books(L);
            printf("Log out......\n");
        }
        else {
            printf("Unknown number!\nPlease enter again!\n");
        }
    }
}
