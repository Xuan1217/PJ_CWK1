EXE = ./bin/library_management
SRC= main.c library.c librarian.c user.c utility.c login.c

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK= 

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

clean:
	rm -f $(OBJ) $(EXE)

main.o:      main.c library.h
library.o:   library.c library.h librarian.h user.h utility.h login.h book_management.h
librarian.o: librarian.c librarian.h library.h login.h utility.h
book_management.h
user.o:      user.c user.h utility.h librarian.h book_management.h
utility.o:   utility.c utility.h book_management.h
login.o: login.c book_management.h login.h librarian.h user.h 

