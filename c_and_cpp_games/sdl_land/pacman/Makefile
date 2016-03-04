OBJ=main.o pacman.o gost.o event.o draw.o init.o timer.o update.o
CFLAGS=`sdl2-config --cflags` 
LIBS=`sdl2-config --cflags --libs`
.c.o:
	$(CC) -c $<
all: $(OBJ)
	$(CC) -o pacman *.o -lm $(CFLAGS) $(LIBS)
clean:
	@rm -f *.o pacman > /dev/null

