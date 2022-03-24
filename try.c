#include<stdio.h>
#include "book_management.h"
BookList a;

int store_books(FILE* file) {
	Book* p;
	p = a.list;
	file = fopen("books.txt", "w");
	if (file == NULL) {
		printf("Error!");
		return 0;
	}
	else {
		while (p != NULL) {
			fputs(&p->id, file);
			fputs(p->title, file);
			fputs(p->authors, file);
			fputs(&p->year, file);
			fputs(&p->copies, file);
			p = p->next;
		}
		fclose(file);
	}
}

int load_books(FILE* file) {
	if ((file = fopen("books.txt", "r")) == NULL) {
		printf("Error\nBook file does not exist");
		exit(0);
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
			p -> title = (char *)malloc(100);
			p -> authors = (char *)malloc(100);
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
		return 0;
	}
}

void PrintBook(Book*list) {
	while (p != NULL) {
		printf("id:%d\n", p->id);
		printf("title:%s\n", p->title);
		printf("author:%s\n", p->authors);
		printf("year:%d\n", p->year);
		printf("copies:%d\n", p->copies);
		p = p->next;
	}
}
int main(){
FILE *fp;
load_books(fp);
PrintBook(a.list);
return 0;}
