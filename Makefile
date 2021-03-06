CC = g++
CFLAGS = -W -Wall -ansi -std=c++0x -g
LIBS = -L./SDL2_ttf/.libs -L./SDL2_image/.libs
LDFLAGS = `sdl2-config --cflags --libs`
INCLUDES = -I./SDL2_ttf -I./SDL2_image
EXEC = main
SRC = main.cpp Monde.cpp fonctionSDL.cpp Joueur.cpp Ennemi.cpp
DEPS = functions_SDL.h 
OBJ = $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf $(EXEC)