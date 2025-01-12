CC = gcc
CFLAGS = -Wall -g
SOURCES = main.c test_auth.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = autentikointijärjestelmä

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)
