OBJ=main.o pacman.o ghost.o event.o draw.o init.o timer.o update.o map.o
CFLAGS=`sdl2-config --cflags` 
LIBS=`sdl2-config --cflags --libs`
.c.o:
	$(CC) -g -c $<
all: $(OBJ)
	$(CC) -o pacman *.o -lm $(CFLAGS) $(LIBS)
clean:
	@rm -f *.o pacman > /dev/null

