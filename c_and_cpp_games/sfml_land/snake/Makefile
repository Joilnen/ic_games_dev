CC=c++
OBJ=snake.o
CFLAGS=-I /usr/local/include
LIBS=-L /usr/local/lib -l sfml-window -l sfml-system -l sfml-graphics
.c.o:
	$(CC) -c $<
all: snake.o
	$(CC) -o snake *.o $(CFLAGS) $(LIBS)
clean:
	@rm -f *.o snake > /dev/null

