#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"book_management.h"
#include"library.h"

int main(int argc, char** argv) {
	printf("*****************************************\n");
	printf("*******  Welcome to the library  ********\n");
	printf("*****************************************\n\n");
	FILE*fp;
    LibraryOpen(fp);
    printf("Library is closed!");
    return 0;
}
