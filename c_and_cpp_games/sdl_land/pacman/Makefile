OBJ=main.o pacman.o ghost.o event.o draw.o init.o timer.o update.o map.o poslist.o sound.o
CFLAGS=`sdl2-config --cflags` `pkg-config --cflags SDL2_image SDL2_mixer`
LIBS=`sdl2-config --cflags --libs` `pkg-config --cflags --libs SDL2_image SDL2_mixer`
.c.o:
	$(CC) -g $(CFLAGS) -c $<
all: $(OBJ)
	$(CC) -o pacman *.o -lm $(CFLAGS) $(LIBS) 
clean:
	@rm -f *.o pacman > /dev/null

