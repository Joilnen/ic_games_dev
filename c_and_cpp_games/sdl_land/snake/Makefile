OBJ=snake.o
CFLAGS=`sdl2-config --cflags` 
LIBS=`sdl2-config --cflags --libs`
.c.o:
	$(CC) -c $<
all: snake.o
	$(CC) -o snake *.o $(CFLAGS) $(LIBS)
clean:
	@rm -f *.o snake > /dev/null

